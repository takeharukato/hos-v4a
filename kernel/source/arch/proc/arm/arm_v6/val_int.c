/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  val_int.c
 * @brief %jp{割込み用変数定義}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */

#include "core/core.h"


UB volatile _kernel_int_cnt;		/* %jp{割り込みネストカウンタ} */


/* end of file */
