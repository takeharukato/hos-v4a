/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  ctxctl.h
 * @brief %jp{コンテキスト制御}%en{context control}
 *
 * Copyright (C) 1998-2006 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */


#ifndef _KERNEL__arch__proc__h8__h8300h__proc_h__
#define _KERNEL__arch__proc__h8__h8300h__proc_h__


#define _KERNEL_IMSK_I		0x80		/**< %jp{割り込みマスクビット} */
#define _KERNEL_IMSK_UI		0x40		/**< %jp{ユーザービット／割り込みマスクビット} */

#define _KERNEL_IMSK_LV0	0xc0		/**< %jp{割り込みマスクレベル0(すべてマスク)} */
#define _KERNEL_IMSK_LV1	0x80		/**< %jp{割り込みマスクレベル1(高優先割込みのみ許可)} */
#define _KERNEL_IMSK_LV2	0x00		/**< %jp{割り込みマスクレベル2(すべて許可)} */


/** %jp{コンテキスト情報保存ブロック} */
typedef struct _kernel_t_ctxcb
{
	VP_INT  sp;
} _KERNEL_T_CTXCB;



/* %jp{広域変数定義} */
extern volatile UB _kernel_h83_imsk;				/**< %jp{H8/300用割り込みマスク} */
extern volatile UB _kernel_int_cnt;				/**< %jp{割り込みネストカウンタ} */


#ifdef __cplusplus
extern "C" {
#endif

void    _kernel_ini_prc(void);																		/**< %jp{プロセッサの初期化} */

void    _kernel_ena_int(void);																		/**< %jp{割り込み許可} */
void    _kernel_dis_int(void);																		/**< %jp{割り込み禁止} */
void    _kernel_wai_int(void);																		/**< %jp{割り込み待ち(アイドル時の処理)} */

void    _kernel_cre_ctx(_KERNEL_T_CTXCB *pk_ctxcb, VP isp, FP entry, VP_INT par1, VP_INT par2);		/**< %jp{実行コンテキストの作成} */
void    _kernel_del_ctx(_KERNEL_T_CTXCB *pk_ctxcb);													/**< %jp{実行コンテキストの削除} */
void    _kernel_rst_ctx(VP_INT par1, VP_INT par2, FP entry, VP isp);								/**< %jp{実行コンテキストのリスタート} */
void    _kernel_sta_ctx(_KERNEL_T_CTXCB *pk_ctxcb);													/**< %jp{実行コンテキストの開始} */
void    _kernel_swi_ctx(_KERNEL_T_CTXCB *pk_ctxinf_nxt, _KERNEL_T_CTXCB *pk_ctxcb_now);				/**< %jp{実行コンテキストの切替} */

#ifdef __cplusplus
}
#endif


#define _KERNEL_INI_PRC()	do {} while (0)

#define _KERNEL_ENA_INT()	_kernel_ena_int()														/**< %jp{割り込み許可} */
#define _KERNEL_DIS_INT()	_kernel_dis_int()														/**< %jp{割り込み禁止} */
#define _KERNEL_WAI_INT()	_kernel_wai_int()														/**< %jp{割り込み待ち(アイドル時の処理)} */

#define _KERNEL_CRE_CTX(pk_ctxcb, stksz, stk, isp, entry, exinf1, exinf2)		\
									_kernel_cre_ctx((pk_ctxcb), (isp), (entry), (exinf1), (exinf2))
#define _KERNEL_DEL_CTX(pk_ctxcb)	_kernel_del_ctx(pk_ctxcb)
#define _KERNEL_RST_CTX(pk_ctxcb, stksz, stk, isp, entry, exinf1, exinf2)		\
									_kernel_rst_ctx((exinf1), (exinf2), (entry), (isp))
#define _KERNEL_STA_CTX(pk_ctxcb)	_kernel_sta_ctx(pk_ctxcb)
#define _KERNEL_SWI_CTX(pk_ctxcb_now, pk_ctxinf_nxt)							\
									_kernel_swi_ctx((pk_ctxinf_nxt), (pk_ctxcb_now))


#endif	/* _KERNEL__arch__proc__h8__h8300h__proc_h__ */


/* end of file */
