/**
 *  Hyper Operating System V4 Advance
 *
 * @file  procatr.h
 * @brief %jp{プロセッサアーキテクチャ固有機能}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__arch__proc__riscv__procatr_h__
#define _KERNEL__arch__proc__riscv__procatr_h__


/* %jp{プロセッサアーキテクチャ定義のあるインクルードパス} */
#define _KERNEL_PROCATR_INC_PATH			"riscv"


/* %jp{プロセッサアーキテクチャに依存した属性} */
#define _KERNEL_PROCATR_CTX_STK				FALSE		/**< %jp{コンテキスト生成にスタック領域の指定が必要か？} */
#define _KERNEL_PROCATR_CTX_STKSZ			FALSE		/**< %jp{コンテキスト生成にスタックサイズの指定が必要か？} */
#define _KERNEL_PROCATR_CTX_ISP				TRUE		/**< %jp{コンテキスト生成に初期スタックポインタ値が必要か？} */
#define _KERNEL_PROCATR_CTX_DEL				FALSE		/**< %jp{別コンテキストからのコンテキスト削除が必要か？} */
#define _KERNEL_PROCATR_CTX_RST				TRUE		/**< %jp{自コンテキストのリスタートが可能か？} */

#define _KERNEL_PROCATR_SPT_SMP				FALSE		/**< %jp{SMPに対応しているか？} */
#define _KERNEL_PROCATR_SPT_MULTINT			TRUE		/**< %jp{多重割込みに対応しているか？} */

#define _KERNEL_PROCATR_TMIN_INHNO			0			/**< %jp{割込みハンドラ番号の最小値} */
#define _KERNEL_PROCATR_TMAX_INHNO			3			/**< %jp{割込みハンドラ番号の最大値(CLIC:3)} */

#define _KERNEL_PROCATR_TMIN_EXCNO			0			/**< %jp{CPU例外ハンドラ番号の最小値} */
#define _KERNEL_PROCATR_TMAX_EXCNO			63			/**< %jp{CPU例外ハンドラ番号の最大値} */

#define _KERNEL_PROCATR_SYSSTK_NUM			1			/**< %jp{システムスタックは何本必要か？} */

#define _KERNEL_PROCATR_SIGNED_INT			0			/**< %jp{符号付整数と符号無し整数のどちらが得意か？(符号付き:1, 符号無し:-1, 同じ:0)} */


#define _KERNEL_PROCATR_ALLOW_UNALIGN		        FALSE		/**< %jp{アンアラインアクセスは可能か？} */


/* %jp{RISC-V固有の定数} */
/* TODO: PLIC/CLICの割込み数を定義 */
#define _KERNEL_PROCATR_SYS_CTX				FALSE		/**< %jp{コンテキスト状態管理をプロセッサで実施するか？} */
#define _KERNEL_PROCATR_SYS_LOC				FALSE		/**< %jp{CPUロック状態管理をプロセッサで実施するか？} */
#define _KERNEL_PROCATR_SYS_DSP				FALSE		/**< %jp{ディスパッチ禁止状態管理をプロセッサで実施するか？} */
#define _KERNEL_PROCATR_SYS_SYS				FALSE		/**< %jp{システム状態管理をプロセッサで実施するか？} */
#define _KERNEL_PROCATR_SYS_DLY				FALSE		/**< %jp{遅延ディスパッチ保留状態管理をプロセッサで実施するか？} */

/** %jp{RISC-V C API Specificationに準拠したコンパイラの場合, __riscv_xlenによってレジスタ長を判定可能} */
#ifdef __riscv
#define _KERNEL_RISCV_XLEN                         __riscv_xlen    /**< %jp{bit長} */
/**< %jp{レジスタ長(単位:バイト)} */
#define _KERNEL_RISCV_REGSIZE                      (__riscv_xlen/8)


#if __riscv_xlen == 32
#define _KERNEL_PROCATR_TMIN_STKSZ			(4*32)		/**< %jp{最低限必要なスタックサイズ(byte単位).} */
#define _KERNEL_PROCATR_TBIT_INT			32			/**< %jp{プロセッサに最適な整数型のビット数} */
#define _KERNEL_PROCATR_TBIT_PTR			32			/**< %jp{ポインタのビット数} */
#define _KERNEL_PROCATR_MEM_ALIGN			4			/**< %jp{適切なメモリのアライメント(byte単位)} */
#define _KERNEL_PROCATR_STK_ALIGN			16			/**< %jp{適切なスタックのアライメント(byte単位)} */

#define _KERNEL_RISCV_PROC_REGTYPE                 UW    /**< %jp{32bitレジスタ} */
#define _KERNEL_RISCV_PROC_LD                      lw    /**< %jp{32bitレジスタ} */
#define _KERNEL_RISCV_PROC_ST                      sw    /**< %jp{32bitレジスタ} */


/**< %jp{割込みコンテキスト} */
#define _KERNEL_RISCV_PROC_ICTX_SIZE               80

#define _KERNEL_RISCV_PROC_ICTX_RA                  0
#define _KERNEL_RISCV_PROC_ICTX_T0                  4
#define _KERNEL_RISCV_PROC_ICTX_T1                  8
#define _KERNEL_RISCV_PROC_ICTX_T2                 12
#define _KERNEL_RISCV_PROC_ICTX_T3                 16
#define _KERNEL_RISCV_PROC_ICTX_T4                 20
#define _KERNEL_RISCV_PROC_ICTX_T5                 24
#define _KERNEL_RISCV_PROC_ICTX_T6                 28

#define _KERNEL_RISCV_PROC_ICTX_A0                 32
#define _KERNEL_RISCV_PROC_ICTX_A1                 36
#define _KERNEL_RISCV_PROC_ICTX_A2                 40
#define _KERNEL_RISCV_PROC_ICTX_A3                 44
#define _KERNEL_RISCV_PROC_ICTX_A4                 48
#define _KERNEL_RISCV_PROC_ICTX_A5                 52
#define _KERNEL_RISCV_PROC_ICTX_A6                 56
#define _KERNEL_RISCV_PROC_ICTX_A7                 60

#define _KERNEL_RISCV_PROC_ICTX_TP                 64
#define _KERNEL_RISCV_PROC_ICTX_GP                 68
#define _KERNEL_RISCV_PROC_ICTX_EPC                72
#define _KERNEL_RISCV_PROC_ICTX_STATUS             76


/**< %jp{タスクスイッチコンテキスト} */
#define _KERNEL_RISCV_PROC_TSKCTX_SIZE             52

#define _KERNEL_RISCV_PROC_TSKCTX_RA                0
#define _KERNEL_RISCV_PROC_TSKCTX_S0                4
#define _KERNEL_RISCV_PROC_TSKCTX_S1                8
#define _KERNEL_RISCV_PROC_TSKCTX_S2               12
#define _KERNEL_RISCV_PROC_TSKCTX_S3               16
#define _KERNEL_RISCV_PROC_TSKCTX_S4               20
#define _KERNEL_RISCV_PROC_TSKCTX_S5               24
#define _KERNEL_RISCV_PROC_TSKCTX_S6               28
#define _KERNEL_RISCV_PROC_TSKCTX_S7               32
#define _KERNEL_RISCV_PROC_TSKCTX_S8               36
#define _KERNEL_RISCV_PROC_TSKCTX_S9               40
#define _KERNEL_RISCV_PROC_TSKCTX_S10              44
#define _KERNEL_RISCV_PROC_TSKCTX_S11              48


#elif __riscv_xlen == 64
#define _KERNEL_PROCATR_TMIN_STKSZ			(8*32)		/**< %jp{最低限必要なスタックサイズ(byte単位).} */
#define _KERNEL_PROCATR_TBIT_INT			64			/**< %jp{プロセッサに最適な整数型のビット数} */
#define _KERNEL_PROCATR_TBIT_PTR			64			/**< %jp{ポインタのビット数} */
#define _KERNEL_PROCATR_MEM_ALIGN			8			/**< %jp{適切なメモリのアライメント(byte単位)} */
#define _KERNEL_PROCATR_STK_ALIGN			16			/**< %jp{適切なスタックのアライメント(byte単位)} */

#define _KERNEL_RISCV_PROC_REGTYPE                 UD    /**< %jp{64bitレジスタ} */
#define _KERNEL_RISCV_PROC_LD                      ld    /**< %jp{64bitレジスタ} */
#define _KERNEL_RISCV_PROC_ST                      sd    /**< %jp{64bitレジスタ} */


/**< %jp{割込みコンテキスト} */
#define _KERNEL_RISCV_PROC_ICTX_SIZE              160

#define _KERNEL_RISCV_PROC_ICTX_RA                  0
#define _KERNEL_RISCV_PROC_ICTX_T0                  8
#define _KERNEL_RISCV_PROC_ICTX_T1                 16
#define _KERNEL_RISCV_PROC_ICTX_T2                 24
#define _KERNEL_RISCV_PROC_ICTX_T3                 32
#define _KERNEL_RISCV_PROC_ICTX_T4                 40
#define _KERNEL_RISCV_PROC_ICTX_T5                 48
#define _KERNEL_RISCV_PROC_ICTX_T6                 56

#define _KERNEL_RISCV_PROC_ICTX_A0                 64
#define _KERNEL_RISCV_PROC_ICTX_A1                 72
#define _KERNEL_RISCV_PROC_ICTX_A2                 80
#define _KERNEL_RISCV_PROC_ICTX_A3                 88
#define _KERNEL_RISCV_PROC_ICTX_A4                 96
#define _KERNEL_RISCV_PROC_ICTX_A5                104
#define _KERNEL_RISCV_PROC_ICTX_A6                112
#define _KERNEL_RISCV_PROC_ICTX_A7                120

#define _KERNEL_RISCV_PROC_ICTX_TP                128
#define _KERNEL_RISCV_PROC_ICTX_GP                136
#define _KERNEL_RISCV_PROC_ICTX_EPC               144
#define _KERNEL_RISCV_PROC_ICTX_STATUS            152


/**< %jp{タスクスイッチコンテキスト} */
#define _KERNEL_RISCV_PROC_TSKCTX_SIZE            104
#define _KERNEL_RISCV_PROC_TSKCTX_RA                0
#define _KERNEL_RISCV_PROC_TSKCTX_S0                8
#define _KERNEL_RISCV_PROC_TSKCTX_S1               16
#define _KERNEL_RISCV_PROC_TSKCTX_S2               24
#define _KERNEL_RISCV_PROC_TSKCTX_S3               32
#define _KERNEL_RISCV_PROC_TSKCTX_S4               40
#define _KERNEL_RISCV_PROC_TSKCTX_S5               48
#define _KERNEL_RISCV_PROC_TSKCTX_S6               56
#define _KERNEL_RISCV_PROC_TSKCTX_S7               64
#define _KERNEL_RISCV_PROC_TSKCTX_S8               72
#define _KERNEL_RISCV_PROC_TSKCTX_S9               80
#define _KERNEL_RISCV_PROC_TSKCTX_S10              88
#define _KERNEL_RISCV_PROC_TSKCTX_S11              96

#else
#error "target is not supported"
#endif


#ifndef _ASM_FILE

#ifdef __cplusplus
extern "C" {
#endif

/** %jp{割込みコンテキスト:160バイト} */
typedef struct _kernel_riscv64_ictx{
	_KERNEL_RISCV_PROC_REGTYPE      ra;  /* %jp{オフセット: 0 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE      t0;  /* %jp{オフセット: 8 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE      t1;  /* %jp{オフセット: 16 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE      t2;  /* %jp{オフセット: 24 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE      t3;  /* %jp{オフセット: 32 バイト} */

	_KERNEL_RISCV_PROC_REGTYPE      t4;  /* %jp{オフセット: 40 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE      t5;  /* %jp{オフセット: 48 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE      t6;  /* %jp{オフセット: 56 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE      a0;  /* %jp{オフセット: 64 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE      a1;  /* %jp{オフセット: 72 バイト} */

	_KERNEL_RISCV_PROC_REGTYPE      a2;  /* %jp{オフセット: 80 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE      a3;  /* %jp{オフセット: 88 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE      a4;  /* %jp{オフセット: 96 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE      a5;  /* %jp{オフセット: 104 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE      a6;  /* %jp{オフセット: 112 バイト} */

	_KERNEL_RISCV_PROC_REGTYPE      a7;  /* %jp{オフセット: 120 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE      tp;  /* %jp{オフセット: 128 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE      gp;  /* %jp{オフセット: 136 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE     epc;  /* %jp{オフセット: 144 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE  status;  /* %jp{オフセット: 152 バイト} */
}kernel_riscv64_ictx;


/** %jp{タスクスイッチコンテキスト:104バイト} */
typedef struct _kernel_riscv64_tskswctx{
	_KERNEL_RISCV_PROC_REGTYPE      ra;  /* %jp{オフセット: 0 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE      s0;  /* %jp{オフセット: 8 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE      s1;  /* %jp{オフセット: 16 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE      s2;  /* %jp{オフセット: 24 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE      s3;  /* %jp{オフセット: 32 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE      s4;  /* %jp{オフセット: 40 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE      s5;  /* %jp{オフセット: 48 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE      s6;  /* %jp{オフセット: 56 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE      s7;  /* %jp{オフセット: 64 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE      s8;  /* %jp{オフセット: 72 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE      s9;  /* %jp{オフセット: 80 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE     s10;  /* %jp{オフセット: 88 バイト} */
	_KERNEL_RISCV_PROC_REGTYPE     s11;  /* %jp{オフセット: 96 バイト} */
}kernel_riscv64_tskswctx;

#ifdef __cplusplus
}
#endif  /*  __cplusplus  */
#endif  /*  !_ASM_FILE  */
#endif  /*  __riscv  */
#endif	/* _KERNEL__arch__proc__riscv__procatr_h__ */


/* end of file */
