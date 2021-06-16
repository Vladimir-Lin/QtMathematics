NAME         = Mathematics
TARGET       = $${NAME}

QT           = core
QT          -= gui
QT          += QtCUDA
QT          += Essentials
QT          += QtGMP
QT          += QtGSL
QT          += QtAlgebra
QT          += QtDiscrete
QT          += QtFFT
QT          += QtDAI

load(qt_build_config)
load(qt_module)

INCLUDEPATH += $${PWD}/../../include/$${NAME}

HEADERS     += $${PWD}/../../include/$${NAME}/qtmathematics.h

include ($${PWD}/Basic/Basic.pri)

OTHER_FILES += $${PWD}/../../include/$${NAME}/headers.pri

include ($${PWD}/../../doc/Qt/Qt.pri)

win32 {
  CONFIG(debug,debug|release) {
    LIBS    += -lgslcblasd
    LIBS    += -lgsld
  } else {
    LIBS    += -lgslcblas
    LIBS    += -lgsl
  }
} else {
  CONFIG(debug,debug|release) {
    LIBS    += -lgslcblasd
    LIBS    += -lgsld
  } else {
    LIBS    += -lgslcblas
    LIBS    += -lgsl
  }
}

TRNAME       = $${NAME}
include ($${PWD}/../../Translations.pri)
