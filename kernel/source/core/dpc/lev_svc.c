/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  dpc.h
 * @brief %jp{遅延プロシージャーコールヘッダファイル}%en{Deferred Procedure Call header file}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include "core/core.h"
#include "core/dpc.h"

#if _KERNEL_SPT_DPC

/* サービスコール退出時の処理 */
void _kernel_dpc_lev_svc(void)
{
	FP   fncSvc;
	UINT svcnst;
	
	/* サービスコールのネスト数取得 */
	svcnst = _KERNEL_SYS_REF_SVC();

	/* 遅延プロシージャ処理中の再呼び出しは無視 */
	if ( svcnst > 1 || _KERNEL_SYS_SNS_DPN() )
	{
		_KERNEL_SYS_SET_SVC(svcnst - 1);
		return;
	}
	
	/* 遅延プロシージャ呼び出し */
	while ( _KERNEL_SYS_RDT_DPC() > 0 )
	{
		fncSvc = (FP)_KERNEL_SYS_RCV_DPC();
		fncSvc();
	}

	/* タスクディスパッチの実施 */

	_KERNEL_DSP_TSK();

	/* サービスコールを抜ける */
	_KERNEL_SYS_SET_SVC(0);
}

#endif	/* _KERNEL_SPT_DPC	*/


/* end of file */
