# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.16.3)

# We name the project and the target for the ExternalProject_Add() call
# to something that will highlight to the user what we are working on if
# something goes wrong and an error message is produced.

project(darknet-download-populate NONE)

include(ExternalProject)
ExternalProject_Add(darknet-download-populate
                     "UPDATE_DISCONNECTED" "False" "GIT_REPOSITORY" "https://github.com/tiagoshibata/darknet" "GIT_TAG" "795e5ac1ebee56dac1f792938a9698604e9e4638"
                    SOURCE_DIR          "/root/skinny/build/darknet_vendor/_deps/darknet-download-src"
                    BINARY_DIR          "/root/skinny/build/darknet_vendor/_deps/darknet-download-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
                    USES_TERMINAL_DOWNLOAD  YES
                    USES_TERMINAL_UPDATE    YES
)
