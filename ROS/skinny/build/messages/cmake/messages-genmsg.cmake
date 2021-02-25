# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "messages: 8 messages, 0 services")

set(MSG_I_FLAGS "-Imessages:/home/team/SoftwareDevelopment/ROS/src/messages/msg;-Istd_msgs:/opt/ros/melodic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(messages_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/team/SoftwareDevelopment/ROS/src/messages/msg/HatState.msg" NAME_WE)
add_custom_target(_messages_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "messages" "/home/team/SoftwareDevelopment/ROS/src/messages/msg/HatState.msg" ""
)

get_filename_component(_filename "/home/team/SoftwareDevelopment/ROS/src/messages/msg/Power.msg" NAME_WE)
add_custom_target(_messages_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "messages" "/home/team/SoftwareDevelopment/ROS/src/messages/msg/Power.msg" ""
)

get_filename_component(_filename "/home/team/SoftwareDevelopment/ROS/src/messages/msg/VictorOut.msg" NAME_WE)
add_custom_target(_messages_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "messages" "/home/team/SoftwareDevelopment/ROS/src/messages/msg/VictorOut.msg" ""
)

get_filename_component(_filename "/home/team/SoftwareDevelopment/ROS/src/messages/msg/ButtonState.msg" NAME_WE)
add_custom_target(_messages_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "messages" "/home/team/SoftwareDevelopment/ROS/src/messages/msg/ButtonState.msg" ""
)

get_filename_component(_filename "/home/team/SoftwareDevelopment/ROS/src/messages/msg/AxisState.msg" NAME_WE)
add_custom_target(_messages_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "messages" "/home/team/SoftwareDevelopment/ROS/src/messages/msg/AxisState.msg" ""
)

get_filename_component(_filename "/home/team/SoftwareDevelopment/ROS/src/messages/msg/Camera.msg" NAME_WE)
add_custom_target(_messages_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "messages" "/home/team/SoftwareDevelopment/ROS/src/messages/msg/Camera.msg" ""
)

get_filename_component(_filename "/home/team/SoftwareDevelopment/ROS/src/messages/msg/TalonOut.msg" NAME_WE)
add_custom_target(_messages_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "messages" "/home/team/SoftwareDevelopment/ROS/src/messages/msg/TalonOut.msg" ""
)

get_filename_component(_filename "/home/team/SoftwareDevelopment/ROS/src/messages/msg/KeyState.msg" NAME_WE)
add_custom_target(_messages_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "messages" "/home/team/SoftwareDevelopment/ROS/src/messages/msg/KeyState.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(messages
  "/home/team/SoftwareDevelopment/ROS/src/messages/msg/HatState.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/messages
)
_generate_msg_cpp(messages
  "/home/team/SoftwareDevelopment/ROS/src/messages/msg/Power.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/messages
)
_generate_msg_cpp(messages
  "/home/team/SoftwareDevelopment/ROS/src/messages/msg/VictorOut.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/messages
)
_generate_msg_cpp(messages
  "/home/team/SoftwareDevelopment/ROS/src/messages/msg/ButtonState.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/messages
)
_generate_msg_cpp(messages
  "/home/team/SoftwareDevelopment/ROS/src/messages/msg/AxisState.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/messages
)
_generate_msg_cpp(messages
  "/home/team/SoftwareDevelopment/ROS/src/messages/msg/Camera.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/messages
)
_generate_msg_cpp(messages
  "/home/team/SoftwareDevelopment/ROS/src/messages/msg/TalonOut.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/messages
)
_generate_msg_cpp(messages
  "/home/team/SoftwareDevelopment/ROS/src/messages/msg/KeyState.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/messages
)

### Generating Services

### Generating Module File
_generate_module_cpp(messages
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/messages
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(messages_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(messages_generate_messages messages_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/team/SoftwareDevelopment/ROS/src/messages/msg/HatState.msg" NAME_WE)
add_dependencies(messages_generate_messages_cpp _messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/team/SoftwareDevelopment/ROS/src/messages/msg/Power.msg" NAME_WE)
add_dependencies(messages_generate_messages_cpp _messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/team/SoftwareDevelopment/ROS/src/messages/msg/VictorOut.msg" NAME_WE)
add_dependencies(messages_generate_messages_cpp _messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/team/SoftwareDevelopment/ROS/src/messages/msg/ButtonState.msg" NAME_WE)
add_dependencies(messages_generate_messages_cpp _messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/team/SoftwareDevelopment/ROS/src/messages/msg/AxisState.msg" NAME_WE)
add_dependencies(messages_generate_messages_cpp _messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/team/SoftwareDevelopment/ROS/src/messages/msg/Camera.msg" NAME_WE)
add_dependencies(messages_generate_messages_cpp _messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/team/SoftwareDevelopment/ROS/src/messages/msg/TalonOut.msg" NAME_WE)
add_dependencies(messages_generate_messages_cpp _messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/team/SoftwareDevelopment/ROS/src/messages/msg/KeyState.msg" NAME_WE)
add_dependencies(messages_generate_messages_cpp _messages_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(messages_gencpp)
add_dependencies(messages_gencpp messages_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS messages_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(messages
  "/home/team/SoftwareDevelopment/ROS/src/messages/msg/HatState.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/messages
)
_generate_msg_eus(messages
  "/home/team/SoftwareDevelopment/ROS/src/messages/msg/Power.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/messages
)
_generate_msg_eus(messages
  "/home/team/SoftwareDevelopment/ROS/src/messages/msg/VictorOut.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/messages
)
_generate_msg_eus(messages
  "/home/team/SoftwareDevelopment/ROS/src/messages/msg/ButtonState.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/messages
)
_generate_msg_eus(messages
  "/home/team/SoftwareDevelopment/ROS/src/messages/msg/AxisState.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/messages
)
_generate_msg_eus(messages
  "/home/team/SoftwareDevelopment/ROS/src/messages/msg/Camera.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/messages
)
_generate_msg_eus(messages
  "/home/team/SoftwareDevelopment/ROS/src/messages/msg/TalonOut.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/messages
)
_generate_msg_eus(messages
  "/home/team/SoftwareDevelopment/ROS/src/messages/msg/KeyState.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/messages
)

### Generating Services

### Generating Module File
_generate_module_eus(messages
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/messages
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(messages_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(messages_generate_messages messages_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/team/SoftwareDevelopment/ROS/src/messages/msg/HatState.msg" NAME_WE)
add_dependencies(messages_generate_messages_eus _messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/team/SoftwareDevelopment/ROS/src/messages/msg/Power.msg" NAME_WE)
add_dependencies(messages_generate_messages_eus _messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/team/SoftwareDevelopment/ROS/src/messages/msg/VictorOut.msg" NAME_WE)
add_dependencies(messages_generate_messages_eus _messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/team/SoftwareDevelopment/ROS/src/messages/msg/ButtonState.msg" NAME_WE)
add_dependencies(messages_generate_messages_eus _messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/team/SoftwareDevelopment/ROS/src/messages/msg/AxisState.msg" NAME_WE)
add_dependencies(messages_generate_messages_eus _messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/team/SoftwareDevelopment/ROS/src/messages/msg/Camera.msg" NAME_WE)
add_dependencies(messages_generate_messages_eus _messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/team/SoftwareDevelopment/ROS/src/messages/msg/TalonOut.msg" NAME_WE)
add_dependencies(messages_generate_messages_eus _messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/team/SoftwareDevelopment/ROS/src/messages/msg/KeyState.msg" NAME_WE)
add_dependencies(messages_generate_messages_eus _messages_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(messages_geneus)
add_dependencies(messages_geneus messages_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS messages_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(messages
  "/home/team/SoftwareDevelopment/ROS/src/messages/msg/HatState.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/messages
)
_generate_msg_lisp(messages
  "/home/team/SoftwareDevelopment/ROS/src/messages/msg/Power.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/messages
)
_generate_msg_lisp(messages
  "/home/team/SoftwareDevelopment/ROS/src/messages/msg/VictorOut.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/messages
)
_generate_msg_lisp(messages
  "/home/team/SoftwareDevelopment/ROS/src/messages/msg/ButtonState.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/messages
)
_generate_msg_lisp(messages
  "/home/team/SoftwareDevelopment/ROS/src/messages/msg/AxisState.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/messages
)
_generate_msg_lisp(messages
  "/home/team/SoftwareDevelopment/ROS/src/messages/msg/Camera.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/messages
)
_generate_msg_lisp(messages
  "/home/team/SoftwareDevelopment/ROS/src/messages/msg/TalonOut.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/messages
)
_generate_msg_lisp(messages
  "/home/team/SoftwareDevelopment/ROS/src/messages/msg/KeyState.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/messages
)

### Generating Services

### Generating Module File
_generate_module_lisp(messages
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/messages
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(messages_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(messages_generate_messages messages_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/team/SoftwareDevelopment/ROS/src/messages/msg/HatState.msg" NAME_WE)
add_dependencies(messages_generate_messages_lisp _messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/team/SoftwareDevelopment/ROS/src/messages/msg/Power.msg" NAME_WE)
add_dependencies(messages_generate_messages_lisp _messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/team/SoftwareDevelopment/ROS/src/messages/msg/VictorOut.msg" NAME_WE)
add_dependencies(messages_generate_messages_lisp _messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/team/SoftwareDevelopment/ROS/src/messages/msg/ButtonState.msg" NAME_WE)
add_dependencies(messages_generate_messages_lisp _messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/team/SoftwareDevelopment/ROS/src/messages/msg/AxisState.msg" NAME_WE)
add_dependencies(messages_generate_messages_lisp _messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/team/SoftwareDevelopment/ROS/src/messages/msg/Camera.msg" NAME_WE)
add_dependencies(messages_generate_messages_lisp _messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/team/SoftwareDevelopment/ROS/src/messages/msg/TalonOut.msg" NAME_WE)
add_dependencies(messages_generate_messages_lisp _messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/team/SoftwareDevelopment/ROS/src/messages/msg/KeyState.msg" NAME_WE)
add_dependencies(messages_generate_messages_lisp _messages_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(messages_genlisp)
add_dependencies(messages_genlisp messages_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS messages_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(messages
  "/home/team/SoftwareDevelopment/ROS/src/messages/msg/HatState.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/messages
)
_generate_msg_nodejs(messages
  "/home/team/SoftwareDevelopment/ROS/src/messages/msg/Power.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/messages
)
_generate_msg_nodejs(messages
  "/home/team/SoftwareDevelopment/ROS/src/messages/msg/VictorOut.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/messages
)
_generate_msg_nodejs(messages
  "/home/team/SoftwareDevelopment/ROS/src/messages/msg/ButtonState.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/messages
)
_generate_msg_nodejs(messages
  "/home/team/SoftwareDevelopment/ROS/src/messages/msg/AxisState.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/messages
)
_generate_msg_nodejs(messages
  "/home/team/SoftwareDevelopment/ROS/src/messages/msg/Camera.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/messages
)
_generate_msg_nodejs(messages
  "/home/team/SoftwareDevelopment/ROS/src/messages/msg/TalonOut.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/messages
)
_generate_msg_nodejs(messages
  "/home/team/SoftwareDevelopment/ROS/src/messages/msg/KeyState.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/messages
)

### Generating Services

### Generating Module File
_generate_module_nodejs(messages
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/messages
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(messages_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(messages_generate_messages messages_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/team/SoftwareDevelopment/ROS/src/messages/msg/HatState.msg" NAME_WE)
add_dependencies(messages_generate_messages_nodejs _messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/team/SoftwareDevelopment/ROS/src/messages/msg/Power.msg" NAME_WE)
add_dependencies(messages_generate_messages_nodejs _messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/team/SoftwareDevelopment/ROS/src/messages/msg/VictorOut.msg" NAME_WE)
add_dependencies(messages_generate_messages_nodejs _messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/team/SoftwareDevelopment/ROS/src/messages/msg/ButtonState.msg" NAME_WE)
add_dependencies(messages_generate_messages_nodejs _messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/team/SoftwareDevelopment/ROS/src/messages/msg/AxisState.msg" NAME_WE)
add_dependencies(messages_generate_messages_nodejs _messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/team/SoftwareDevelopment/ROS/src/messages/msg/Camera.msg" NAME_WE)
add_dependencies(messages_generate_messages_nodejs _messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/team/SoftwareDevelopment/ROS/src/messages/msg/TalonOut.msg" NAME_WE)
add_dependencies(messages_generate_messages_nodejs _messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/team/SoftwareDevelopment/ROS/src/messages/msg/KeyState.msg" NAME_WE)
add_dependencies(messages_generate_messages_nodejs _messages_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(messages_gennodejs)
add_dependencies(messages_gennodejs messages_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS messages_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(messages
  "/home/team/SoftwareDevelopment/ROS/src/messages/msg/HatState.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/messages
)
_generate_msg_py(messages
  "/home/team/SoftwareDevelopment/ROS/src/messages/msg/Power.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/messages
)
_generate_msg_py(messages
  "/home/team/SoftwareDevelopment/ROS/src/messages/msg/VictorOut.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/messages
)
_generate_msg_py(messages
  "/home/team/SoftwareDevelopment/ROS/src/messages/msg/ButtonState.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/messages
)
_generate_msg_py(messages
  "/home/team/SoftwareDevelopment/ROS/src/messages/msg/AxisState.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/messages
)
_generate_msg_py(messages
  "/home/team/SoftwareDevelopment/ROS/src/messages/msg/Camera.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/messages
)
_generate_msg_py(messages
  "/home/team/SoftwareDevelopment/ROS/src/messages/msg/TalonOut.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/messages
)
_generate_msg_py(messages
  "/home/team/SoftwareDevelopment/ROS/src/messages/msg/KeyState.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/messages
)

### Generating Services

### Generating Module File
_generate_module_py(messages
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/messages
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(messages_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(messages_generate_messages messages_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/team/SoftwareDevelopment/ROS/src/messages/msg/HatState.msg" NAME_WE)
add_dependencies(messages_generate_messages_py _messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/team/SoftwareDevelopment/ROS/src/messages/msg/Power.msg" NAME_WE)
add_dependencies(messages_generate_messages_py _messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/team/SoftwareDevelopment/ROS/src/messages/msg/VictorOut.msg" NAME_WE)
add_dependencies(messages_generate_messages_py _messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/team/SoftwareDevelopment/ROS/src/messages/msg/ButtonState.msg" NAME_WE)
add_dependencies(messages_generate_messages_py _messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/team/SoftwareDevelopment/ROS/src/messages/msg/AxisState.msg" NAME_WE)
add_dependencies(messages_generate_messages_py _messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/team/SoftwareDevelopment/ROS/src/messages/msg/Camera.msg" NAME_WE)
add_dependencies(messages_generate_messages_py _messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/team/SoftwareDevelopment/ROS/src/messages/msg/TalonOut.msg" NAME_WE)
add_dependencies(messages_generate_messages_py _messages_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/team/SoftwareDevelopment/ROS/src/messages/msg/KeyState.msg" NAME_WE)
add_dependencies(messages_generate_messages_py _messages_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(messages_genpy)
add_dependencies(messages_genpy messages_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS messages_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/messages)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/messages
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(messages_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/messages)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/messages
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(messages_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/messages)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/messages
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(messages_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/messages)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/messages
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(messages_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/messages)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/messages\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/messages
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(messages_generate_messages_py std_msgs_generate_messages_py)
endif()
