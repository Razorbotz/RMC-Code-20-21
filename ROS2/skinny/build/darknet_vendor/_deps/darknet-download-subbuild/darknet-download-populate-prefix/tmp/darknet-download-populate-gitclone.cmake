
if(NOT "/root/skinny/build/darknet_vendor/_deps/darknet-download-subbuild/darknet-download-populate-prefix/src/darknet-download-populate-stamp/darknet-download-populate-gitinfo.txt" IS_NEWER_THAN "/root/skinny/build/darknet_vendor/_deps/darknet-download-subbuild/darknet-download-populate-prefix/src/darknet-download-populate-stamp/darknet-download-populate-gitclone-lastrun.txt")
  message(STATUS "Avoiding repeated git clone, stamp file is up to date: '/root/skinny/build/darknet_vendor/_deps/darknet-download-subbuild/darknet-download-populate-prefix/src/darknet-download-populate-stamp/darknet-download-populate-gitclone-lastrun.txt'")
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E remove_directory "/root/skinny/build/darknet_vendor/_deps/darknet-download-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: '/root/skinny/build/darknet_vendor/_deps/darknet-download-src'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "/usr/bin/git"  clone --no-checkout "https://github.com/tiagoshibata/darknet" "darknet-download-src"
    WORKING_DIRECTORY "/root/skinny/build/darknet_vendor/_deps"
    RESULT_VARIABLE error_code
    )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once:
          ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/tiagoshibata/darknet'")
endif()

execute_process(
  COMMAND "/usr/bin/git"  checkout 795e5ac1ebee56dac1f792938a9698604e9e4638 --
  WORKING_DIRECTORY "/root/skinny/build/darknet_vendor/_deps/darknet-download-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: '795e5ac1ebee56dac1f792938a9698604e9e4638'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "/usr/bin/git"  submodule update --recursive --init 
    WORKING_DIRECTORY "/root/skinny/build/darknet_vendor/_deps/darknet-download-src"
    RESULT_VARIABLE error_code
    )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: '/root/skinny/build/darknet_vendor/_deps/darknet-download-src'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy
    "/root/skinny/build/darknet_vendor/_deps/darknet-download-subbuild/darknet-download-populate-prefix/src/darknet-download-populate-stamp/darknet-download-populate-gitinfo.txt"
    "/root/skinny/build/darknet_vendor/_deps/darknet-download-subbuild/darknet-download-populate-prefix/src/darknet-download-populate-stamp/darknet-download-populate-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: '/root/skinny/build/darknet_vendor/_deps/darknet-download-subbuild/darknet-download-populate-prefix/src/darknet-download-populate-stamp/darknet-download-populate-gitclone-lastrun.txt'")
endif()

