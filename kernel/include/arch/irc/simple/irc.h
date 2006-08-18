/**
 *  Hyper Operating System V4 Advance
 *
 * @file  irc.h
 * @brief %jp{割り込みコントローラ固有属性定義}%jp{Interrupt controler attribute}
 *  %jp{割込みハンドラと割込みサービスルーチンが単純対応する場合}
 *
 * @version $Id: irc.h,v 1.1 2006-08-18 06:47:47 ryuz Exp $
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__arch__irc_none_h__
#define _KERNEL__arch__irc_none_h__


#define _KERNEL_INI_IRC()			do {} while (0)				/**< %jp{IRCの初期化ハンドラ} */
#define _KERNEL_EXE_IRC				_kernel_exe_isr				/**< %jp{IRCの処理ルーチン} */


#endif	/* _KERNEL__arch__irc_none_h__ */


/* end of file */