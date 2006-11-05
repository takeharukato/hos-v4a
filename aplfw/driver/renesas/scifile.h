/** 
 *  Hyper Operating System  Application Framework
 *
 * @file  scifile.h
 * @brief %jp{SCI用デバイスドライバ用ファイルI/Fクラス}
 *
 * @version $Id: scifile.h,v 1.1 2006-11-05 16:11:07 ryuz Exp $
 *
 * Copyright (C) 2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef __HOS__renesas_scifile_h__
#define __HOS__renesas_scifile_h__


#include "scidrv.h"
#include "system/file.h"


/* SCI用ドライバ制御部 */
typedef struct c_scifile
{
	C_FILEOBJ FileObj;		/* ファイルオブジェクトを継承 */

	C_SCIDRV  *pSciDrv;		/* SciDrvクラスの参照 */
} C_SCIFILE;



#ifdef __cplusplus
extern "C" {
#endif

/* SCI用デバイスドライバ */
FILEERR SciFile_Create(HANDLE hFile, void *pParam);			/**< コンストラクタ */

#ifdef __cplusplus
}
#endif


#endif	/* __HOS__renesas_scifile_h__ */


/* end of file */
