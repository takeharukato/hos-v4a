/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  exe_inh.c
 * @brief %jp{割り込みハンドラの処理}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#include "core/core.h"
#include "object/inhobj.h"


/* %jp{割り込みハンドラの処理} */
void _kernel_exe_inh(INHNO inhno)
{
	_KERNEL_ENA_INT();			/* %jp{多重割込み許可} */

	/* %jp{割り込みハンドラの処理} */
#if _KERNEL_SPT_INH
	{
		const _KERNEL_T_INHINF *pk_inhinf;
	
		pk_inhinf = _KERNEL_INT_GET_INHINF(inhno);
	
		if ( pk_inhinf->inthdr != NULL )
		{
			pk_inhinf->inthdr(inhno);	/* %jp{割込みハンドラの処理} */
		}
	}
#endif

	/* %jp{割り込みコントローラの処理} */
#if _KERNEL_SPT_ISR
	_KERNEL_EXE_IRC(inhno);
#endif

	_KERNEL_DIS_INT();			/* %jp{割込み禁止} */
}


/* end of file */
