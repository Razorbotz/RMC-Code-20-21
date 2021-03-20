
####### Expanded from @PACKAGE_INIT@ by configure_package_config_file() #######
####### Any changes to this file will be overwritten by the next CMake run ####
####### The input file was darknet_vendor-config.cmake.in                            ########

get_filename_component(PACKAGE_PREFIX_DIR "${CMAKE_CURRENT_LIST_DIR}/../../../" ABSOLUTE)

macro(set_and_check _var _file)
  set(${_var} "${_file}")
  if(NOT EXISTS "${_file}")
    message(FATAL_ERROR "File or directory ${_file} referenced by variable ${_var} does not exist !")
  endif()
endmacro()

macro(check_required_components _NAME)
  foreach(comp ${${_NAME}_FIND_COMPONENTS})
    if(NOT ${_NAME}_${comp}_FOUND)
      if(${_NAME}_FIND_REQUIRED_${comp})
        set(${_NAME}_FOUND FALSE)
      endif()
    endif()
  endforeach()
endmacro()

####################################################################################

find_package(Threads)

if(ON)
  find_package(OpenCV REQUIRED)
endif()

# Export targets for modern-style CMake code
if(NOT TARGET darknet_vendor::darknet_vendor)
  include("${PACKAGE_PREFIX_DIR}/share/darknet_vendor/cmake/darknet_vendor-targets.cmake")
endif()

# Set standard variables for old-style CMake code
set_and_check(darknet_vendor_INCLUDE_DIRS "${PACKAGE_PREFIX_DIR}/include")
set(darknet_vendor_LIBRARIES "darknet_vendor::darknet_vendor")
set_and_check(darknet_vendor_EXECUTABLE "${PACKAGE_PREFIX_DIR}/bin/darknet")
set(darknet_vendor_VERSION_MAJOR "0")
set(darknet_vendor_VERSION_MINOR "1")
set(darknet_vendor_VERSION_PATCH "0")
