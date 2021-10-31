TEMPLATE = app
TARGET = svcquery
CONFIG = c++11
DEFINES =
INCLUDEPATH =

HEADERS += \
    SvcEntry.h \
    SvcList.h \
    SvcQuery.h

SOURCES += \
    0Temp.cpp \
    SvcEntry.cpp \
    SvcList.cpp \
    SvcQuery.cpp \
    main.cpp \

DISTFILES += \
    install.sh \
    meson.build \
    Readme.txt \


