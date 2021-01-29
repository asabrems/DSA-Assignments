CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

#############################################
SET(MODULENAME dvernon)
#############################################

PROJECT(${MODULENAME})

FILE(GLOB folder_source *.cpp *.c )
FILE(GLOB folder_header *.h)

SOURCE_GROUP("Source Files" FILES ${folder_source})
SOURCE_GROUP("Header Files" FILES ${folder_header})

SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

ADD_EXECUTABLE(${MODULENAME} ${folder_source} ${folder_header}) 

INSTALL(TARGETS ${MODULENAME} DESTINATION bin) 