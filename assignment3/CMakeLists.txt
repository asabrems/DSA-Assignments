# Author: David Vernon
 
#Reduce warning level with cmake 2.6
IF(WIN32)
cmake_minimum_required(VERSION 2.6)
#disable annoying warnings about use of deprecated c functions
ADD_DEFINITIONS(-D_CRT_SECURE_NO_DEPRECATE)
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /NODEFAULTLIB:libc;libcmt.lib;libcmtd.lib") 
ELSE(WIN32)
cmake_minimum_required(VERSION 2.4)
ENDIF(WIN32)

##############################################
PROJECT(assignment3)
##############################################

SET(NESTED_BUILD TRUE)

SET(ADS_DIR ${PROJECT_SOURCE_DIR})
IF (NOT ADS_FOUND)
#Changing the default CMAKE_INSTALL_PREFIX
IF(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  SET(CMAKE_INSTALL_PREFIX "${ADS_DIR}" CACHE PATH "ADS install prefix" FORCE)
ENDIF(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
ENDIF (NOT ADS_FOUND)

SET(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})

SUBDIRS(src)