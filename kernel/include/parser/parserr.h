/** 
 *  Hyper Operating System V4 Advance
 *
 * @file  parserr.h
 * @brief %jp{エラー処理コンフィギュレーションの解析}%en{error configulation parser}
 *
 * Copyright (C) 1998-2008 by Project HOS
 * http://sourceforge.jp/projects/hos/
 */



#ifndef _KERNEL__parser__parserr_h__
#define _KERNEL__parser__parserr_h__



#ifdef _KERNEL_ERRLEVEL

/* %jp{コンパイルオプションで上書きする}%en{overwrite on compile option} */
#define _KERNEL_SPT_E_ID(x)				((_KERNEL_ERRLEVEL) >= 3)
#define _KERNEL_SPT_E_SYS(x)			((_KERNEL_ERRLEVEL) >= 1)
#define _KERNEL_SPT_E_NOSPT(x)			((_KERNEL_ERRLEVEL) >= 4)
#define _KERNEL_SPT_E_RSFN(x)			((_KERNEL_ERRLEVEL) >= 4)
#define _KERNEL_SPT_E_RSATR(x)			((_KERNEL_ERRLEVEL) >= 3)
#define _KERNEL_SPT_E_PAR(x)			((_KERNEL_ERRLEVEL) >= 3)
#define _KERNEL_SPT_E_ID(x)				((_KERNEL_ERRLEVEL) >= 3)
#define _KERNEL_SPT_E_CTX(x)			((_KERNEL_ERRLEVEL) >= 4)
#define _KERNEL_SPT_E_MACV(x)			((_KERNEL_ERRLEVEL) >= 4)
#define _KERNEL_SPT_E_OACV(x)			((_KERNEL_ERRLEVEL) >= 4)
#define _KERNEL_SPT_E_ILUSE(x)			((_KERNEL_ERRLEVEL) >= 4)
#define _KERNEL_SPT_E_NOMEM(x)			((_KERNEL_ERRLEVEL) >= 1)
#define _KERNEL_SPT_E_NOID(x)			((_KERNEL_ERRLEVEL) >= 3)
#define _KERNEL_SPT_E_OBJ(x)			((_KERNEL_ERRLEVEL) >= 1)
#define _KERNEL_SPT_E_NOEXS(x)			((_KERNEL_ERRLEVEL) >= 4)
#define _KERNEL_SPT_E_QOVR(x)			((_KERNEL_ERRLEVEL) >= 2)
#define _KERNEL_SPT_E_RLWAI(x)			((_KERNEL_ERRLEVEL) >= 0)
#define _KERNEL_SPT_E_TMOUT(x)			((_KERNEL_ERRLEVEL) >= 1)
#define _KERNEL_SPT_E_DLT(x)			((_KERNEL_ERRLEVEL) >= 3)
#define _KERNEL_SPT_E_CLS(x)			((_KERNEL_ERRLEVEL) >= 1)
#define _KERNEL_SPT_E_WBLK(x)			((_KERNEL_ERRLEVEL) >= 1)
#define _KERNEL_SPT_E_BOVR(x)			((_KERNEL_ERRLEVEL) >= 2)

#else

/* %jp{コンフィギュレーションファイルに従う}%en{through of configuration} */
#define _KERNEL_SPT_E_ID(x)				(x)
#define _KERNEL_SPT_E_SYS(x)			(x)
#define _KERNEL_SPT_E_NOSPT(x)			(x)
#define _KERNEL_SPT_E_RSFN(x)			(x)
#define _KERNEL_SPT_E_RSATR(x)			(x)
#define _KERNEL_SPT_E_PAR(x)			(x)
#define _KERNEL_SPT_E_ID(x)				(x)
#define _KERNEL_SPT_E_CTX(x)			(x)
#define _KERNEL_SPT_E_MACV(x)			(x)
#define _KERNEL_SPT_E_OACV(x)			(x)
#define _KERNEL_SPT_E_ILUSE(x)			(x)
#define _KERNEL_SPT_E_NOMEM(x)			(x)
#define _KERNEL_SPT_E_NOID(x)			(x)
#define _KERNEL_SPT_E_OBJ(x)			(x)
#define _KERNEL_SPT_E_NOEXS(x)			(x)
#define _KERNEL_SPT_E_QOVR(x)			(x)
#define _KERNEL_SPT_E_RLWAI(x)			(x)
#define _KERNEL_SPT_E_TMOUT(x)			(x)
#define _KERNEL_SPT_E_DLT(x)			(x)
#define _KERNEL_SPT_E_CLS(x)			(x)
#define _KERNEL_SPT_E_WBLK(x)			(x)
#define _KERNEL_SPT_E_BOVR(x)			(x)

#endif





/* cre_tsk */
/* acre_tsk */
/* del_tsk */
#define _KERNEL_SPT_DEL_TSK_E_ID		_KERNEL_SPT_E_ID	(_KERNEL_CFG_DEL_TSK_E_ID)
#define _KERNEL_SPT_DEL_TSK_E_NOEXS		_KERNEL_SPT_E_NOEXS	(_KERNEL_CFG_DEL_TSK_E_NOEXS)
#define _KERNEL_SPT_DEL_TSK_E_OBJ		_KERNEL_SPT_E_OBJ	(_KERNEL_CFG_DEL_TSK_E_OBJ)
#define _KERNEL_SPT_DEL_TSK_E_NOSPT		_KERNEL_SPT_E_NOSPT	(_KERNEL_CFG_DEL_TSK_E_NOSPT)

/* act_tsk */
#define _KERNEL_SPT_ACT_TSK_E_ID		_KERNEL_SPT_E_ID	(_KERNEL_CFG_ACT_TSK_E_ID)
#define _KERNEL_SPT_ACT_TSK_E_NOEXS		_KERNEL_SPT_E_NOEXS	(_KERNEL_CFG_ACT_TSK_E_NOEXS)
#define _KERNEL_SPT_ACT_TSK_E_NOSPT		_KERNEL_SPT_E_NOSPT	(_KERNEL_CFG_ACT_TSK_E_NOSPT)


/* iact_tsk */
#define _KERNEL_SPT_IACT_TSK_E_ID		_KERNEL_SPT_E_ID	(_KERNEL_SPT_IACT_TSK_E_ID)
#define _KERNEL_SPT_IACT_TSK_E_CTX		_KERNEL_SPT_E_CTX	(_KERNEL_SPT_IACT_TSK_E_CTX)	
#define _KERNEL_SPT_IACT_TSK_E_NOEXS	_KERNEL_SPT_E_NOEXS	(_KERNEL_CFG_IACT_TSK_E_NOEXS)
#define _KERNEL_SPT_IACT_TSK_E_NOSPT	_KERNEL_SPT_E_NOSPT	(_KERNEL_CFG_IACT_TSK_E_NOSPT)


/* can_act */
#define _KERNEL_SPT_CAN_ACT_E_ID		_KERNEL_SPT_E_ID	(_KERNEL_CFG_CAN_ACT_E_ID)
#define _KERNEL_SPT_CAN_ACT_E_NOEXS		_KERNEL_SPT_E_NOEXS	(_KERNEL_CFG_CAN_ACT_E_NOEXS)
#define _KERNEL_SPT_CAN_ACT_E_NOSPT		_KERNEL_SPT_E_NOSPT	(_KERNEL_CFG_CAN_ACT_E_NOSPT)


/* sta_tsk */
#define _KERNEL_SPT_STA_TSK_E_ID		_KERNEL_SPT_E_ID	(_KERNEL_CFG_STA_TSK_E_ID)
#define _KERNEL_SPT_STA_TSK_E_NOEXS		_KERNEL_SPT_E_NOEXS	(_KERNEL_CFG_STA_TSK_E_NOEXS)
#define _KERNEL_SPT_STA_TSK_E_OBJ		_KERNEL_SPT_E_OBJ	(_KERNEL_CFG_STA_TSK_E_OBJ)
#define _KERNEL_SPT_STA_TSK_E_NOSPT		_KERNEL_SPT_E_NOSPT	(_KERNEL_CFG_STA_TSK_E_NOSPT)

/* ext_tsk */
/* exd_tsk */
/* ter_tsk */
#define _KERNEL_SPT_TER_TSK_E_ID		_KERNEL_SPT_E_ID	(_KERNEL_CFG_TER_TSK_E_ID)
#define _KERNEL_SPT_TER_TSK_E_NOEXS		_KERNEL_SPT_E_NOEXS	(_KERNEL_CFG_TER_TSK_E_NOEXS)
#define _KERNEL_SPT_TER_TSK_E_ILUSE		_KERNEL_SPT_E_ILUSE	(_KERNEL_CFG_TER_TSK_E_ILUSE)
#define _KERNEL_SPT_TER_TSK_E_NOSPT		_KERNEL_SPT_E_NOSPT	(_KERNEL_CFG_TER_TSK_E_NOSPT)


/* chg_pri */
/* get_pri */
/* ref_tsk */
#define _KERNEL_SPT_REF_TSK_E_ID		_KERNEL_SPT_E_ID	(_KERNEL_CFG_REF_TSK_E_ID)
#define _KERNEL_SPT_REF_TSK_E_NOEXS		_KERNEL_SPT_E_NOEXS	(_KERNEL_CFG_REF_TSK_E_NOEXS)

/* ref_tst */

/* slp_tsk */
/* tslp_tsk */
/* wup_tsk */
#define _KERNEL_SPT_WUP_TSK_E_ID		_KERNEL_SPT_E_ID	(_KERNEL_CFG_WUP_TSK_E_ID)
#define _KERNEL_SPT_WUP_TSK_E_NOEXS		_KERNEL_SPT_E_NOEXS	(_KERNEL_CFG_WUP_TSK_E_NOEXS)
#define _KERNEL_SPT_WUP_TSK_E_QOVR		_KERNEL_SPT_E_QOVR	(_KERNEL_CFG_WUP_TSK_E_QOVR)

/* iwup_tsk */
/* can_wup */
#define _KERNEL_SPT_CAN_WUP_E_ID		_KERNEL_SPT_E_ID	(_KERNEL_CFG_CAN_WUP_E_ID)
#define _KERNEL_SPT_CAN_WUP_E_NOEXS		_KERNEL_SPT_E_NOEXS	(_KERNEL_CFG_CAN_WUP_E_NOEXS)

/* rel_wai */
#define _KERNEL_SPT_REL_WAI_E_ID		_KERNEL_SPT_E_ID	(_KERNEL_CFG_REL_WAI_E_ID)
#define _KERNEL_SPT_REL_WAI_E_NOEXS		_KERNEL_SPT_E_NOEXS	(_KERNEL_CFG_REL_WAI_E_NOEXS)
/* irel_wai */
/* sus_tsk */
#define _KERNEL_SPT_SUS_TSK_E_ID		_KERNEL_SPT_E_ID	(_KERNEL_CFG_SUS_TSK_E_ID)		
#define _KERNEL_SPT_SUS_TSK_E_CTX		_KERNEL_SPT_E_CTX	(_KERNEL_CFG_SUS_TSK_E_CTX)
#define _KERNEL_SPT_SUS_TSK_E_NOEXS		_KERNEL_SPT_E_NOEXS	(_KERNEL_CFG_SUS_TSK_E_NOEXS)
#define _KERNEL_SPT_SUS_TSK_E_OBJ		_KERNEL_SPT_E_OBJ	(_KERNEL_CFG_SUS_TSK_E_OBJ)
#define _KERNEL_SPT_SUS_TSK_E_QOVR		_KERNEL_SPT_E_QOVR	(_KERNEL_CFG_SUS_TSK_E_QOVR)
#define _KERNEL_SPT_SUS_TSK_E_NOSPT		_KERNEL_SPT_E_NOSPT	(_KERNEL_CFG_SUS_TSK_E_NOSPT)


/* rsm_tsk */
/* frsm_tsk */

/* dly_tsk */
#define _KERNEL_SPT_DLY_TSK_E_CTX		_KERNEL_SPT_E_CTX	(_KERNEL_CFG_DLY_TSK_E_CTX)



/* def_tex */
#define _KERNEL_SPT_DEF_TEX_E_ID		_KERNEL_SPT_E_ID	(_KERNEL_CFG_DEF_TEX_E_ID)
#define _KERNEL_SPT_DEF_TEX_E_NOEXS		_KERNEL_SPT_E_NOEXS	(_KERNEL_CFG_DEF_TEX_E_NOEXS)
#define _KERNEL_SPT_DEF_TEX_E_RSATR 	_KERNEL_SPT_E_RSATR (_KERNEL_CFG_DEF_TEX_E_RSATR)
#define _KERNEL_SPT_DEF_TEX_E_NOMEM		_KERNEL_SPT_E_NOMEM	(_KERNEL_CFG_DEF_TEX_E_NOMEM)
#define _KERNEL_SPT_DEF_TEX_E_NOSPT		_KERNEL_SPT_E_NOSPT	(_KERNEL_CFG_DEF_TEX_E_NOSPT)


/* ras_tex */
/* iras_tex */
/* dis_tex */
/* ena_tex */
/* sns_tex */
/* ref_tex */


/* cre_sem */
#define _KERNEL_SPT_CRE_SEM_E_ID		_KERNEL_SPT_E_ID	(_KERNEL_CFG_CRE_SEM_E_ID)
#define _KERNEL_SPT_CRE_SEM_E_RSATR 	_KERNEL_SPT_E_RSATR (_KERNEL_CFG_CRE_SEM_E_RSATR)
#define _KERNEL_SPT_CRE_SEM_E_OBJ		_KERNEL_SPT_E_OBJ	(_KERNEL_CFG_CRE_SEM_E_OBJ)
#define _KERNEL_SPT_CRE_SEM_E_NOMEM		_KERNEL_SPT_E_NOMEM	(_KERNEL_CFG_CRE_SEM_E_NOMEM)	
#define _KERNEL_SPT_CRE_SEM_E_NOSPT		_KERNEL_SPT_E_NOSPT	(_KERNEL_CFG_CRE_SEM_E_NOSPT)

/* acre_sem */
#define _KERNEL_SPT_ACRE_SEM_E_NOID		_KERNEL_SPT_E_NOID	(_KERNEL_CFG_ACRE_SEM_E_NOID)
#define _KERNEL_SPT_ACRE_SEM_E_RSATR 	_KERNEL_SPT_E_RSATR	(_KERNEL_CFG_ACRE_SEM_E_RSATR)
#define _KERNEL_SPT_ACRE_SEM_E_NOMEM	_KERNEL_SPT_E_NOMEM	(_KERNEL_CFG_ACRE_SEM_E_NOMEM)
#define _KERNEL_SPT_ACRE_SEM_E_NOSPT	_KERNEL_SPT_E_NOSPT	(_KERNEL_CFG_ACRE_SEM_E_NOSPT)

/* del_sem */
#define _KERNEL_SPT_DEL_SEM_E_ID		_KERNEL_SPT_E_ID	(_KERNEL_CFG_DEL_SEM_E_ID)
#define _KERNEL_SPT_DEL_SEM_E_NOEXS		_KERNEL_SPT_E_NOEXS	(_KERNEL_CFG_DEL_SEM_E_NOEXS)
#define _KERNEL_SPT_DEL_SEM_E_NOSPT		_KERNEL_SPT_E_NOSPT	(_KERNEL_CFG_DEL_SEM_E_NOSPT)

/* sig_sem */
#define _KERNEL_SPT_SIG_SEM_E_ID		_KERNEL_SPT_E_ID	(_KERNEL_CFG_SIG_SEM_E_ID)
#define _KERNEL_SPT_SIG_SEM_E_NOEXS		_KERNEL_SPT_E_NOEXS	(_KERNEL_CFG_SIG_SEM_E_NOEXS)
#define _KERNEL_SPT_SIG_SEM_E_QOVR		_KERNEL_SPT_E_QOVR	(_KERNEL_CFG_SIG_SEM_E_QOVR)
#define _KERNEL_SPT_SIG_SEM_E_NOSPT		_KERNEL_SPT_E_NOSPT	(_KERNEL_CFG_SIG_SEM_E_NOSPT)

/* isig_sem */
#define _KERNEL_SPT_ISIG_SEM_E_ID		_KERNEL_SPT_E_ID	(_KERNEL_CFG_ISIG_SEM_E_ID)
#define _KERNEL_SPT_ISIG_SEM_E_NOEXS	_KERNEL_SPT_E_NOEXS	(_KERNEL_CFG_ISIG_SEM_E_NOEXS)
#define _KERNEL_SPT_ISIG_SEM_E_QOVR		_KERNEL_SPT_E_QOVR	(_KERNEL_CFG_ISIG_SEM_E_QOVR)	
#define _KERNEL_SPT_ISIG_SEM_E_NOSPT	_KERNEL_SPT_E_NOSPT	(_KERNEL_CFG_ISIG_SEM_E_NOSPT)

/* wai_sem */
#define _KERNEL_SPT_WAI_SEM_E_ID		_KERNEL_SPT_E_ID	(_KERNEL_CFG_WAI_SEM_E_ID)
#define _KERNEL_SPT_WAI_SEM_E_CTX		_KERNEL_SPT_E_CTX	(_KERNEL_CFG_WAI_SEM_E_CTX)
#define _KERNEL_SPT_WAI_SEM_E_NOEXS		_KERNEL_SPT_E_NOEXS	(_KERNEL_CFG_WAI_SEM_E_NOEXS)
#define _KERNEL_SPT_WAI_SEM_E_RLWAI 	_KERNEL_SPT_E_RLWAI (_KERNEL_CFG_WAI_SEM_E_RLWAI)
#define _KERNEL_SPT_WAI_SEM_E_DLT   	_KERNEL_SPT_E_DLT   (_KERNEL_CFG_WAI_SEM_E_DLT)
#define _KERNEL_SPT_WAI_SEM_E_NOSPT		_KERNEL_SPT_E_NOSPT	(_KERNEL_CFG_WAI_SEM_E_NOSPT)

/* pol_sem */
#define _KERNEL_SPT_POL_SEM_E_ID		_KERNEL_SPT_E_ID	(_KERNEL_CFG_POL_SEM_E_ID)
#define _KERNEL_SPT_POL_SEM_E_NOEXS		_KERNEL_SPT_E_NOEXS	(_KERNEL_CFG_POL_SEM_E_NOEXS)
#define _KERNEL_SPT_POL_SEM_E_TMOUT		_KERNEL_SPT_E_TMOUT	(_KERNEL_CFG_POL_SEM_E_TMOUT)
#define _KERNEL_SPT_POL_SEM_E_NOSPT		_KERNEL_SPT_E_NOSPT	(_KERNEL_CFG_POL_SEM_E_NOSPT)

/* twai_sem */
#define _KERNEL_SPT_TWAI_SEM_E_ID		_KERNEL_SPT_E_ID	(_KERNEL_CFG_TWAI_SEM_E_ID)
#define _KERNEL_SPT_TWAI_SEM_E_CTX		_KERNEL_SPT_E_CTX	(_KERNEL_CFG_TWAI_SEM_E_CTX)
#define _KERNEL_SPT_TWAI_SEM_E_NOEXS	_KERNEL_SPT_E_NOEXS	(_KERNEL_CFG_TWAI_SEM_E_NOEXS)
#define _KERNEL_SPT_TWAI_SEM_E_TMOUT	_KERNEL_SPT_E_TMOUT	(_KERNEL_CFG_TWAI_SEM_E_TMOUT)
#define _KERNEL_SPT_TWAI_SEM_E_RLWAI 	_KERNEL_SPT_E_RLWAI	(_KERNEL_CFG_TWAI_SEM_E_RLWAI)
#define _KERNEL_SPT_TWAI_SEM_E_DLT   	_KERNEL_SPT_E_DLT  	(_KERNEL_CFG_TWAI_SEM_E_DLT)
#define _KERNEL_SPT_TWAI_SEM_E_NOSPT	_KERNEL_SPT_E_NOSPT	(_KERNEL_CFG_TWAI_SEM_E_NOSPT)

/* _kernel_wai_sem */
#if _KERNEL_OPT_CODE_SIZE <= _KERNEL_OPT_SPEED	/* %jp{twai_semへの集約を行う場合} */
#define _KERNEL_SPT_KWAI_SEM_E_ID		(_KERNEL_CFG_TWAI_SEM_E_ID    || _KERNEL_CFG_WAI_SEM_E_ID    || _KERNEL_CFG_POL_SEM_E_ID)
#define _KERNEL_SPT_KWAI_SEM_E_CTX		(_KERNEL_CFG_TWAI_SEM_E_CTX   || _KERNEL_CFG_WAI_SEM_E_CTX)
#define _KERNEL_SPT_KWAI_SEM_E_NOEXS	(_KERNEL_CFG_TWAI_SEM_E_NOEXS || _KERNEL_CFG_WAI_SEM_E_NOEXS || _KERNEL_CFG_POL_SEM_E_NOEXS)
#define _KERNEL_SPT_KWAI_SEM_E_TMOUT	(_KERNEL_CFG_TWAI_SEM_E_TMOUT                                || _KERNEL_CFG_POL_SEM_E_TMOUT)
#define _KERNEL_SPT_KWAI_SEM_E_RLWAI 	(_KERNEL_CFG_TWAI_SEM_E_RLWAI || _KERNEL_CFG_WAI_SEM_E_RLWAI)
#define _KERNEL_SPT_KWAI_SEM_E_DLT   	(_KERNEL_CFG_TWAI_SEM_E_DLT   || _KERNEL_CFG_WAI_SEM_E_DLT)
#define _KERNEL_SPT_KWAI_SEM_E_NOSPT	_KERNEL_CFG_TWAI_SEM_E_NOSPT
#else
#define _KERNEL_SPT_KWAI_SEM_E_ID		_KERNEL_SPT_E_ID	(_KERNEL_CFG_TWAI_SEM_E_ID)
#define _KERNEL_SPT_KWAI_SEM_E_CTX		_KERNEL_SPT_E_CTX	(_KERNEL_CFG_TWAI_SEM_E_CTX)
#define _KERNEL_SPT_KWAI_SEM_E_NOEXS	_KERNEL_SPT_E_NOEXS	(_KERNEL_CFG_TWAI_SEM_E_NOEXS)
#define _KERNEL_SPT_KWAI_SEM_E_TMOUT	_KERNEL_SPT_E_TMOUT	(_KERNEL_CFG_TWAI_SEM_E_TMOUT)
#define _KERNEL_SPT_KWAI_SEM_E_RLWAI 	_KERNEL_SPT_E_RLWAI	(_KERNEL_CFG_TWAI_SEM_E_RLWAI) 
#define _KERNEL_SPT_KWAI_SEM_E_DLT   	_KERNEL_SPT_E_DLT	(_KERNEL_CFG_TWAI_SEM_E_DLT)
#define _KERNEL_SPT_KWAI_SEM_E_NOSPT	_KERNEL_SPT_E_NOSPT	(_KERNEL_CFG_TWAI_SEM_E_NOSPT)
#endif

/* ref_sem */
#define _KERNEL_SPT_REF_SEM_E_ID		_KERNEL_SPT_E_ID	(_KERNEL_CFG_REF_SEM_E_ID)
#define _KERNEL_SPT_REF_SEM_E_NOEXS		_KERNEL_SPT_E_NOEXS	(_KERNEL_CFG_REF_SEM_E_NOEXS)
#define _KERNEL_SPT_REF_SEM_E_PAR		_KERNEL_SPT_E_PAR	(_KERNEL_CFG_REF_SEM_E_PAR)
#define _KERNEL_SPT_REF_SEM_E_NOSPT		_KERNEL_SPT_E_NOSPT	(_KERNEL_CFG_REF_SEM_E_NOSPT)


/* cre_flg */
#define _KERNEL_SPT_CRE_FLG_E_ID		_KERNEL_SPT_E_ID	(_KERNEL_CFG_CRE_FLG_E_ID)
#define _KERNEL_SPT_CRE_FLG_E_RSATR 	_KERNEL_SPT_E_RSATR (_KERNEL_CFG_CRE_FLG_E_RSATR)
#define _KERNEL_SPT_CRE_FLG_E_OBJ		_KERNEL_SPT_E_OBJ	(_KERNEL_CFG_CRE_FLG_E_OBJ)
#define _KERNEL_SPT_CRE_FLG_E_NOMEM		_KERNEL_SPT_E_NOMEM	(_KERNEL_CFG_CRE_FLG_E_NOMEM)
#define _KERNEL_SPT_CRE_FLG_E_NOSPT		_KERNEL_SPT_E_NOSPT	(_KERNEL_CFG_CRE_FLG_E_NOSPT)

/* acre_flg */
#define _KERNEL_SPT_ACRE_FLG_E_NOID		_KERNEL_SPT_E_NOID	(_KERNEL_CFG_ACRE_FLG_E_NOID)	
#define _KERNEL_SPT_ACRE_FLG_E_RSATR	_KERNEL_SPT_E_RSATR	(_KERNEL_CFG_ACRE_FLG_E_RSATR)
#define _KERNEL_SPT_ACRE_FLG_E_NOMEM	_KERNEL_SPT_E_NOMEM	(_KERNEL_CFG_ACRE_FLG_E_NOMEM)
#define _KERNEL_SPT_ACRE_FLG_E_NOSPT	_KERNEL_SPT_E_NOSPT	(_KERNEL_CFG_ACRE_FLG_E_NOSPT)

/* del_flg */
#define _KERNEL_SPT_DEL_FLG_E_ID		_KERNEL_SPT_E_ID	(_KERNEL_CFG_DEL_FLG_E_ID)
#define _KERNEL_SPT_DEL_FLG_E_NOEXS		_KERNEL_SPT_E_NOEXS	(_KERNEL_CFG_DEL_FLG_E_NOEXS)
#define _KERNEL_SPT_DEL_FLG_E_NOSPT		_KERNEL_SPT_E_NOSPT	(_KERNEL_CFG_DEL_FLG_E_NOSPT)
 
/* set_flg */
#define _KERNEL_SPT_SET_FLG_E_ID		_KERNEL_SPT_E_ID	(_KERNEL_CFG_SET_FLG_E_ID)
#define _KERNEL_SPT_SET_FLG_E_NOEXS		_KERNEL_SPT_E_NOEXS	(_KERNEL_CFG_SET_FLG_E_NOEXS)
#define _KERNEL_SPT_SET_FLG_E_PAR		_KERNEL_SPT_E_PAR	(_KERNEL_CFG_SET_FLG_E_PAR)
#define _KERNEL_SPT_SET_FLG_E_NOSPT		_KERNEL_SPT_E_NOSPT	(_KERNEL_CFG_SET_FLG_E_NOSPT)

/* iset_flg */
#define _KERNEL_SPT_ISET_FLG_E_ID		_KERNEL_SPT_E_ID	(_KERNEL_CFG_ISET_FLG_E_ID)
#define _KERNEL_SPT_ISET_FLG_E_NOEXS	_KERNEL_SPT_E_NOEXS	(_KERNEL_CFG_ISET_FLG_E_NOEXS)
#define _KERNEL_SPT_ISET_FLG_E_NOSPT	_KERNEL_SPT_E_NOSPT	(_KERNEL_CFG_ISET_FLG_E_NOSPT)

/* clr_flg */
#define _KERNEL_SPT_CLR_FLG_E_ID		_KERNEL_SPT_E_ID	(_KERNEL_CFG_CLR_FLG_E_ID)
#define _KERNEL_SPT_CLR_FLG_E_NOEXS		_KERNEL_SPT_E_NOEXS	(_KERNEL_CFG_CLR_FLG_E_NOEXS)
#define _KERNEL_SPT_CLR_FLG_E_PAR		_KERNEL_SPT_E_PAR	(_KERNEL_CFG_CLR_FLG_E_PAR)
#define _KERNEL_SPT_CLR_FLG_E_NOSPT		_KERNEL_SPT_E_NOSPT	(_KERNEL_CFG_CLR_FLG_E_NOSPT)

/* wai_flg */
#define _KERNEL_SPT_WAI_FLG_E_ID		_KERNEL_SPT_E_ID	(_KERNEL_CFG_WAI_FLG_E_ID)
#define _KERNEL_SPT_WAI_FLG_E_CTX		_KERNEL_SPT_E_CTX	(_KERNEL_CFG_WAI_FLG_E_CTX)
#define _KERNEL_SPT_WAI_FLG_E_NOEXS		_KERNEL_SPT_E_NOEXS (_KERNEL_CFG_WAI_FLG_E_NOEXS)
#define _KERNEL_SPT_WAI_FLG_E_PAR		_KERNEL_SPT_E_PAR	(_KERNEL_CFG_WAI_FLG_E_PAR)
#define _KERNEL_SPT_WAI_FLG_E_ILUSE		_KERNEL_SPT_E_ILUSE (_KERNEL_CFG_WAI_FLG_E_ILUSE)
#define _KERNEL_SPT_WAI_FLG_E_RLWAI		_KERNEL_SPT_E_RLWAI (_KERNEL_CFG_WAI_FLG_E_RLWAI)
#define _KERNEL_SPT_WAI_FLG_E_DLT		_KERNEL_SPT_E_DLT	(_KERNEL_CFG_WAI_FLG_E_DLT)
#define _KERNEL_SPT_WAI_FLG_E_NOSPT		_KERNEL_SPT_E_NOSPT	(_KERNEL_CFG_WAI_FLG_E_NOSPT)

/* pol_flg */
#define _KERNEL_SPT_POL_FLG_E_ID		_KERNEL_SPT_E_ID	(_KERNEL_CFG_POL_FLG_E_ID)
#define _KERNEL_SPT_POL_FLG_E_NOEXS 	_KERNEL_SPT_E_NOEXS	(_KERNEL_CFG_POL_FLG_E_NOEXS)
#define _KERNEL_SPT_POL_FLG_E_PAR   	_KERNEL_SPT_E_PAR  	(_KERNEL_CFG_POL_FLG_E_PAR)
#define _KERNEL_SPT_POL_FLG_E_TMOUT   	_KERNEL_SPT_E_TMOUT	(_KERNEL_CFG_POL_FLG_E_TMOUT)
#define _KERNEL_SPT_POL_FLG_E_NOSPT		_KERNEL_SPT_E_NOSPT	(_KERNEL_CFG_POL_FLG_E_NOSPT)

/* twai_flg */
#if _KERNEL_OPT_CODE_SIZE <= _KERNEL_OPT_SPEED	/* %jp{twai_flgへの集約を行う場合} */
#define _KERNEL_SPT_TWAI_FLG_E_ID		(_KERNEL_CFG_TWAI_FLG_E_ID    || _KERNEL_CFG_WAI_FLG_E_ID    || _KERNEL_CFG_POL_FLG_E_ID) 
#define _KERNEL_SPT_TWAI_FLG_E_CTX		(_KERNEL_CFG_TWAI_FLG_E_CTX   || _KERNEL_CFG_WAI_FLG_E_CTX)
#define _KERNEL_SPT_TWAI_FLG_E_NOEXS 	(_KERNEL_CFG_TWAI_FLG_E_NOEXS || _KERNEL_CFG_WAI_FLG_E_NOEXS || _KERNEL_CFG_POL_FLG_E_NOEXS)
#define _KERNEL_SPT_TWAI_FLG_E_PAR   	(_KERNEL_CFG_TWAI_FLG_E_PAR   || _KERNEL_CFG_WAI_FLG_E_PAR   || _KERNEL_CFG_POL_FLG_E_PAR)
#define _KERNEL_SPT_TWAI_FLG_E_ILUSE 	(_KERNEL_CFG_TWAI_FLG_E_ILUSE || _KERNEL_CFG_WAI_FLG_E_ILUSE)
#define _KERNEL_SPT_TWAI_FLG_E_TMOUT   	(_KERNEL_CFG_TWAI_FLG_E_TMOUT                                || _KERNEL_CFG_POL_FLG_E_TMOUT)
#define _KERNEL_SPT_TWAI_FLG_E_RLWAI 	(_KERNEL_CFG_TWAI_FLG_E_RLWAI || _KERNEL_CFG_WAI_FLG_E_RLWAI)
#define _KERNEL_SPT_TWAI_FLG_E_DLT   	(_KERNEL_CFG_TWAI_FLG_E_DLT   || _KERNEL_CFG_WAI_FLG_E_DLT)
#define _KERNEL_SPT_TWAI_FLG_E_NOSPT	_KERNEL_CFG_TWAI_FLG_E_NOSPT
#else
#define _KERNEL_SPT_TWAI_FLG_E_ID		_KERNEL_SPT_E_ID	(_KERNEL_CFG_TWAI_FLG_E_ID)
#define _KERNEL_SPT_TWAI_FLG_E_CTX		_KERNEL_SPT_E_CTX	(_KERNEL_CFG_TWAI_FLG_E_CTX)
#define _KERNEL_SPT_TWAI_FLG_E_NOEXS 	_KERNEL_SPT_E_NOEXS	(_KERNEL_CFG_TWAI_FLG_E_NOEXS)
#define _KERNEL_SPT_TWAI_FLG_E_PAR   	_KERNEL_SPT_E_PAR  	(_KERNEL_CFG_TWAI_FLG_E_PAR)
#define _KERNEL_SPT_TWAI_FLG_E_ILUSE 	_KERNEL_SPT_E_ILUSE	(_KERNEL_CFG_TWAI_FLG_E_ILUSE)
#define _KERNEL_SPT_TWAI_FLG_E_TMOUT   	_KERNEL_SPT_E_TMOUT	(_KERNEL_CFG_TWAI_FLG_E_TMOUT)
#define _KERNEL_SPT_TWAI_FLG_E_RLWAI 	_KERNEL_SPT_E_RLWAI	(_KERNEL_CFG_TWAI_FLG_E_RLWAI)
#define _KERNEL_SPT_TWAI_FLG_E_DLT   	_KERNEL_SPT_E_DLT  	(_KERNEL_CFG_TWAI_FLG_E_DLT)
#define _KERNEL_SPT_TWAI_FLG_E_NOSPT	_KERNEL_SPT_E_NOSPT	(_KERNEL_CFG_TWAI_FLG_E_NOSPT)
#endif

/* ref_flg */
#define _KERNEL_SPT_REF_FLG_E_ID		_KERNEL_SPT_E_ID	(_KERNEL_CFG_REF_FLG_E_ID)
#define _KERNEL_SPT_REF_FLG_E_NOEXS 	_KERNEL_SPT_E_NOEXS	(_KERNEL_CFG_REF_FLG_E_NOEXS)
#define _KERNEL_SPT_REF_FLG_E_PAR   	_KERNEL_SPT_E_PAR	(_KERNEL_CFG_REF_FLG_E_PAR)
#define _KERNEL_SPT_REF_FLG_E_NOSPT		_KERNEL_SPT_E_NOSPT	(_KERNEL_CFG_REF_FLG_E_NOSPT)


/* cre_dtq */
#define _KERNEL_SPT_CRE_DTQ_E_ID		_KERNEL_SPT_E_ID	(_KERNEL_CFG_CRE_DTQ_E_ID)
#define _KERNEL_SPT_CRE_DTQ_E_RSATR		_KERNEL_SPT_E_RSATR	(_KERNEL_CFG_CRE_DTQ_E_RSATR)
#define _KERNEL_SPT_CRE_DTQ_E_OBJ		_KERNEL_SPT_E_OBJ	(_KERNEL_CFG_CRE_DTQ_E_OBJ)
#define _KERNEL_SPT_CRE_DTQ_E_NOMEM		_KERNEL_SPT_E_NOMEM	(_KERNEL_CFG_CRE_DTQ_E_NOMEM)
#define _KERNEL_SPT_CRE_DTQ_E_NOSPT		_KERNEL_SPT_E_NOSPT	(_KERNEL_CFG_CRE_DTQ_E_NOSPT)

/* acre_dtq */
#define _KERNEL_SPT_ACRE_DTQ_E_RSATR	_KERNEL_SPT_E_RSATR	(_KERNEL_CFG_ACRE_DTQ_E_RSATR)
#define _KERNEL_SPT_ACRE_DTQ_E_NOID		_KERNEL_SPT_E_NOID	(_KERNEL_CFG_ACRE_DTQ_E_NOID)	
#define _KERNEL_SPT_ACRE_DTQ_E_NOMEM	_KERNEL_SPT_E_NOMEM	(_KERNEL_CFG_ACRE_DTQ_E_NOMEM)
#define _KERNEL_SPT_ACRE_DTQ_E_NOSPT	_KERNEL_SPT_E_NOSPT	(_KERNEL_CFG_ACRE_DTQ_E_NOSPT)

/* del_dtq */
/* snd_dtq */
#define _KERNEL_SPT_SND_DTQ_E_CTX		_KERNEL_SPT_E_CTX	(_KERNEL_CFG_SND_DTQ_E_CTX)
#define _KERNEL_SPT_SND_DTQ_E_ID		_KERNEL_SPT_E_ID	(_KERNEL_CFG_SND_DTQ_E_ID)
#define _KERNEL_SPT_SND_DTQ_E_NOEXS		_KERNEL_SPT_E_NOEXS	(_KERNEL_CFG_SND_DTQ_E_NOEXS)
#define _KERNEL_SPT_SND_DTQ_E_NOSPT		_KERNEL_SPT_E_NOSPT	(_KERNEL_CFG_SND_DTQ_E_NOSPT)

/* ipsnd_dtq */
/* tsnd_dtq */
/* fsnd_dtq */
#define _KERNEL_SPT_FSND_DTQ_E_ID		_KERNEL_SPT_E_ID	(_KERNEL_CFG_FSND_DTQ_E_ID)
#define _KERNEL_SPT_FSND_DTQ_E_NOEXS	_KERNEL_SPT_E_NOEXS	(_KERNEL_CFG_FSND_DTQ_E_NOEXS)
#define _KERNEL_SPT_FSND_DTQ_E_ILUSE	_KERNEL_SPT_E_ILUSE	(_KERNEL_CFG_FSND_DTQ_E_ILUSE)
#define _KERNEL_SPT_FSND_DTQ_E_NOSPT	_KERNEL_SPT_E_NOSPT	(_KERNEL_CFG_FSND_DTQ_E_NOSPT)

/* ifsnd_dtq */
/* rcv_dtq */
#define _KERNEL_SPT_RCV_DTQ_E_CTX		_KERNEL_SPT_E_CTX	(_KERNEL_CFG_RCV_DTQ_E_CTX)
#define _KERNEL_SPT_RCV_DTQ_E_ID		_KERNEL_SPT_E_ID	(_KERNEL_CFG_RCV_DTQ_E_ID)
#define _KERNEL_SPT_RCV_DTQ_E_NOEXS		_KERNEL_SPT_E_NOEXS	(_KERNEL_CFG_RCV_DTQ_E_NOEXS)
#define _KERNEL_SPT_RCV_DTQ_E_NOSPT		_KERNEL_SPT_E_NOSPT	(_KERNEL_CFG_RCV_DTQ_E_NOSPT)

/* prcv_dtq */
#define _KERNEL_SPT_PRCV_DTQ_E_CTX		_KERNEL_SPT_E_CTX	(_KERNEL_CFG_PRCV_DTQ_E_CTX)
#define _KERNEL_SPT_PRCV_DTQ_E_ID		_KERNEL_SPT_E_ID	(_KERNEL_CFG_PRCV_DTQ_E_ID)
#define _KERNEL_SPT_PRCV_DTQ_E_NOEXS	_KERNEL_SPT_E_NOEXS	(_KERNEL_CFG_PRCV_DTQ_E_NOEXS)
#define _KERNEL_SPT_PRCV_DTQ_E_NOSPT	_KERNEL_SPT_E_NOSPT	(_KERNEL_CFG_PRCV_DTQ_E_NOSPT)

/* trcv_dtq */

/* ref_dtq */



/* cre_mbx */
#define _KERNEL_SPT_CRE_MBX_E_ID		_KERNEL_SPT_E_ID	(_KERNEL_CFG_CRE_MBX_E_ID)
#define _KERNEL_SPT_CRE_MBX_E_RSATR 	_KERNEL_SPT_E_RSATR	(_KERNEL_CFG_CRE_MBX_E_RSATR)
#define _KERNEL_SPT_CRE_MBX_E_OBJ		_KERNEL_SPT_E_OBJ	(_KERNEL_CFG_CRE_MBX_E_OBJ)
#define _KERNEL_SPT_CRE_MBX_E_NOMEM		_KERNEL_SPT_E_NOMEM	(_KERNEL_CFG_CRE_MBX_E_NOMEM)
#define _KERNEL_SPT_CRE_MBX_E_NOSPT		_KERNEL_SPT_E_NOSPT	(_KERNEL_CFG_CRE_MBX_E_NOSPT)

/* acre_mbx */
#define _KERNEL_SPT_ACRE_MBX_E_NOID		_KERNEL_SPT_E_NOID	(_KERNEL_CFG_ACRE_MBX_E_NOID)
#define _KERNEL_SPT_ACRE_MBX_E_RSATR 	_KERNEL_SPT_E_RSATR	(_KERNEL_CFG_ACRE_MBX_E_RSATR)
#define _KERNEL_SPT_ACRE_MBX_E_NOMEM	_KERNEL_SPT_E_NOMEM	(_KERNEL_CFG_ACRE_MBX_E_NOMEM)	
#define _KERNEL_SPT_ACRE_MBX_E_NOSPT	_KERNEL_SPT_E_NOSPT	(_KERNEL_CFG_ACRE_MBX_E_NOSPT)

/* del_mbx */
#define _KERNEL_SPT_DEL_MBX_E_ID		_KERNEL_SPT_E_ID	(_KERNEL_CFG_DEL_MBX_E_ID)
#define _KERNEL_SPT_DEL_MBX_E_NOEXS		_KERNEL_SPT_E_NOEXS	(_KERNEL_CFG_DEL_MBX_E_NOEXS)
#define _KERNEL_SPT_DEL_MBX_E_NOSPT		_KERNEL_SPT_E_NOSPT	(_KERNEL_CFG_DEL_MBX_E_NOSPT)

/* snd_mbx */
/* rcv_mbx */
#define _KERNEL_SPT_RCV_MBX_E_ID		_KERNEL_SPT_E_ID	(_KERNEL_CFG_RCV_MBX_E_ID)
#define _KERNEL_SPT_RCV_MBX_E_NOEXS		_KERNEL_SPT_E_NOEXS	(_KERNEL_CFG_RCV_MBX_E_NOEXS)
#define _KERNEL_SPT_RCV_MBX_E_NOSPT		_KERNEL_SPT_E_NOSPT	(_KERNEL_CFG_RCV_MBX_E_NOSPT)

/* prcv_mbx */
/* trcv_mbx */
/* ref_mbx */


/* cre_mtx */
#define _KERNEL_SPT_CRE_MTX_E_ID		_KERNEL_SPT_E_ID	(_KERNEL_CFG_CRE_MTX_E_ID)
#define _KERNEL_SPT_CRE_MTX_E_RSATR		_KERNEL_SPT_E_RSATR	(_KERNEL_CFG_CRE_MTX_E_RSATR)
#define _KERNEL_SPT_CRE_MTX_E_OBJ		_KERNEL_SPT_E_OBJ	(_KERNEL_CFG_CRE_MTX_E_OBJ)
#define _KERNEL_SPT_CRE_MTX_E_NOSPT		_KERNEL_SPT_E_NOSPT	(_KERNEL_CFG_CRE_MTX_E_NOSPT)
#define _KERNEL_SPT_CRE_MTX_E_NOMEM		_KERNEL_SPT_E_NOMEM	(_KERNEL_CFG_CRE_MTX_E_NOMEM)

/* acre_mtx */
#define _KERNEL_SPT_ACRE_MTX_E_RSATR	_KERNEL_SPT_E_RSATR	(_KERNEL_CFG_ACRE_MTX_E_RSATR)
#define _KERNEL_SPT_ACRE_MTX_E_NOID		_KERNEL_SPT_E_NOID	(_KERNEL_CFG_ACRE_MTX_E_NOID)
#define _KERNEL_SPT_ACRE_MTX_E_NOSPT	_KERNEL_SPT_E_NOSPT	(_KERNEL_CFG_ACRE_MTX_E_NOSPT)
#define _KERNEL_SPT_ACRE_MTX_E_NOMEM	_KERNEL_SPT_E_NOMEM	(_KERNEL_CFG_ACRE_MTX_E_NOMEM)

/* del_mtx */
#define _KERNEL_SPT_DEL_MTX_E_ID		_KERNEL_SPT_E_ID	(_KERNEL_CFG_DEL_MTX_E_ID)
#define _KERNEL_SPT_DEL_MTX_E_NOEXS		_KERNEL_SPT_E_NOEXS	(_KERNEL_CFG_DEL_MTX_E_NOEXS)
#define _KERNEL_SPT_DEL_MTX_E_NOSPT		_KERNEL_SPT_E_NOSPT	(_KERNEL_CFG_DEL_MTX_E_NOSPT)

/* loc_mtx */
#define _KERNEL_SPT_LOC_MTX_E_CTX		_KERNEL_SPT_E_CTX	(_KERNEL_CFG_LOC_MTX_E_CTX)
#define _KERNEL_SPT_LOC_MTX_E_ID		_KERNEL_SPT_E_ID	(_KERNEL_CFG_LOC_MTX_E_ID)
#define _KERNEL_SPT_LOC_MTX_E_NOEXS		_KERNEL_SPT_E_NOEXS	(_KERNEL_CFG_LOC_MTX_E_NOEXS)
#define _KERNEL_SPT_LOC_MTX_E_NOSPT		_KERNEL_SPT_E_NOSPT	(_KERNEL_CFG_LOC_MTX_E_NOSPT)

/* ploc_mtx */
/* tloc_mtx */
/* unl_mtx */
#define _KERNEL_SPT_UNL_MTX_E_CTX		_KERNEL_SPT_E_CTX	(_KERNEL_CFG_UNL_MTX_E_CTX)
#define _KERNEL_SPT_UNL_MTX_E_ID		_KERNEL_SPT_E_ID	(_KERNEL_CFG_UNL_MTX_E_ID)
#define _KERNEL_SPT_UNL_MTX_E_NOEXS		_KERNEL_SPT_E_NOEXS	(_KERNEL_CFG_UNL_MTX_E_NOEXS)
#define _KERNEL_SPT_UNL_MTX_E_ILUSE		_KERNEL_SPT_E_ILUSE	(_KERNEL_CFG_UNL_MTX_E_ILUSE)
#define _KERNEL_SPT_UNL_MTX_E_NOSPT		_KERNEL_SPT_E_NOSPT	(_KERNEL_CFG_UNL_MTX_E_NOSPT)


/* ref_mtx */


/* cre_mbf */
/* acre_mbf */
/* del_mbf */
/* snd_mbf */
/* psnd_mbf */
/* tsnd_mbf */
/* rcv_mbf */
/* prcv_mbf */
/* trcv_mbf */
/* ref_mbf */


/* cre_por */
/* acre_por */
/* del_por */
/* cal_por */
/* tcal_por */
/* acp_por */
/* pacp_por */
/* tacp_por */
/* fwd_por */
/* rpl_rdv */
/* ref_por */
/* ref_rdv */


/* cre_mpf */
#define _KERNEL_SPT_CRE_MPF_E_ID		_KERNEL_SPT_E_ID	(_KERNEL_CFG_CRE_MPF_E_ID)
#define _KERNEL_SPT_CRE_MPF_E_RSATR 	_KERNEL_SPT_E_RSATR (_KERNEL_CFG_CRE_MPF_E_RSATR)
#define _KERNEL_SPT_CRE_MPF_E_OBJ		_KERNEL_SPT_E_OBJ	(_KERNEL_CFG_CRE_MPF_E_OBJ)
#define _KERNEL_SPT_CRE_MPF_E_NOMEM		_KERNEL_SPT_E_NOMEM	(_KERNEL_CFG_CRE_MPF_E_NOMEM)
#define _KERNEL_SPT_CRE_MPF_E_NOSPT		_KERNEL_SPT_E_NOSPT	(_KERNEL_CFG_CRE_MPF_E_NOSPT)

/* acre_mpf */
#define _KERNEL_SPT_ACRE_MPF_E_NOID		_KERNEL_SPT_E_NOID	(_KERNEL_CFG_ACRE_MPF_E_NOID)
#define _KERNEL_SPT_ACRE_MPF_E_RSATR 	_KERNEL_SPT_E_RSATR	(_KERNEL_CFG_ACRE_MPF_E_RSATR)
#define _KERNEL_SPT_ACRE_MPF_E_NOMEM	_KERNEL_SPT_E_NOMEM	(_KERNEL_CFG_ACRE_MPF_E_NOMEM)
#define _KERNEL_SPT_ACRE_MPF_E_NOSPT	_KERNEL_SPT_E_NOSPT	(_KERNEL_CFG_ACRE_MPF_E_NOSPT)

/* del_mpf */
#define _KERNEL_SPT_DEL_MPF_E_ID		_KERNEL_SPT_E_ID	(_KERNEL_CFG_DEL_MPF_E_ID)
#define _KERNEL_SPT_DEL_MPF_E_NOEXS		_KERNEL_SPT_E_NOEXS	(_KERNEL_CFG_DEL_MPF_E_NOEXS)
#define _KERNEL_SPT_DEL_MPF_E_NOSPT		_KERNEL_SPT_E_NOSPT	(_KERNEL_CFG_DEL_MPF_E_NOSPT)
                                                      
/* get_mpf */                                         
#define _KERNEL_SPT_GET_MPF_E_ID		_KERNEL_SPT_E_ID	(_KERNEL_CFG_GET_MPF_E_ID)
#define _KERNEL_SPT_GET_MPF_E_CTX		_KERNEL_SPT_E_CTX	(_KERNEL_CFG_GET_MPF_E_CTX)
#define _KERNEL_SPT_GET_MPF_E_NOEXS 	_KERNEL_SPT_E_NOEXS	(_KERNEL_CFG_GET_MPF_E_NOEXS)
#define _KERNEL_SPT_GET_MPF_E_PAR   	_KERNEL_SPT_E_PAR  	(_KERNEL_CFG_GET_MPF_E_PAR)
#define _KERNEL_SPT_GET_MPF_E_ILUSE 	_KERNEL_SPT_E_ILUSE	(_KERNEL_CFG_GET_MPF_E_ILUSE)
#define _KERNEL_SPT_GET_MPF_E_RLWAI 	_KERNEL_SPT_E_RLWAI	(_KERNEL_CFG_GET_MPF_E_RLWAI)
#define _KERNEL_SPT_GET_MPF_E_DLT   	_KERNEL_SPT_E_DLT  	(_KERNEL_CFG_GET_MPF_E_DLT)
#define _KERNEL_SPT_GET_MPF_E_NOSPT		_KERNEL_SPT_E_NOSPT	(_KERNEL_CFG_GET_MPF_E_NOSPT)

/* pget_mpf */
#define _KERNEL_SPT_PGET_MPF_E_ID		_KERNEL_SPT_E_ID	(_KERNEL_CFG_PGET_MPF_E_ID)
#define _KERNEL_SPT_PGET_MPF_E_CTX		_KERNEL_SPT_E_CTX	(_KERNEL_CFG_PGET_MPF_E_CTX)
#define _KERNEL_SPT_PGET_MPF_E_NOEXS	_KERNEL_SPT_E_NOEXS	(_KERNEL_CFG_PGET_MPF_E_NOEXS)
#define _KERNEL_SPT_PGET_MPF_E_PAR  	_KERNEL_SPT_E_PAR  	(_KERNEL_CFG_PGET_MPF_E_PAR)
#define _KERNEL_SPT_PGET_MPF_E_NOSPT	_KERNEL_SPT_E_NOSPT	(_KERNEL_CFG_PGET_MPF_E_NOSPT)

/* tget_mpf */
/* rel_mpf */
/* ref_mpf */


/* cre_mpl */
/* acre_mpl */
/* del_mpl */
/* get_mpl */
/* pget_mpl */
/* tget_mpl */
/* rel_mpl */
/* ref_mpl */


/* set_tim */
#define _KERNEL_SPT_SET_TIM_E_PAR		_KERNEL_SPT_E_PAR	(_KERNEL_CFG_SET_TIM_E_PAR)
#define _KERNEL_SPT_SET_TIM_E_NOSPT		_KERNEL_SPT_E_NOSPT	(_KERNEL_CFG_SET_TIM_E_NOSPT)

/* get_tim */
#define _KERNEL_SPT_GET_TIM_E_PAR		_KERNEL_SPT_E_PAR	(_KERNEL_CFG_GET_TIM_E_PAR)
#define _KERNEL_SPT_GET_TIM_E_NOSPT		_KERNEL_SPT_E_NOSPT	(_KERNEL_CFG_GET_TIM_E_NOSPT)

/* isig_tim */
#define _KERNEL_SPT_ISIG_TIM_E_NOSPT	_KERNEL_SPT_E_NOSPT	(_KERNEL_CFG_ISIG_TIM_E_NOSPT)



/* cre_cyc */
/* acre_cyc */
/* del_cyc */
/* sta_cyc */
/* stp_cyc */
/* ref_cyc */


/* cre_alm */
/* acre_alm */
/* del_alm */
/* sta_alm */
/* stp_alm */
/* ref_alm */


/* def_ovr */
/* sta_ovr */
/* stp_ovr */
/* ref_ovr */


/* rot_rdq */
/* irot_rdq */
/* get_tid */
/* iget_tid */
/* loc_cpu */
/* iloc_cpu */
/* unl_cpu */
/* ilnl_cpu */
/* dis_dsp */
/* ena_dsp */
/* sns_ctx */
/* sns_loc */
/* sns_dsp */
/* sns_dpn */
/* ref_sys */


/* def_inh */
/* cre_isr */
/* acre_isr */
/* del_isr */
/* ref_isr */
/* dis_int */
/* ena_int */
/* chg_ilv */
/* get_ilv */


/* def_svc */
/* cal_svc */


/* def_exc */
/* ref_cfg */
/* ref_ver */




#endif	/* _KERNEL__parser__parserr_h__ */


/* end of file */
