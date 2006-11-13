/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  ena_int.c
 * @brief %jp{割り込み禁止}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

#include "kernel.h"


/* %jp{割り込みの許可} */
ER ena_int(INTNO intno)
{
	return E_NOSPT;
}


/* end of file */