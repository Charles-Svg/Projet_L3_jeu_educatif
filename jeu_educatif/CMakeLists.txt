cmake_minimum_required(VERSION 3.5)

project(jeu_educatif LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check https://doc.qt.io/qt/deployment-android.html for more information.
# They need to be set before the find_package( ...) calls below.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

set(PROJECT_SOURCES
        main.cpp

        mainwindow.cpp
        mainwindow.h

        desktop.cpp
        desktop.h

        abstractfile.cpp
        abstractfile.h

        abstractfileview.cpp
        abstractfileview.h

        file.cpp
        file.h

        fileview.cpp
        fileview.h

        filewindow.cpp
        filewindow.h

        directory.cpp
        directory.h

        directoryview.cpp
        directoryview.h

        evenements.cpp
        evenements.h

        ressources.qrc
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(jeu_educatif
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(jeu_educatif SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(jeu_educatif
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(jeu_educatif PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
