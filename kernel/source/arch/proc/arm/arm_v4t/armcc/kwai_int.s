; --------------------------------------------------------------------------- 
;  Hyper Operating System V4 Advance
;   %en{コンテキスト制御(ARM v4t アーキテクチャ)}%jp{ARM v4t}
;
;  Copyright (C) 1998-2006 by Project HOS
;  http://sourceforge.jp/projects/hos/
; --------------------------------------------------------------------------- 


				PRESERVE8
				AREA	code, CODE, READONLY

				ALIGN
				CODE32

; -----------------------------------------------
;  割り込み待ち(CPUのアイドル処理)
;  void 	_kernel_wai_int(void);
; -----------------------------------------------
				EXPORT	_kernel_wai_int
_kernel_wai_int
				b		_kernel_wai_int

				
				END


; end of file
