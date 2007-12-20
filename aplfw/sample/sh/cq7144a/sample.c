/**
 *  Sample program for Hyper Operating System V4 Advance
 *
 * @file  sample.c
 * @brief %jp{サンプルプログラム}%en{Sample program}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kernel.h"
#include "kernel_id.h"
#include "hosaplfw.h"
#include "system/system/system.h"
#include "system/sysapi/sysapi.h"
#include "system/file/console.h"
#include "system/process/process.h"
#include "system/command/command.h"
#include "system/shell/shell.h"
#include "driver/serial/renesas/scidrv.h"
#include "driver/console/vt100/vt100drv.h"
#include "application/example/hello/hello.h"
#include "application/filecmd/filelist/filelist.h"
#include "application/utility/memdump/memdump.h"
#include "application/utility/memwrite/memwrite.h"
#include "application/utility/memtest/memtest.h"
#include "application/utility/keytest/keytest.h"
#include "regs_sh7144.h"



void Sample_Task(VP_INT exinf)
{
	HANDLE	hTty;
	HANDLE	hCon;
	HANDLE	hDriver;
	
	/*************************/
	/*    固有初期設定       */
	/*************************/
	
	*REG_STANDBY_MSTCR1 &= ~0x0002;	/* %jp{SCI1のスタンバイモードを解除} */
	*REG_PFC_PACRL2 |= 0x0100;		/* %jp{端子設定} */
	
	*REG_INTC_IPRF = ((*REG_INTC_IPRF & 0xfff0) | 0x0001);
	
	/*************************/
	/*       初期化          *
	/*************************/
	
	/* システム初期化 */
	System_Initialize((void *)0x00440000, 0x40000);
	
	
	/*************************/
	/*   デバイスドライバ    */
	/*************************/
	
	/* SCIデバドラ生成 */
	hDriver = SciDrv_Create((void *)REG_SCI0_SMR, 128, 24000000L, 64);	/* SCI0生成 */
	File_AddDevice("com0", hDriver);									/* /dev/com0 に登録 */

	hDriver = SciDrv_Create((void *)REG_SCI1_SMR, 132, 24000000L, 64);	/* SCI1生成 */
	File_AddDevice("com1", hDriver);									/* /dev/com1 に登録 */

	hDriver = SciDrv_Create((void *)REG_SCI2_SMR, 168, 24000000L, 64);	/* SCI2生成 */
	File_AddDevice("com2", hDriver);									/* /dev/com2 に登録 */

	hDriver = SciDrv_Create((void *)REG_SCI3_SMR, 172, 24000000L, 64);	/* SCI3生成 */
	File_AddDevice("com3", hDriver);									/* /dev/com3 に登録 */
	
	/* シリアルを開く */
	hTty = File_Open("/dev/com1", FILE_OPEN_READ | FILE_OPEN_WRITE);
	
	/* シリアル上にコンソールを生成( /dev/con1 に登録) */
	hDriver = Vt100Drv_Create(hTty);
	File_AddDevice("con1", hDriver);
	
	/* コンソールを開く */
	hCon = File_Open("/dev/con1", FILE_OPEN_READ | FILE_OPEN_WRITE);
	
	
	/*************************/
	/*     コマンド登録      */
	/*************************/
	Command_AddCommand("hsh",      Shell_Main);
	Command_AddCommand("hello",    Hello_Main);
	Command_AddCommand("ls",       FileList_Main);
	Command_AddCommand("memdump",  MemDump_Main);
	Command_AddCommand("memwrite", MemWrite_Main);
	Command_AddCommand("memtest",  MemTest_Main);
	Command_AddCommand("keytest",  KeyTest_Main);
	
	
	/*************************/
	/*  システムプロセス起動 */
	/*************************/
	System_Boot(hTty, hCon, "hsh", 4096);
}



/* end of file */
