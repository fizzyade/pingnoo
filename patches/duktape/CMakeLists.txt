#
# Copyright (C) 2020 Adrian Carpenter
#
# This file is part of fontawesome for qt (https://github.com/nedrysoft/FontAwesomeForQt)
#
# A cross-platform library for using FontAwesome glyphs in Qt applications.
#
# Created by Adrian Carpenter on 03/12/2020.
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#

cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

#file(MAKE_DIRECTORY download)
#file(MAKE_DIRECTORY extracted)
#file(DOWNLOAD https:/duktape.org/duktape-2.6.0.tar.xz duktape.tar.xz)
#file(ARCHIVE_EXTRACT INPUT duktape.tar.xz DESTINATION . PATTERNS duktape-2.6.0/*/*)
#file(RENAME extracted/duktape-2.6.0/ .)

#set(CMAKE_AUTORCC ON)

#ADD_DEFINITIONS(-DQT_NO_KEYWORDS)

#ADD_DEFINITIONS(-DNEDRYSOFT_LIBRARY_FONTAWESOME_EXPORT)

# create the font awesome library

project(duktape)

set(library_SOURCES
    src/duktape.c
    src/duktape.h
    )

#set(Qt_LIBS Qt5::Core Qt5::Widgets)

add_library(${PROJECT_NAME} SHARED
    ${library_SOURCES}
)

if(DEFINED NEDRYSOFT_DUKTAPE_LIBRARY_DIR)
    message(STATUS "LIBRARY_OUTPUT_DIRECTORY is set to ${LIBRARY_OUTPUT_DIRECTORY}")
    message(STATUS "RUNTIME_OUTPUT_DIRECTORY is set to ${RUNTIME_OUTPUT_DIRECTORY}")
    set_target_properties(${PROJECT_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${NEDRYSOFT_DUKTAPE_LIBRARY_DIR}")
    set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${NEDRYSOFT_DUKTAPE_LIBRARY_DIR}")
else()
    message(STATUS "Set NEDRYSOFT_DUKTAPE_LIBRARY_DIR to set the binary output dir.")
endif()

#target_link_libraries(${PROJECT_NAME} ${Qt_LIBS})
