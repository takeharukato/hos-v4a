# ----------------------------------------------------------------------------
#  Hyper Operating System V4 Advance
#
#  Copyright (C) 1998-2006 by Project HOS
#  http://sourceforge.jp/projects/hos/
# ----------------------------------------------------------------------------


# %jp{特殊文字定義}
comma:= ,
empty:=
space:= $(empty) $(empty)



# %jp{実行ファイル生成}%en{Executable file}
$(TARGET_EXE): $(OBJS) $(LIBS)
	$(CMD_RM) -f $(TARGET_EXE)
	$(CMD_ECHO) "-rom D=R"                                            > $(OBJS_DIR)/linksub.txt
	$(CMD_ECHO) "-list $(TARGET).map"                                >> $(OBJS_DIR)/linksub.txt
	$(CMD_ECHO) "-SHow SY,R,X"                                       >> $(OBJS_DIR)/linksub.txt
	$(CMD_ECHO) "-Input=$(subst $(space),$(comma),$(strip $(OBJS)))" >> $(OBJS_DIR)/linksub.txt
	$(CMD_ECHO) "-LIB=$(subst $(space),$(comma),$(strip $(LIBS)))"   >> $(OBJS_DIR)/linksub.txt
	$(CMD_ECHO) "-start=VECTTBL/$(SECTION_VECT),P,C,C\$$BSEC,C\$$DSEC,D/$(SECTION_ROM),B,R,S/$(SECTION_RAM)" >> $(OBJS_DIR)/linksub.txt
	$(CMD_ECHO) "-output=$(TARGET_EXE)"                              >> $(OBJS_DIR)/linksub.txt
	$(CMD_LINK) -SU=$(OBJS_DIR)/linksub.txt


# %jp{モトローラS形式ファイル生成}%en{Motorola S format file}
$(TARGET_MOT): $(TARGET_EXE)
	$(CMD_ECHO) "-input=$(TARGET_EXE)"     > $(OBJS_DIR)/ascsub.txt
	$(CMD_ECHO) "-form stype"             >> $(OBJS_DIR)/ascsub.txt
	$(CMD_ECHO) "-output $(TARGET_MOT)"   >> $(OBJS_DIR)/ascsub.txt
	$(CMD_OBJCNV) -SU=$(OBJS_DIR)/ascsub.txt


# %jp{ライブラリ生成}
$(TARGET_LIB): $(OBJS)
	$(CMD_RM) -f $(TARGET_LIB)
	$(CMD_ECHO) "-Input=$(subst $(space),$(comma),$(strip $(OBJS)))" > $(OBJS_DIR)/subcmd.txt
	$(CMD_ECHO) "-OUtput=$(TARGET_LIB)"                             >> $(OBJS_DIR)/subcmd.txt
	$(CMD_ECHO) "-FOrm=Library"                                     >> $(OBJS_DIR)/subcmd.txt
	$(CMD_LIBR) "-SU=$(OBJS_DIR)/subcmd.txt"


# %jp{Cコンパイル}
$(OBJS_DIR)/%.obj :: %.c
	$(CMD_CC) $(CFLAGS) $< -OB=$@ -List=$(@:%.obj=%.lst)


# %jp{アセンブル}
$(OBJS_DIR)/%.obj :: %.src
	$(CMD_ASM) $(AFLAGS) $< -OB=$@



# end of file