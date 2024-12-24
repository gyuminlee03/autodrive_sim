// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from midterm_msgs:msg/SimpleLidar.idl
// generated code does not contain a copyright notice

#ifndef MIDTERM_MSGS__MSG__DETAIL__SIMPLE_LIDAR__FUNCTIONS_H_
#define MIDTERM_MSGS__MSG__DETAIL__SIMPLE_LIDAR__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "midterm_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "midterm_msgs/msg/detail/simple_lidar__struct.h"

/// Initialize msg/SimpleLidar message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * midterm_msgs__msg__SimpleLidar
 * )) before or use
 * midterm_msgs__msg__SimpleLidar__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_midterm_msgs
bool
midterm_msgs__msg__SimpleLidar__init(midterm_msgs__msg__SimpleLidar * msg);

/// Finalize msg/SimpleLidar message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_midterm_msgs
void
midterm_msgs__msg__SimpleLidar__fini(midterm_msgs__msg__SimpleLidar * msg);

/// Create msg/SimpleLidar message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * midterm_msgs__msg__SimpleLidar__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_midterm_msgs
midterm_msgs__msg__SimpleLidar *
midterm_msgs__msg__SimpleLidar__create();

/// Destroy msg/SimpleLidar message.
/**
 * It calls
 * midterm_msgs__msg__SimpleLidar__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_midterm_msgs
void
midterm_msgs__msg__SimpleLidar__destroy(midterm_msgs__msg__SimpleLidar * msg);

/// Check for msg/SimpleLidar message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_midterm_msgs
bool
midterm_msgs__msg__SimpleLidar__are_equal(const midterm_msgs__msg__SimpleLidar * lhs, const midterm_msgs__msg__SimpleLidar * rhs);

/// Copy a msg/SimpleLidar message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_midterm_msgs
bool
midterm_msgs__msg__SimpleLidar__copy(
  const midterm_msgs__msg__SimpleLidar * input,
  midterm_msgs__msg__SimpleLidar * output);

/// Initialize array of msg/SimpleLidar messages.
/**
 * It allocates the memory for the number of elements and calls
 * midterm_msgs__msg__SimpleLidar__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_midterm_msgs
bool
midterm_msgs__msg__SimpleLidar__Sequence__init(midterm_msgs__msg__SimpleLidar__Sequence * array, size_t size);

/// Finalize array of msg/SimpleLidar messages.
/**
 * It calls
 * midterm_msgs__msg__SimpleLidar__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_midterm_msgs
void
midterm_msgs__msg__SimpleLidar__Sequence__fini(midterm_msgs__msg__SimpleLidar__Sequence * array);

/// Create array of msg/SimpleLidar messages.
/**
 * It allocates the memory for the array and calls
 * midterm_msgs__msg__SimpleLidar__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_midterm_msgs
midterm_msgs__msg__SimpleLidar__Sequence *
midterm_msgs__msg__SimpleLidar__Sequence__create(size_t size);

/// Destroy array of msg/SimpleLidar messages.
/**
 * It calls
 * midterm_msgs__msg__SimpleLidar__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_midterm_msgs
void
midterm_msgs__msg__SimpleLidar__Sequence__destroy(midterm_msgs__msg__SimpleLidar__Sequence * array);

/// Check for msg/SimpleLidar message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_midterm_msgs
bool
midterm_msgs__msg__SimpleLidar__Sequence__are_equal(const midterm_msgs__msg__SimpleLidar__Sequence * lhs, const midterm_msgs__msg__SimpleLidar__Sequence * rhs);

/// Copy an array of msg/SimpleLidar messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_midterm_msgs
bool
midterm_msgs__msg__SimpleLidar__Sequence__copy(
  const midterm_msgs__msg__SimpleLidar__Sequence * input,
  midterm_msgs__msg__SimpleLidar__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // MIDTERM_MSGS__MSG__DETAIL__SIMPLE_LIDAR__FUNCTIONS_H_
