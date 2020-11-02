cmake_minimum_required(VERSION 2.8)
project (ui)

if(WIN32)
    set(CMAKE_WIN32_EXECUTABLE ON)
    set(UI_FRAMEWORK_DIR ${CMAKE_CURRENT_SOURCE_DIR}/ui_framework/win)
    set(UI_INCLUDE ${UI_FRAMEWORK_DIR})
    set(UI_LINK )
    set(UI_DEFS )
    set(UI_LIBS )
    file(WRITE depend.linkdirs ${CMAKE_CURRENT_SOURCE_DIR}/Release)
ELSE()
    set(UI_FRAMEWORK_DIR ${CMAKE_CURRENT_SOURCE_DIR}/ui_framework/gtk)
    find_package(PkgConfig REQUIRED)
    PKG_CHECK_MODULES(GTK3 REQUIRED gtk+-3.0)
    set(UI_INCLUDE
        ${GTK3_INCLUDE_DIRS}
        ${UI_FRAMEWORK_DIR}
    )
    set(UI_LINK ${GTK3_LIBRARY_DIRS})
    set(UI_DEFS ${GTK3_CFLAGS_OTHER})
    set(UI_LIBS ${GTK3_LIBRARIES})
ENDIF()

file(WRITE depend.includedirs ${CMAKE_CURRENT_SOURCE_DIR}\n)
foreach(inc ${UI_INCLUDE})
    file(APPEND depend.includedirs ${inc}\n)
endforeach()
file(WRITE depend.linkdirs ${CMAKE_CURRENT_SOURCE_DIR}\n)
foreach(inc ${UI_LINK})
    file(APPEND depend.linkdirs ${inc}\n)
endforeach()
file(WRITE depend.libs gui\n)
foreach(inc ${UI_LIBS})
    file(APPEND depend.libs ${inc}\n)
endforeach()
file(WRITE depend.defs "")
foreach(inc ${UI_DEFS})
    file(APPEND depend.defs ${inc}\n)
endforeach()

include_directories( ${UI_INCLUDE} )
link_directories( ${UI_LINK} )
add_definitions( ${UI_DEFS} )

add_library(gui STATIC
    ${UI_FRAMEWORK_DIR}/ui_framework/MWidget.cpp
    ${UI_FRAMEWORK_DIR}/ui_framework/MButton.cpp
    ${UI_FRAMEWORK_DIR}/ui_framework/MButtonBox.cpp
    ${UI_FRAMEWORK_DIR}/ui_framework/MTextBox.cpp
    ${UI_FRAMEWORK_DIR}/ui_framework/MWindow.cpp
    ${UI_FRAMEWORK_DIR}/ui_framework/MApplication.cpp
)

add_executable(testui testui.cpp)
target_link_libraries(
    testui
    gui
    ${UI_LIBS}
)
