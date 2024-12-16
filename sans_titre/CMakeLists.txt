cmake_minimum_required(VERSION 3.16)

project(sans_titre VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Recherche de Qt, incluant le module Qt Data Visualization
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets DataVisualization)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets DataVisualization)

set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
)

# Création de l'exécutable en fonction de la version de Qt
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(sans_titre
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(sans_titre SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(sans_titre
            ${PROJECT_SOURCES}
        )
    endif()
endif()

# Lier l'exécutable avec les bibliothèques Qt nécessaires
target_link_libraries(sans_titre PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::DataVisualization)

# Qt pour iOS définit automatiquement MACOSX_BUNDLE_GUI_IDENTIFIER depuis Qt 6.1.0
if(${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.sans_titre)
endif()

set_target_properties(sans_titre PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

# Installation de l'exécutable et des fichiers associés
include(GNUInstallDirs)
install(TARGETS sans_titre
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Finaliser l'exécutable si nous utilisons Qt 6
if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(sans_titre)
endif()
