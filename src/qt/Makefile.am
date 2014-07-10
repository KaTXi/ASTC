include $(top_srcdir)/src/Makefile.include

AM_CPPFLAGS += -I$(top_srcdir)/src \
  -I$(top_builddir)/src/qt \
  -I$(top_builddir)/src/qt/forms \
  $(PROTOBUF_CFLAGS) \
  $(QR_CFLAGS)
bin_PROGRAMS = asturcoin-qt
noinst_LIBRARIES = libasturcoinqt.a
SUBDIRS = $(BUILD_TEST_QT)
DIST_SUBDIRS = test

# asturcoin qt core #
QT_TS = \
  locale/asturcoin_ach.ts \
  locale/asturcoin_af_ZA.ts \
  locale/asturcoin_ar.ts \
  locale/asturcoin_be_BY.ts \
  locale/asturcoin_bg.ts \
  locale/asturcoin_bs.ts \
  locale/asturcoin_ca_ES.ts \
  locale/asturcoin_ca.ts \
  locale/asturcoin_ca@valencia.ts \
  locale/asturcoin_cmn.ts \
  locale/asturcoin_cs.ts \
  locale/asturcoin_cy.ts \
  locale/asturcoin_da.ts \
  locale/asturcoin_de_AT.ts \
  locale/asturcoin_de.ts \
  locale/asturcoin_el_GR.ts \
  locale/asturcoin_en.ts \
  locale/asturcoin_eo.ts \
  locale/asturcoin_es_CL.ts \
  locale/asturcoin_es_DO.ts \
  locale/asturcoin_es_MX.ts \
  locale/asturcoin_es.ts \
  locale/asturcoin_es_UY.ts \
  locale/asturcoin_et.ts \
  locale/asturcoin_eu_ES.ts \
  locale/asturcoin_fa_IR.ts \
  locale/asturcoin_fa.ts \
  locale/asturcoin_fi.ts \
  locale/asturcoin_fr_CA.ts \
  locale/asturcoin_fr.ts \
  locale/asturcoin_gl.ts \
  locale/asturcoin_gu_IN.ts \
  locale/asturcoin_he.ts \
  locale/asturcoin_hi_IN.ts \
  locale/asturcoin_hr.ts \
  locale/asturcoin_hu.ts \
  locale/asturcoin_id_ID.ts \
  locale/asturcoin_it.ts \
  locale/asturcoin_ja.ts \
  locale/asturcoin_ka.ts \
  locale/asturcoin_kk_KZ.ts \
  locale/asturcoin_ko_KR.ts \
  locale/asturcoin_ky.ts \
  locale/asturcoin_la.ts \
  locale/asturcoin_lt.ts \
  locale/asturcoin_lv_LV.ts \
  locale/asturcoin_ms_MY.ts \
  locale/asturcoin_nb.ts \
  locale/asturcoin_nl.ts \
  locale/asturcoin_pam.ts \
  locale/asturcoin_pl.ts \
  locale/asturcoin_pt_BR.ts \
  locale/asturcoin_pt_PT.ts \
  locale/asturcoin_ro_RO.ts \
  locale/asturcoin_ru.ts \
  locale/asturcoin_sah.ts \
  locale/asturcoin_sk.ts \
  locale/asturcoin_sl_SI.ts \
  locale/asturcoin_sq.ts \
  locale/asturcoin_sr.ts \
  locale/asturcoin_sv.ts \
  locale/asturcoin_th_TH.ts \
  locale/asturcoin_tr.ts \
  locale/asturcoin_uk.ts \
  locale/asturcoin_ur_PK.ts \
  locale/asturcoin_uz@Cyrl.ts \
  locale/asturcoin_vi.ts \
  locale/asturcoin_vi_VN.ts \
  locale/asturcoin_zh_CN.ts \
  locale/asturcoin_zh_HK.ts \
  locale/asturcoin_zh_TW.ts

QT_FORMS_UI = \
  forms/aboutdialog.ui \
  forms/addressbookpage.ui \
  forms/askpassphrasedialog.ui \
  forms/coincontroldialog.ui \
  forms/editaddressdialog.ui \
  forms/helpmessagedialog.ui \
  forms/intro.ui \
  forms/openuridialog.ui \
  forms/optionsdialog.ui \
  forms/overviewpage.ui \
  forms/receivecoinsdialog.ui \
  forms/receiverequestdialog.ui \
  forms/rpcconsole.ui \
  forms/sendcoinsdialog.ui \
  forms/utildialog.ui \
  forms/sendcoinsentry.ui \
  forms/signverifymessagedialog.ui \
  forms/transactiondescdialog.ui

QT_MOC_CPP = \
  moc_addressbookpage.cpp \
  moc_addresstablemodel.cpp \
  moc_askpassphrasedialog.cpp \
  moc_asturcoinaddressvalidator.cpp \
  moc_asturcoinamountfield.cpp \
  moc_asturcoingui.cpp \
  moc_asturcoinunits.cpp \
  moc_clientmodel.cpp \
  moc_coincontroldialog.cpp \
  moc_coincontroltreewidget.cpp \
  moc_csvmodelwriter.cpp \
  moc_editaddressdialog.cpp \
  moc_guiutil.cpp \
  moc_intro.cpp \
  moc_macdockiconhandler.cpp \
  moc_macnotificationhandler.cpp \
  moc_monitoreddatamapper.cpp \
  moc_notificator.cpp \
  moc_openuridialog.cpp \
  moc_optionsdialog.cpp \
  moc_optionsmodel.cpp \
  moc_overviewpage.cpp \
  moc_paymentserver.cpp \
  moc_qvalidatedlineedit.cpp \
  moc_qvaluecombobox.cpp \
  moc_receivecoinsdialog.cpp \
  moc_receiverequestdialog.cpp \
  moc_recentrequeststablemodel.cpp \
  moc_rpcconsole.cpp \
  moc_sendcoinsdialog.cpp \
  moc_utildialog.cpp \
  moc_sendcoinsentry.cpp \
  moc_signverifymessagedialog.cpp \
  moc_splashscreen.cpp \
  moc_trafficgraphwidget.cpp \
  moc_transactiondesc.cpp \
  moc_transactiondescdialog.cpp \
  moc_transactionfilterproxy.cpp \
  moc_transactiontablemodel.cpp \
  moc_transactionview.cpp \
  moc_utilitydialog.cpp \
  moc_walletframe.cpp \
  moc_walletmodel.cpp \
  moc_walletview.cpp

ASTURCOIN_MM = \
  macdockiconhandler.mm \
  macnotificationhandler.mm

QT_MOC = \
  asturcoin.moc \
  intro.moc \
  overviewpage.moc \
  rpcconsole.moc

QT_QRC_CPP = qrc_asturcoin.cpp
QT_QRC = asturcoin.qrc

PROTOBUF_CC = paymentrequest.pb.cc
PROTOBUF_H = paymentrequest.pb.h
PROTOBUF_PROTO = paymentrequest.proto

ASTURCOIN_QT_H = \
  addressbookpage.h \
  addresstablemodel.h \
  askpassphrasedialog.h \
  asturcoinaddressvalidator.h \
  asturcoinamountfield.h \
  asturcoingui.h \
  asturcoinunits.h \
  clientmodel.h \
  coincontroldialog.h \
  coincontroltreewidget.h \
  csvmodelwriter.h \
  editaddressdialog.h \
  guiconstants.h \
  guiutil.h \
  intro.h \
  macdockiconhandler.h \
  macnotificationhandler.h \
  monitoreddatamapper.h \
  notificator.h \
  openuridialog.h \
  optionsdialog.h \
  optionsmodel.h \
  overviewpage.h \
  paymentrequestplus.h \
  paymentserver.h \
  qvalidatedlineedit.h \
  qvaluecombobox.h \
  receivecoinsdialog.h \
  receiverequestdialog.h \
  recentrequeststablemodel.h \
  rpcconsole.h \
  sendcoinsdialog.h \
  utildialog.h \
  sendcoinsentry.h \
  signverifymessagedialog.h \
  splashscreen.h \
  trafficgraphwidget.h \
  transactiondesc.h \
  transactiondescdialog.h \
  transactionfilterproxy.h \
  transactionrecord.h \
  transactiontablemodel.h \
  transactionview.h \
  utilitydialog.h \
  walletframe.h \
  walletmodel.h \
  walletmodeltransaction.h \
  walletview.h

RES_ICONS = \
  res/icons/add.png \
  res/icons/address-book.png \
  res/icons/asturcoin.ico \
  res/icons/asturcoin.png \
  res/icons/asturcoin_testnet.ico \
  res/icons/asturcoin_testnet.png \
  res/icons/clock1.png \
  res/icons/clock2.png \
  res/icons/clock3.png \
  res/icons/clock4.png \
  res/icons/clock5.png \
  res/icons/configure.png \
  res/icons/connect0_16.png \
  res/icons/connect1_16.png \
  res/icons/connect2_16.png \
  res/icons/connect3_16.png \
  res/icons/connect4_16.png \
  res/icons/debugwindow.png \
  res/icons/edit.png \
  res/icons/editcopy.png \
  res/icons/editpaste.png \
  res/icons/export.png \
  res/icons/filesave.png \
  res/icons/history.png \
  res/icons/key.png \
  res/icons/lock_closed.png \
  res/icons/lock_open.png \
  res/icons/overview.png \
  res/icons/qrcode.png \
  res/icons/quit.png \
  res/icons/receive.png \
  res/icons/remove.png \
  res/icons/send.png \
  res/icons/synced.png \
  res/icons/toolbar.png \
  res/icons/toolbar_testnet.png \
  res/icons/transaction0.png \
  res/icons/transaction2.png \
  res/icons/transaction_conflicted.png \
  res/icons/tx_inout.png \
  res/icons/tx_input.png \
  res/icons/tx_output.png \
  res/icons/tx_mined.png

ASTURCOIN_QT_CPP = \
  asturcoin.cpp \
  asturcoinaddressvalidator.cpp \
  asturcoinamountfield.cpp \
  asturcoingui.cpp \
  asturcoinunits.cpp \
  clientmodel.cpp \
  csvmodelwriter.cpp \
  guiutil.cpp \
  intro.cpp \
  monitoreddatamapper.cpp \
  notificator.cpp \
  optionsdialog.cpp \
  optionsmodel.cpp \
  qvalidatedlineedit.cpp \
  qvaluecombobox.cpp \
  rpcconsole.cpp \
  signverifymessagedialog.cpp \
  splashscreen.cpp \
  trafficgraphwidget.cpp \
  utilitydialog.cpp

if ENABLE_WALLET
ASTURCOIN_QT_CPP += \
  addressbookpage.cpp \
  addresstablemodel.cpp \
  askpassphrasedialog.cpp \
  coincontroldialog.cpp \
  coincontroltreewidget.cpp \
  editaddressdialog.cpp \
  openuridialog.cpp \
  overviewpage.cpp \
  paymentrequestplus.cpp \
  paymentserver.cpp \
  receivecoinsdialog.cpp \
  receiverequestdialog.cpp \
  recentrequeststablemodel.cpp \
  sendcoinsdialog.cpp \
  utildialog.cpp \
  sendcoinsentry.cpp \
  transactiondesc.cpp \
  transactiondescdialog.cpp \
  transactionfilterproxy.cpp \
  transactionrecord.cpp \
  transactiontablemodel.cpp \
  transactionview.cpp \
  walletframe.cpp \
  walletmodel.cpp \
  walletmodeltransaction.cpp \
  walletview.cpp
endif

RES_IMAGES = \
  res/images/about.png \
  res/images/splash.png \
  res/images/splash_testnet.png \
  res/images/wallet_bgcoin.png

RES_MOVIES = $(wildcard res/movies/spinner-*.png)

ASTURCOIN_RC = res/asturcoin-qt-res.rc

libasturcoinqt_a_CPPFLAGS = $(AM_CPPFLAGS) $(QT_INCLUDES) \
  -I$(top_srcdir)/src/qt/forms $(QT_DBUS_INCLUDES)
libasturcoinqt_a_SOURCES = $(ASTURCOIN_QT_CPP) $(ASTURCOIN_QT_H) $(QT_FORMS_UI) \
  $(QT_QRC) $(QT_TS) $(PROTOBUF_PROTO) $(RES_ICONS) $(RES_IMAGES) $(RES_MOVIES)

nodist_libasturcoinqt_a_SOURCES = $(QT_MOC_CPP) $(QT_MOC) $(PROTOBUF_CC) \
  $(PROTOBUF_H) $(QT_QRC_CPP)

BUILT_SOURCES = $(nodist_libasturcoinqt_a_SOURCES)

#Generating these with a half-written protobuf header leads to wacky results.
#This makes sure it's done.
$(QT_MOC): $(PROTOBUF_H)
$(QT_MOC_CPP): $(PROTOBUF_H)

# asturcoin-qt binary #
asturcoin_qt_CPPFLAGS = $(AM_CPPFLAGS) $(QT_INCLUDES) \
  -I$(top_srcdir)/src/qt/forms
asturcoin_qt_SOURCES = asturcoin.cpp
if TARGET_DARWIN
  asturcoin_qt_SOURCES += $(ASTURCOIN_MM)
endif
if TARGET_WINDOWS
  asturcoin_qt_SOURCES += $(ASTURCOIN_RC)
endif
asturcoin_qt_LDADD = libasturcoinqt.a $(LIBASTURCOIN_SERVER)
if ENABLE_WALLET
asturcoin_qt_LDADD += $(LIBASTURCOIN_WALLET) $(LIBASTURCOIN_SERVER_WALLET)
endif
asturcoin_qt_LDADD += $(LIBASTURCOIN_CLI) $(LIBASTURCOIN_COMMON) $(LIBLEVELDB) $(LIBMEMENV) \
  $(BOOST_LIBS) $(QT_LIBS) $(QT_DBUS_LIBS) $(QR_LIBS) $(PROTOBUF_LIBS) $(BDB_LIBS)
asturcoin_qt_LDFLAGS = $(QT_LDFLAGS)

# forms/foo.h -> forms/ui_foo.h
QT_FORMS_H=$(join $(dir $(QT_FORMS_UI)),$(addprefix ui_, $(notdir $(QT_FORMS_UI:.ui=.h))))

#locale/foo.ts -> locale/foo.qm
QT_QM=$(QT_TS:.ts=.qm)

.PHONY: FORCE
.SECONDARY: $(QT_QM)

asturcoinstrings.cpp: FORCE
	$(MAKE) -C $(top_srcdir)/src qt/asturcoinstrings.cpp

translate: asturcoinstrings.cpp $(QT_FORMS_UI) $(QT_FORMS_UI) $(ASTURCOIN_QT_CPP) $(ASTURCOIN_QT_H) $(ASTURCOIN_MM)
	@test -n $(LUPDATE) || echo "lupdate is required for updating translations"
	@QT_SELECT=$(QT_SELECT) $(LUPDATE) $^ -locations relative -no-obsolete -ts locale/asturcoin_en.ts

$(QT_QRC_CPP): $(QT_QRC) $(QT_QM) $(QT_FORMS_H) $(RES_ICONS) $(RES_IMAGES) $(RES_MOVIES) $(PROTOBUF_H)
	@cd $(abs_srcdir); test -f $(RCC) && QT_SELECT=$(QT_SELECT) $(RCC) -name asturcoin -o $(abs_builddir)/$@ $< || \
	  echo error: could not build $@
	$(SED) -i.bak -e '/^\*\*.*Created:/d' $@ && rm -f $@.bak
	$(SED) -i.bak -e '/^\*\*.*by:/d' $@ && rm -f $@.bak

CLEANFILES = $(BUILT_SOURCES) $(QT_QM) $(QT_FORMS_H) *.gcda *.gcno
