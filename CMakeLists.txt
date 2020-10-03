cmake_minimum_required(VERSION 2.8)
project (ui)

find_package(PkgConfig REQUIRED)
PKG_CHECK_MODULES(GTK3 REQUIRED gtk+-3.0)

include_directories(
    ${GTK3_INCLUDE_DIRS}
    gtk/
)
link_directories(
    ${GTK3_LIBRARY_DIRS}
)
add_definitions(
    ${GTK3_CFLAGS_OTHER}
)

add_library(gui STATIC
    gtk/ui_framework/MWidget.cpp
    gtk/ui_framework/MButton.cpp
    gtk/ui_framework/MButtonBox.cpp
    gtk/ui_framework/MWindow.cpp
    gtk/ui_framework/MApplication.cpp
)

add_executable(testui testui.cpp)
target_link_libraries(
    testui
    gui
    ${GTK3_LIBRARIES}
)
