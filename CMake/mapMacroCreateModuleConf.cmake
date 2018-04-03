###################################################################
#
# MAP_CREATE_MODULE_CONF 
# 
# This can be called in a similar way like MAP_CREATE_MODULE
# but it just creates the module configuration files without
# actually building it. It is used for integration of legacy libraries
# into the MatchPoint module build system
#
##################################################################
MACRO(MAP_CREATE_MODULE_CONF MODULE_NAME_IN)
  MACRO_PARSE_ARGUMENTS(MODULE "INCLUDE_DIRS;DEPENDS;PROVIDES" "QT_MODULE;HEADERS_ONLY" ${ARGN})
  SET(MODULE_NAME ${MODULE_NAME_IN})
  SET(MODULE_IS_ENABLED 1)
  _MAP_CREATE_MODULE_CONF()
ENDMACRO(MAP_CREATE_MODULE_CONF)

MACRO(_MAP_CREATE_MODULE_CONF)
    IF(NOT MODULE_PROVIDES AND NOT MODULE_HEADERS_ONLY)
      SET(MODULE_PROVIDES ${MODULE_NAME})
    ENDIF(NOT MODULE_PROVIDES AND NOT MODULE_HEADERS_ONLY)
    SET(MODULE_INCLUDE_DIRS_ABSOLUTE "")
    FOREACH(dir ${MODULE_INCLUDE_DIRS})
      GET_FILENAME_COMPONENT(abs_dir ${dir} ABSOLUTE)
      SET(MODULE_INCLUDE_DIRS_ABSOLUTE ${MODULE_INCLUDE_DIRS_ABSOLUTE} ${abs_dir})
    ENDFOREACH(dir)

    SET(MODULE_INCLUDE_DIRS ${MODULE_INCLUDE_DIRS_ABSOLUTE} ${CMAKE_CURRENT_SOURCE_DIR})
    
    IF (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/source)
      SET(MODULE_INCLUDE_DIRS ${MODULE_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/source)
    ENDIF()

    IF (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/include)
      SET(MODULE_INCLUDE_DIRS ${MODULE_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/include)
    ENDIF()

    IF (EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/boxed)
      SET(MODULE_INCLUDE_DIRS ${MODULE_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/boxed)
    ENDIF()

    CONFIGURE_FILE(${MatchPoint_SOURCE_DIR}/CMake/moduleConf.cmake.in ${MAP_MODULES_CONF_DIR}/${MODULE_NAME}Config.cmake @ONLY)
ENDMACRO(_MAP_CREATE_MODULE_CONF)
