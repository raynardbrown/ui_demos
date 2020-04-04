cmake_minimum_required(VERSION 3.15.5)

# Set the name of the project and store it in a variable, PROJECT_NAME.
project(RowLayoutDemo)

# Require at least this version of boost
find_package(Boost 1.71.0)
if(NOT Boost_FOUND)
  message(FATAL_ERROR "boost not found")
endif()

set(Headers "")
list(APPEND Headers ${CMAKE_CURRENT_SOURCE_DIR}/inc)
list(APPEND Headers ${Boost_INCLUDE_DIRS})

################################################################################
# Source files and compiler options
################################################################################

set(Sources src/maingui.cpp)

if (MSVC)
    add_compile_options(-Zi
                        -W4
                        -EHsc
                        -D_CRT_SECURE_NO_WARNINGS
                        -DSTRICT
                        -DUNICODE
                        -D_UNICODE)
else()
    # fail until we target more platforms
    message(FATAL_ERROR "compiler not supported")
endif()

set(Libraries "")

################################################################################
# Graphics Library and Headers
################################################################################

find_library(GRAPHICS_LIBRARY graphics PATH_SUFFIXES graphics/build)

if(NOT GRAPHICS_LIBRARY)
  message(FATAL_ERROR "graphics library not found")
endif()

list(APPEND Libraries ${GRAPHICS_LIBRARY})

find_path(GRAPHICS_INCLUDE NAMES graphics/Color.h PATH_SUFFIXES graphics/inc)

if(NOT GRAPHICS_INCLUDE)
  message(FATAL_ERROR "graphics headers not found")
endif()

list(APPEND Headers ${GRAPHICS_INCLUDE})

################################################################################
# UI Library and Headers
################################################################################

find_library(UI_LIBRARY ui PATH_SUFFIXES ui/build)

if(NOT UI_LIBRARY)
  message(FATAL_ERROR "ui library not found")
endif()

list(APPEND Libraries ${UI_LIBRARY})

find_path(UI_INCLUDE NAMES ui/Window.h PATH_SUFFIXES ui/inc)

if(NOT UI_INCLUDE)
  message(FATAL_ERROR "ui headers not found")
endif()

list(APPEND Headers ${UI_INCLUDE})

################################################################################
# UI Layout Library and Headers
################################################################################

find_library(UI_LAYOUT_LIBRARY ui_layout PATH_SUFFIXES ui_layout/build)

if(NOT UI_LAYOUT_LIBRARY)
  message(FATAL_ERROR "ui layout library not found")
endif()

list(APPEND Libraries ${UI_LAYOUT_LIBRARY})

find_path(UI_LAYOUT_INCLUDE NAMES ui/layout/ILayout.h PATH_SUFFIXES ui_layout/inc)

if(NOT UI_LAYOUT_INCLUDE)
  message(FATAL_ERROR "ui layout headers not found")
endif()

list(APPEND Headers ${UI_LAYOUT_INCLUDE})

################################################################################
# String Extras Library
################################################################################

find_library(STRING_EXTRAS_LIBRARY string_extras PATH_SUFFIXES string_extras/build)

if(NOT STRING_EXTRAS_LIBRARY)
  message(FATAL_ERROR "string extras library not found")
endif()

list(APPEND Libraries ${STRING_EXTRAS_LIBRARY})

################################################################################
# Executable and its options
################################################################################

add_executable(${PROJECT_NAME} WIN32 ${Sources})

if (MSVC)
    target_link_options(${PROJECT_NAME} PRIVATE -SUBSYSTEM:WINDOWS
                                                -ENTRY:mainCRTStartup
                                                -INCREMENTAL:NO)
else()
    # fail until we target more platforms
    message(FATAL_ERROR "compiler not supported")
endif()

target_link_libraries(${PROJECT_NAME} ${Libraries})

target_include_directories(${PROJECT_NAME} PRIVATE ${Headers})