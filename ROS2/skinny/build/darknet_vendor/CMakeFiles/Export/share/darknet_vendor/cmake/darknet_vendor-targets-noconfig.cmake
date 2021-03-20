#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "darknet_vendor::darknet" for configuration ""
set_property(TARGET darknet_vendor::darknet APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(darknet_vendor::darknet PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libdarknet.so"
  IMPORTED_SONAME_NOCONFIG "libdarknet.so"
  )

list(APPEND _IMPORT_CHECK_TARGETS darknet_vendor::darknet )
list(APPEND _IMPORT_CHECK_FILES_FOR_darknet_vendor::darknet "${_IMPORT_PREFIX}/lib/libdarknet.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
