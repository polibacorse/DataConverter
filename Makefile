#############################################################################
# Makefile for building: DataConverter
# Generated by qmake (3.0) (Qt 5.7.1)
# Project:  DataConverter.pro
# Template: app
# Command: /usr/lib/arm-linux-gnueabihf/qt5/bin/qmake -o Makefile DataConverter.pro
#############################################################################

MAKEFILE      = Makefile

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_CORE_LIB
CFLAGS        = -pipe -O2 -Wall -W -D_REENTRANT -fPIC $(DEFINES)
CXXFLAGS      = -pipe -O2 -std=gnu++11 -Wall -W -D_REENTRANT -fPIC $(DEFINES)
INCPATH       = -I. -isystem /usr/include/arm-linux-gnueabihf/qt5 -isystem /usr/include/arm-linux-gnueabihf/qt5/QtCore -I. -I/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/linux-g++
QMAKE         = /usr/lib/arm-linux-gnueabihf/qt5/bin/qmake
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
INSTALL_FILE  = install -m 644 -p
INSTALL_PROGRAM = install -m 755 -p
INSTALL_DIR   = cp -f -R
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
TAR           = tar -cf
COMPRESS      = gzip -9f
DISTNAME      = DataConverter1.0.0
DISTDIR = /home/pi/2-dataconverter/.tmp/DataConverter1.0.0
LINK          = g++
LFLAGS        = -Wl,-O1
LIBS          = $(SUBLIBS) -L/home/pi/2-dataconverter/../../../../usr/lib64/ -lmosquitto -lQt5Core -lpthread 
AR            = ar cqs
RANLIB        = 
SED           = sed
STRIP         = strip

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		mosquittotransceiver.cpp \
		mosquittotransceiversingleton.cpp \
		dataconverter.cpp moc_mosquittotransceiver.cpp \
		moc_dataconverter.cpp
OBJECTS       = main.o \
		mosquittotransceiver.o \
		mosquittotransceiversingleton.o \
		dataconverter.o \
		moc_mosquittotransceiver.o \
		moc_dataconverter.o
DIST          = /usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/spec_pre.prf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/common/unix.conf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/common/linux.conf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/common/sanitize.conf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/common/gcc-base.conf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/common/gcc-base-unix.conf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/common/g++-base.conf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/common/g++-unix.conf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/qconfig.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_eglfs_device_lib_private.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_platformsupport_private.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_qml.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_qmltest.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_quick.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_quickwidgets.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/qt_functions.prf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/qt_config.prf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/linux-g++/qmake.conf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/spec_post.prf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/toolchain.prf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/default_pre.prf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/resolve_config.prf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/default_post.prf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/warn_on.prf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/qt.prf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/resources.prf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/moc.prf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/unix/thread.prf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/file_copies.prf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/testcase_targets.prf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/exceptions.prf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/yacc.prf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/lex.prf \
		DataConverter.pro mosquittotransceiver.h \
		mosquittotransceiversingleton.h \
		dataconverter.h main.cpp \
		mosquittotransceiver.cpp \
		mosquittotransceiversingleton.cpp \
		dataconverter.cpp
QMAKE_TARGET  = DataConverter
DESTDIR       = 
TARGET        = DataConverter


first: all
####### Build rules

$(TARGET):  $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: DataConverter.pro /usr/lib/arm-linux-gnueabihf/qt5/mkspecs/linux-g++/qmake.conf /usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/spec_pre.prf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/common/unix.conf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/common/linux.conf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/common/sanitize.conf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/common/gcc-base.conf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/common/gcc-base-unix.conf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/common/g++-base.conf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/common/g++-unix.conf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/qconfig.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_eglfs_device_lib_private.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_platformsupport_private.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_qml.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_qmltest.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_quick.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_quickwidgets.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/qt_functions.prf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/qt_config.prf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/linux-g++/qmake.conf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/spec_post.prf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/toolchain.prf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/default_pre.prf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/resolve_config.prf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/default_post.prf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/warn_on.prf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/qt.prf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/resources.prf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/moc.prf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/unix/thread.prf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/file_copies.prf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/testcase_targets.prf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/exceptions.prf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/yacc.prf \
		/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/lex.prf \
		DataConverter.pro \
		/usr/lib/arm-linux-gnueabihf/libQt5Core.prl
	$(QMAKE) -o Makefile DataConverter.pro
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/spec_pre.prf:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/common/unix.conf:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/common/linux.conf:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/common/sanitize.conf:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/common/gcc-base.conf:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/common/gcc-base-unix.conf:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/common/g++-base.conf:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/common/g++-unix.conf:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/qconfig.pri:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_concurrent.pri:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_concurrent_private.pri:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_core.pri:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_core_private.pri:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_dbus.pri:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_dbus_private.pri:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_eglfs_device_lib_private.pri:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_gui.pri:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_gui_private.pri:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_network.pri:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_network_private.pri:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_opengl.pri:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_opengl_private.pri:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_openglextensions.pri:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_platformsupport_private.pri:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_printsupport.pri:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_printsupport_private.pri:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_qml.pri:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_qmltest.pri:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_quick.pri:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_quickwidgets.pri:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_sql.pri:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_sql_private.pri:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_testlib.pri:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_testlib_private.pri:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_widgets.pri:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_widgets_private.pri:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_xml.pri:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/modules/qt_lib_xml_private.pri:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/qt_functions.prf:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/qt_config.prf:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/linux-g++/qmake.conf:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/spec_post.prf:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/exclusive_builds.prf:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/toolchain.prf:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/default_pre.prf:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/resolve_config.prf:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/default_post.prf:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/warn_on.prf:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/qt.prf:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/resources.prf:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/moc.prf:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/unix/thread.prf:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/file_copies.prf:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/testcase_targets.prf:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/exceptions.prf:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/yacc.prf:
/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/features/lex.prf:
DataConverter.pro:
/usr/lib/arm-linux-gnueabihf/libQt5Core.prl:
qmake: FORCE
	@$(QMAKE) -o Makefile DataConverter.pro

qmake_all: FORCE


all: Makefile $(TARGET)

dist: distdir FORCE
	(cd `dirname $(DISTDIR)` && $(TAR) $(DISTNAME).tar $(DISTNAME) && $(COMPRESS) $(DISTNAME).tar) && $(MOVE) `dirname $(DISTDIR)`/$(DISTNAME).tar.gz . && $(DEL_FILE) -r $(DISTDIR)

distdir: FORCE
	@test -d $(DISTDIR) || mkdir -p $(DISTDIR)
	$(COPY_FILE) --parents $(DIST) $(DISTDIR)/
	$(COPY_FILE) --parents mosquittotransceiver.h mosquittotransceiversingleton.h dataconverter.h $(DISTDIR)/
	$(COPY_FILE) --parents main.cpp mosquittotransceiver.cpp mosquittotransceiversingleton.cpp dataconverter.cpp $(DISTDIR)/


clean: compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


distclean: clean 
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) .qmake.stash
	-$(DEL_FILE) Makefile


####### Sub-libraries

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

check: first

benchmark: first

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_moc_header_make_all: moc_mosquittotransceiver.cpp moc_dataconverter.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mosquittotransceiver.cpp moc_dataconverter.cpp
moc_mosquittotransceiver.cpp: mosquittotransceiver.h \
		/usr/lib/arm-linux-gnueabihf/qt5/bin/moc
	/usr/lib/arm-linux-gnueabihf/qt5/bin/moc $(DEFINES) -I/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/linux-g++ -I/home/pi/2-dataconverter -I/usr/include/arm-linux-gnueabihf/qt5 -I/usr/include/arm-linux-gnueabihf/qt5/QtCore -I/usr/include/c++/6 -I/usr/include/arm-linux-gnueabihf/c++/6 -I/usr/include/c++/6/backward -I/usr/lib/gcc/arm-linux-gnueabihf/6/include -I/usr/local/include -I/usr/lib/gcc/arm-linux-gnueabihf/6/include-fixed -I/usr/include/arm-linux-gnueabihf -I/usr/include mosquittotransceiver.h -o moc_mosquittotransceiver.cpp

moc_dataconverter.cpp: mosquittotransceiver.h \
		dataconverter.h \
		/usr/lib/arm-linux-gnueabihf/qt5/bin/moc
	/usr/lib/arm-linux-gnueabihf/qt5/bin/moc $(DEFINES) -I/usr/lib/arm-linux-gnueabihf/qt5/mkspecs/linux-g++ -I/home/pi/2-dataconverter -I/usr/include/arm-linux-gnueabihf/qt5 -I/usr/include/arm-linux-gnueabihf/qt5/QtCore -I/usr/include/c++/6 -I/usr/include/arm-linux-gnueabihf/c++/6 -I/usr/include/c++/6/backward -I/usr/lib/gcc/arm-linux-gnueabihf/6/include -I/usr/local/include -I/usr/lib/gcc/arm-linux-gnueabihf/6/include-fixed -I/usr/include/arm-linux-gnueabihf -I/usr/include dataconverter.h -o moc_dataconverter.cpp

compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean 

####### Compile

main.o: main.cpp dataconverter.h \
		mosquittotransceiver.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mosquittotransceiver.o: mosquittotransceiver.cpp mosquittotransceiver.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mosquittotransceiver.o mosquittotransceiver.cpp

mosquittotransceiversingleton.o: mosquittotransceiversingleton.cpp mosquittotransceiversingleton.h \
		mosquittotransceiver.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mosquittotransceiversingleton.o mosquittotransceiversingleton.cpp

dataconverter.o: dataconverter.cpp dataconverter.h \
		mosquittotransceiver.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o dataconverter.o dataconverter.cpp

moc_mosquittotransceiver.o: moc_mosquittotransceiver.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mosquittotransceiver.o moc_mosquittotransceiver.cpp

moc_dataconverter.o: moc_dataconverter.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_dataconverter.o moc_dataconverter.cpp

####### Install

install:  FORCE

uninstall:  FORCE

FORCE:

