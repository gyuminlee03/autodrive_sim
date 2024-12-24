// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from midterm_msgs:msg/SimpleLidar.idl
// generated code does not contain a copyright notice
#include "midterm_msgs/msg/detail/simple_lidar__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `beams`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
midterm_msgs__msg__SimpleLidar__init(midterm_msgs__msg__SimpleLidar * msg)
{
  if (!msg) {
    return false;
  }
  // beams
  if (!rosidl_runtime_c__float__Sequence__init(&msg->beams, 0)) {
    midterm_msgs__msg__SimpleLidar__fini(msg);
    return false;
  }
  return true;
}

void
midterm_msgs__msg__SimpleLidar__fini(midterm_msgs__msg__SimpleLidar * msg)
{
  if (!msg) {
    return;
  }
  // beams
  rosidl_runtime_c__float__Sequence__fini(&msg->beams);
}

bool
midterm_msgs__msg__SimpleLidar__are_equal(const midterm_msgs__msg__SimpleLidar * lhs, const midterm_msgs__msg__SimpleLidar * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // beams
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->beams), &(rhs->beams)))
  {
    return false;
  }
  return true;
}

bool
midterm_msgs__msg__SimpleLidar__copy(
  const midterm_msgs__msg__SimpleLidar * input,
  midterm_msgs__msg__SimpleLidar * output)
{
  if (!input || !output) {
    return false;
  }
  // beams
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->beams), &(output->beams)))
  {
    return false;
  }
  return true;
}

midterm_msgs__msg__SimpleLidar *
midterm_msgs__msg__SimpleLidar__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  midterm_msgs__msg__SimpleLidar * msg = (midterm_msgs__msg__SimpleLidar *)allocator.allocate(sizeof(midterm_msgs__msg__SimpleLidar), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(midterm_msgs__msg__SimpleLidar));
  bool success = midterm_msgs__msg__SimpleLidar__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
midterm_msgs__msg__SimpleLidar__destroy(midterm_msgs__msg__SimpleLidar * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    midterm_msgs__msg__SimpleLidar__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
midterm_msgs__msg__SimpleLidar__Sequence__init(midterm_msgs__msg__SimpleLidar__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  midterm_msgs__msg__SimpleLidar * data = NULL;

  if (size) {
    data = (midterm_msgs__msg__SimpleLidar *)allocator.zero_allocate(size, sizeof(midterm_msgs__msg__SimpleLidar), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = midterm_msgs__msg__SimpleLidar__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        midterm_msgs__msg__SimpleLidar__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
midterm_msgs__msg__SimpleLidar__Sequence__fini(midterm_msgs__msg__SimpleLidar__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      midterm_msgs__msg__SimpleLidar__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

midterm_msgs__msg__SimpleLidar__Sequence *
midterm_msgs__msg__SimpleLidar__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  midterm_msgs__msg__SimpleLidar__Sequence * array = (midterm_msgs__msg__SimpleLidar__Sequence *)allocator.allocate(sizeof(midterm_msgs__msg__SimpleLidar__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = midterm_msgs__msg__SimpleLidar__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
midterm_msgs__msg__SimpleLidar__Sequence__destroy(midterm_msgs__msg__SimpleLidar__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    midterm_msgs__msg__SimpleLidar__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
midterm_msgs__msg__SimpleLidar__Sequence__are_equal(const midterm_msgs__msg__SimpleLidar__Sequence * lhs, const midterm_msgs__msg__SimpleLidar__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!midterm_msgs__msg__SimpleLidar__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
midterm_msgs__msg__SimpleLidar__Sequence__copy(
  const midterm_msgs__msg__SimpleLidar__Sequence * input,
  midterm_msgs__msg__SimpleLidar__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(midterm_msgs__msg__SimpleLidar);
    midterm_msgs__msg__SimpleLidar * data =
      (midterm_msgs__msg__SimpleLidar *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!midterm_msgs__msg__SimpleLidar__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          midterm_msgs__msg__SimpleLidar__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!midterm_msgs__msg__SimpleLidar__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
