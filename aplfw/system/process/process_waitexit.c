/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  process.c
 * @brief %jp{プロセスオブジェクト}
 *
 * Copyright (C) 2006-2007 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include <string.h>
#include "process_local.h"



/** プロセスの終了を待つ */
PROCESS_ERR Process_WaitExit(HANDLE hProcess)
{
	C_PROCESS *self;
	
	if ( hProcess == HANDLE_NULL || hProcess == Process_GetCurrentHandle() )
	{
		return PROCESS_ERR_NG;
	}

	self = (C_PROCESS *)hProcess;
	
	/* 終了を待つ */
	SysEvt_Wait(self->hEvt);

	return PROCESS_ERR_OK;
}



/* end of file */
