
/* Shellのようなもの (現状てきとーー) */
/* そのうちちゃんとリダイレクトとか Ctrl+C とかいろいろつける予定... (--; */


#include <string.h>
#include "shell.h"
#include "system/file/file.h"
#include "system/file/stdfile.h"
#include "system/file/console.h"
#include "system/memory/memory.h"
#include "system/process/process.h"
#include "system/command/command.h"


#define SHELL_MAX_COMMAND		256
#define SHELL_MAX_HISTORY		4


typedef struct c_shell
{
	int		iCurPos;											/* カーソルの文字列上の位置 */
	int		iCurScreenX;										/* カーソルのスクリーンのX位置 */
	int		iScreenWidth;										/* スクリーンの幅 */
	int		iCommandLen;										/* コマンドの文字列長 */
	char	szCommanBuf[SHELL_MAX_COMMAND];						/* コマンドラインバッファ */
	char	szHistory[SHELL_MAX_HISTORY][SHELL_MAX_COMMAND];	/* ヒストリバッファ */
	int		iHistoryNum;
} C_SHELL;


void Shell_Create(C_SHELL *self);
void Shell_Delete(C_SHELL *self);
int  Shell_Execute(C_SHELL *self, int argc, char *argv[]);
int  Shell_InputLine(C_SHELL *self, char *pszBuf, int  iBufSize);
void Shell_PutChar(C_SHELL *self, int c);
void Shell_CurRight(C_SHELL *self);
void Shell_CurLeft(C_SHELL *self);
void Shell_ExecuteCommand(C_SHELL *self, const char *pszCommand);
void Shell_ReplaceLine(C_SHELL *self, const char *pszNewLine);	/* ラインを置き換える */



int Shell_Main(int argc, char *argv[])
{
	C_SHELL *pShell;
	int     iExitCode;

	/* オブジェクト生成 */
	if ( (pShell = Memory_Alloc(sizeof(C_SHELL))) == NULL )
	{
		StdIo_PutString("Memory error\n");
		return 1;
	}
	Shell_Create(pShell);
	
	/* 実行 */
	iExitCode = Shell_Execute(pShell, argc, argv);
		
	/* オブジェクト開放 */
	Shell_Delete(pShell);
	Memory_Free(pShell);
	
	return iExitCode;
}


/* コンストラクタ */
void Shell_Create(C_SHELL *self)
{
	self->iScreenWidth = 80;
	self->iHistoryNum  = 0;
}


/* デストラクタ */
void Shell_Delete(C_SHELL *self)
{
}


int Shell_Execute(C_SHELL *self, int argc, char *argv[])
{
	for ( ; ; )
	{
		/* コマンド入力 */
		Shell_InputLine(self, self->szCommanBuf, SHELL_MAX_COMMAND);

		/* exit なら抜ける */
		if ( strcmp(self->szCommanBuf, "exit") == 0 )
		{
			break;
		}

		/* 空行なら無視 */
		if ( self->szCommanBuf[0] == 0 )
		{
			continue;
		}
		
		/* ヒストリ記憶 */
		memmove(self->szHistory[1], self->szHistory[0], (SHELL_MAX_HISTORY-1)*(SHELL_MAX_COMMAND));
		strcpy(self->szHistory[0], self->szCommanBuf);
		if ( self->iHistoryNum < SHELL_MAX_HISTORY )
		{
			self->iHistoryNum++;
		}

		/* コマンド実行 */
		Shell_ExecuteCommand(self, self->szCommanBuf);
	}
	
	return 0;
}


int Shell_ExecEntry(VPARAM Param)
{
	int iExitCode;
	char *pszCommand;
	
	pszCommand = (char *)Param;
	if ( Command_Execute(pszCommand, &iExitCode) != COMMAND_ERR_NG )
	{
		iExitCode = -1;
	}
	
	Memory_Free(pszCommand);
	
	return iExitCode;
}


void Shell_ExecuteCommand(C_SHELL *self, const char *pszCommand)
{
	int iLen;
	iLen = strlen(pszCommand);
	if ( iLen > 1 && pszCommand[iLen - 1] == '&' )
	{
		char *pszBuf;
		pszBuf = Memory_Alloc(iLen);
		strcpy(pszBuf, pszCommand);
		pszBuf[iLen - 1] = '\0';
		Process_CreateEx(Shell_ExecEntry, (VPARAM)pszBuf, 1024, PROCESS_PRIORITY_NORMAL+1, NULL);
	}
	else
	{
		if ( Command_Execute(pszCommand, NULL) != COMMAND_ERR_OK )
		{
			StdIo_PutString("command is not found.\r\n");
		}
	}
}


/* １行入力 */
int Shell_InputLine(C_SHELL *self, char *pszBuf, int  iBufSize)
{
	int  iHistoryPos = -1;
	int  i;
	int  c;


	/* プロンプトを出す */
	StdIo_PutString("\r% ");
	self->iCurScreenX = 2;

	self->iCommandLen = 0;
	self->iCurPos     = 0;
	
	for ( ; ; )
	{
		c = StdCon_GetCh();
		
		switch ( c )
		{
		case '\n':		/* 改行なら入力完了 */
			pszBuf[self->iCommandLen] = '\0';
			StdCon_PutString("\r\n");
			return self->iCommandLen;
		
		
		case CONSOLE_KEY_BACKSPACE:	/* バックスペースなら */
			if ( self->iCurPos > 0 )
			{
				memmove(&pszBuf[self->iCurPos - 1], &pszBuf[self->iCurPos], self->iCommandLen - self->iCurPos);
				self->iCurPos--;
				self->iCommandLen--;
				Shell_CurLeft(self);
				for ( i = 0; i < self->iCommandLen - self->iCurPos; i++ )
				{
					Shell_PutChar(self, pszBuf[self->iCurPos + i]);
				}
				Shell_PutChar(self, ' ');
				for ( i = 0; i < self->iCommandLen - self->iCurPos + 1; i++ )
				{
					Shell_CurLeft(self);
				}
			}
			break;

		case CONSOLE_KEY_UP:	/* 上 */
			if ( iHistoryPos + 1 < self->iHistoryNum )
			{
				iHistoryPos++;
				Shell_ReplaceLine(self, self->szHistory[iHistoryPos]);
			}
			break;

		case CONSOLE_KEY_DOWN:	/* 下 */
			if ( iHistoryPos > 0 )
			{
				iHistoryPos--;
				Shell_ReplaceLine(self, self->szHistory[iHistoryPos]);
			}
			break;
		
		case CONSOLE_KEY_RIGHT:	/* 右 */
			if ( self->iCurPos < self->iCommandLen )
			{
				Shell_CurRight(self);
				self->iCurPos++;
			}
			break;
		
		case CONSOLE_KEY_LEFT:	/* 左 */
			if ( self->iCurPos > 0 )
			{
				Shell_CurLeft(self);
				self->iCurPos--;
			}
			break;

		case '\t':				/* TAB */
			break;

		default:		/* カーソル位置に文字設定 */
			if ( c >= 0x20 && c <= 255 )
			{
				if ( self->iCurPos < iBufSize - 1 )
				{
					memmove(&pszBuf[self->iCurPos + 1], &pszBuf[self->iCurPos], self->iCommandLen - self->iCurPos);
					pszBuf[self->iCurPos++] = (char)c;
					self->iCommandLen++;
					for ( i = 0; i < self->iCommandLen - self->iCurPos + 1; i++ )
					{
						Shell_PutChar(self, pszBuf[self->iCurPos + i - 1]);
					}
					for ( i = 0; i < self->iCommandLen - self->iCurPos; i++ )
					{
						Shell_CurLeft(self);
					}
				}
				else
				{
					StdCon_PutChar('\a');
				}
			}
			break;
		}
	}
}



/* スクリーンに１文字出力 */
void Shell_PutChar(C_SHELL *self, int c)
{
	StdCon_PutChar(c);	
	self->iCurScreenX++;
	if ( self->iCurScreenX >= self->iScreenWidth )
	{
		self->iCurScreenX = 0;
		StdCon_PutString("\n");
	}	
}

/* カーソル右移動 */
void Shell_CurRight(C_SHELL *self)
{
	self->iCurScreenX++;
	if ( self->iCurScreenX >= self->iScreenWidth )
	{
		self->iCurScreenX = 0;
		StdCon_PutString("\n");
	}
	else
	{
		StdCon_PutString("\x1b[1C");		/* カーソル右 */
	}
}

/* カーソル左移動 */
void Shell_CurLeft(C_SHELL *self)
{
	if ( self->iCurScreenX == 0 )
	{
		self->iCurScreenX = self->iScreenWidth - 1;
		StdCon_PutString("\x1b[1A\x1b[80C");
	}
	else
	{
		self->iCurScreenX--;
		StdCon_PutString("\x1b[1D");		/* カーソル左 */
	}
}

/* ラインを置き換える */
void Shell_ReplaceLine(C_SHELL *self, const char *pszNewLine)
{
	int iOldLen;
	int i;
	
	/* 前回の長さを保存 */
	iOldLen = self->iCommandLen;
	
	/* 行先頭まで移動 */
	while ( self->iCurPos > 0 )
	{
		Shell_CurLeft(self);
		self->iCurPos--;
	}
	
	/* 新しい文字列を出力 */
	for ( i = 0; pszNewLine[i] != '\0'; i++ )
	{
		Shell_PutChar(self, pszNewLine[i]);
		self->szCommanBuf[i] = pszNewLine[i];
		self->iCurPos++;
	}
	self->iCommandLen = i;
	
	/* 末尾削除 */
	for ( i = self->iCommandLen; i < iOldLen; i++ )
	{
		Shell_PutChar(self, ' ');
	}
	for ( i = self->iCommandLen; i < iOldLen; i++ )
	{
		Shell_CurLeft(self);
	}	
}


/* end of file */
