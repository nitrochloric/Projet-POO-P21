QT       += core gui datavisualization

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    src/addition.cpp \
    src/carre.cpp \
    src/cst.cpp \
    src/division.cpp \
    src/expression.cpp \
    src/inverse.cpp \
    src/log_neperien.cpp \
    src/multiplication.cpp \
    src/operateur.cpp \
    src/oppose.cpp \
    src/racine_carre.cpp \
    src/sauvegarde.cpp \
    src/soustraction.cpp \
    src/terminal.cpp \
    src/valeur_absolue.cpp

HEADERS += \
    include/addition.h \
    include/carre.h \
    include/cst.h \
    include/division.h \
    include/expression.h \
    include/inverse.h \
    include/log_neperien.h \
    include/multiplication.h \
    include/operateur.h \
    include/oppose.h \
    include/racine_carre.h \
    include/sauvegarde.h \
    include/soustraction.h \
    include/table_symboles.h \
    include/terminal.h \
    include/valeur_absolue.h \
    include/variable.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
