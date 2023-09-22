QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#QMAKE_CXXFLAGS += -Wa,-mbig-obj

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Controller/controller.cc \
    Model/calculator.cc \
    Model/financecalculator.cc \
    Model/graphplotter.cc \
    View/credit_window.cc \
    View/graph_window.cc \
    View/mainwindow.cc \
    main.cc \
    qcustomplot.cc

HEADERS += \
    Controller/controller.h \
    Model/calculator.h \
    Model/financecalculator.h \
    Model/graphplotter.h \
    View/credit_window.h \
    View/graph_window.h \
    View/mainwindow.h \
    qcustomplot.h

FORMS += \
    View/credit_window.ui \
    View/graph_window.ui \
    View/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
