
#include <stdlib.h>
#include <string.h>
#include "hosaplfw.h"
#include "memdump.h"


int MemDump_Main(int argc, char *argv[])
{
	void *pAddr;
	int  iCount = 16;
	int  iWidth = 'b';
	int  i;

	if ( argc < 2 )
	{
		return 1;
	}
	
	/* コマンドライン解析 */
	pAddr = (void *)strtoul(argv[1], 0, 0);
	if ( argc >= 3 )
	{
		iCount = (int)strtol(argv[2], 0, 0);
	}
	if ( argc >= 4 )
	{
		iWidth = argv[3][0];
	}

	switch ( iWidth )
	{
	case 'b':
		{
			unsigned char *pubAddr;
			pubAddr = (unsigned char *)pAddr;
			for ( i = 0; i < iCount; i++ )
			{
				if ( i % 16 == 0 )
				{
					StdIo_PrintFormat("%08lx: ", (unsigned long)pubAddr);
				}
				StdIo_PrintFormat("%02x ", *pubAddr);
				pubAddr++;
				if ( i % 16 == 15 )
				{
					StdIo_PrintFormat("\n");
				}
			}
		}
		break;

	case 'h':
		{
			unsigned short *puhAddr;
			puhAddr = (unsigned short *)pAddr;
			for ( i = 0; i < iCount; i++ )
			{
				if ( i % 8 == 0 )
				{
					StdIo_PrintFormat("%08lx: ", (unsigned long)puhAddr);
				}
				StdIo_PrintFormat("%04x ", *puhAddr);
				puhAddr++;
				if ( i % 8 == 7 )
				{
					StdIo_PrintFormat("\n");
				}
			}
		}
		break;

	case 'w':
		{
			unsigned long *puwAddr;
			puwAddr = (unsigned long *)pAddr;
			for ( i = 0; i < iCount; i++ )
			{
				if ( i % 4 == 0 )
				{
					StdIo_PrintFormat("%08lx: ", (unsigned long)puwAddr);
				}
				StdIo_PrintFormat("%08x ", *puwAddr);
				puwAddr++;
				if ( i % 4 == 3 )
				{
					StdIo_PrintFormat("\n");
				}
			}
		}
		break;
	}

	StdIo_PrintFormat("\n");


	return 0;
}


