// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from messages:msg/ZedPosition.idl
// generated code does not contain a copyright notice

#ifndef MESSAGES__MSG__ZED_POSITION__FUNCTIONS_H_
#define MESSAGES__MSG__ZED_POSITION__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_generator_c/visibility_control.h"
#include "messages/msg/rosidl_generator_c__visibility_control.h"

#include "messages/msg/zed_position__struct.h"

/// Initialize msg/ZedPosition message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * messages__msg__ZedPosition
 * )) before or use
 * messages__msg__ZedPosition__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_messages
bool
messages__msg__ZedPosition__init(messages__msg__ZedPosition * msg);

/// Finalize msg/ZedPosition message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_messages
void
messages__msg__ZedPosition__fini(messages__msg__ZedPosition * msg);

/// Create msg/ZedPosition message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * messages__msg__ZedPosition__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_messages
messages__msg__ZedPosition *
messages__msg__ZedPosition__create();

/// Destroy msg/ZedPosition message.
/**
 * It calls
 * messages__msg__ZedPosition__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_messages
void
messages__msg__ZedPosition__destroy(messages__msg__ZedPosition * msg);


/// Initialize array of msg/ZedPosition messages.
/**
 * It allocates the memory for the number of elements and calls
 * messages__msg__ZedPosition__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_messages
bool
messages__msg__ZedPosition__Sequence__init(messages__msg__ZedPosition__Sequence * array, size_t size);

/// Finalize array of msg/ZedPosition messages.
/**
 * It calls
 * messages__msg__ZedPosition__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_messages
void
messages__msg__ZedPosition__Sequence__fini(messages__msg__ZedPosition__Sequence * array);

/// Create array of msg/ZedPosition messages.
/**
 * It allocates the memory for the array and calls
 * messages__msg__ZedPosition__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_messages
messages__msg__ZedPosition__Sequence *
messages__msg__ZedPosition__Sequence__create(size_t size);

/// Destroy array of msg/ZedPosition messages.
/**
 * It calls
 * messages__msg__ZedPosition__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_messages
void
messages__msg__ZedPosition__Sequence__destroy(messages__msg__ZedPosition__Sequence * array);

#ifdef __cplusplus
}
#endif

#endif  // MESSAGES__MSG__ZED_POSITION__FUNCTIONS_H_
