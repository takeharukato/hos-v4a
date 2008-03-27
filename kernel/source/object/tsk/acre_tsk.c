/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  act_tsk.c
 * @brief %en{Activate Task}%jp{タスクの起動}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"



/** %en{Create Task}%jp{タスクの起動}
 * @param  tskid   pk_ctsk	%jp{タスク生成情報}%en{}
 * @return Error code or task ID
 */
ER_ID acre_tsk(const T_CTSK *pk_ctsk)
{
	ID    tskid;
	ER_ID erid;

	_KERNEL_ENTER_SVC();		/* %jp{サービスコールに入る}%en{enter service-call} */
	
	/* %jp{空きID探索} */
#if _KERNEL_ACRE_TSK_ASCENDING_ORDER
	/* %jp{空きID昇順探索} */
	for ( tskid = _KERNEL_TSK_TMIN_ID; tskid <= _KERNEL_TSK_TMAX_ID; tskid++ )
	{
		if ( !_KERNEL_TSK_CHECK_EXS(tskid) )
		{
			break;
		}
	}
	if ( tskid > _KERNEL_TSK_TMAX_ID )
	{
		_KERNEL_LEAVE_SVC();		/* %jp{サービスコールから出る}%en{leave service-call} */
		return E_NOID;				/* %jp{ID番号不足} */
	}
#else
	/* %jp{空きID降順探索} */
	for ( tskid = _KERNEL_TSK_TMAX_ID; tskid >= _KERNEL_TSK_TMIN_ID; tskid-- )
	{
		if ( !_KERNEL_TSK_CHECK_EXS(tskid) )
		{
			break;
		}
	}
	if ( tskid < _KERNEL_TSK_TMIN_ID )
	{
		_KERNEL_LEAVE_SVC();		/* %jp{サービスコールから出る}%en{leave service-call} */
		return E_NOID;				/* %jp{ID番号不足} */
	}
#endif
	
	/* %jp{タスク生成} */
	erid = (ER_ID)_kernel_cre_tsk(tskid, pk_ctsk);
	if ( erid == E_OK )
	{
		erid = (ER_ID)tskid;
	}

	_KERNEL_LEAVE_SVC();		/* %jp{サービスコールから出る}%en{leave service-call} */
	
	return erid;
}



/* end of file */
