# Copyright: (C) 2015 icub facility
# Authors: Marco Randazzo
# CopyPolicy: Released under the terms of the GNU GPL v2.0.

project(trajectoryPlayer)
set(PROJECTNAME trajectoryPlayer)

file(GLOB folder_source *.cpp)
file(GLOB folder_header *.h)
source_group("Source Files" FILES ${folder_source})
source_group("Header Files" FILES ${folder_header})

include_directories(${YARP_INCLUDE_DIRS})
add_executable(${PROJECTNAME} ${folder_source} ${folder_header})
target_link_libraries(${PROJECTNAME} ${YARP_LIBRARIES})
install(TARGETS ${PROJECTNAME} DESTINATION bin)