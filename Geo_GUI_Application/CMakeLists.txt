cmake_minimum_required(VERSION 2.8.11)

project(Geo_App_Gui)

# init_qt: Let's do the CMake job for us
set(CMAKE_AUTOMOC ON) # For meta object compiler
set(CMAKE_AUTORCC ON) # Resource files

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Find the QtWidgets library
find_package(Qt5 COMPONENTS Widgets Core Gui REQUIRED)
find_package(VTK REQUIRED)
find_package(PCL REQUIRED)
add_definitions(${QT_DEFINITIONS})
FIND_PROGRAM(QT_QMAKE_EXECUTABLE NAMES qmake qmake5 qmake-qt5 qmake-mac
   DOC "The qmake executable for the Qt installation to use")
# Fix a compilation bug under ubuntu 16.04 (Xenial)
include_directories(${PCL_INCLUDE_DIRS})

add_definitions(${PCL_DEFINITIONS})


set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++0x")




#-------------------------------------------------
#
# Project created by QtCreator 2019-02-18T18:25:15
#
#-------------------------------------------------

#QT       += core gui

#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#TARGET = Geo_GUI_Application
#TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
#DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


set(SOURCES 
        main.cpp 
        mainwindow.cpp 
    gagraphicsview.cpp 
    customelipse.cpp 
    projectmanager.cpp)

set ( MOC_HEADERS
 mainwindow.h
)

set ( UIS
 mainwindow.ui
)

set ( RESOURCES
 assets.qrc
)

qt5_wrap_ui(ui_wrap ${UIS})
qt5_wrap_cpp(moc_sources ${MOC_HEADERS})
#include_directory(.)
include( ${VTK_USE_FILE} )
include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})
add_executable(Geo_GUI_Application ${SOURCES} ${RESOURCES} ${ui_wrap} ${moc_sources})
target_link_libraries (Geo_GUI_Application Qt5::Core Qt5::Widgets Qt5::Gui)
qt5_use_modules(Geo_GUI_Application Core Gui Widgets)

#FORMS += \
 #       mainwindow.ui

# Default rules for deployment.
#qnx: target.path = /tmp/$${TARGET}/bin
#else: unix:!android: target.path = /opt/$${TARGET}/bin
#!isEmpty(target.path): INSTALLS += target

#RESOURCES += \
 #   assets.qrc




