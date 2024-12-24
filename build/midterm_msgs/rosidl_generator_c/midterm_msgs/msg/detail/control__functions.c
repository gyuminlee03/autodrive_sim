// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from midterm_msgs:msg/Control.idl
// generated code does not contain a copyright notice
#include "midterm_msgs/msg/detail/control__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
midterm_msgs__msg__Control__init(midterm_msgs__msg__Control * msg)
{
  if (!msg) {
    return false;
  }
  // accel
  // steering
  return true;
}

void
midterm_msgs__msg__Control__fini(midterm_msgs__msg__Control * msg)
{
  if (!msg) {
    return;
  }
  // accel
  // steering
}

bool
midterm_msgs__msg__Control__are_equal(const midterm_msgs__msg__Control * lhs, const midterm_msgs__msg__Control * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accel
  if (lhs->accel != rhs->accel) {
    return false;
  }
  // steering
  if (lhs->steering != rhs->steering) {
    return false;
  }
  return true;
}

bool
midterm_msgs__msg__Control__copy(
  const midterm_msgs__msg__Control * input,
  midterm_msgs__msg__Control * output)
{
  if (!input || !output) {
    return false;
  }
  // accel
  output->accel = input->accel;
  // steering
  output->steering = input->steering;
  return true;
}

midterm_msgs__msg__Control *
midterm_msgs__msg__Control__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  midterm_msgs__msg__Control * msg = (midterm_msgs__msg__Control *)allocator.allocate(sizeof(midterm_msgs__msg__Control), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(midterm_msgs__msg__Control));
  bool success = midterm_msgs__msg__Control__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
midterm_msgs__msg__Control__destroy(midterm_msgs__msg__Control * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    midterm_msgs__msg__Control__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
midterm_msgs__msg__Control__Sequence__init(midterm_msgs__msg__Control__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  midterm_msgs__msg__Control * data = NULL;

  if (size) {
    data = (midterm_msgs__msg__Control *)allocator.zero_allocate(size, sizeof(midterm_msgs__msg__Control), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = midterm_msgs__msg__Control__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        midterm_msgs__msg__Control__fini(&data[i - 1]);
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
midterm_msgs__msg__Control__Sequence__fini(midterm_msgs__msg__Control__Sequence * array)
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
      midterm_msgs__msg__Control__fini(&array->data[i]);
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

midterm_msgs__msg__Control__Sequence *
midterm_msgs__msg__Control__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  midterm_msgs__msg__Control__Sequence * array = (midterm_msgs__msg__Control__Sequence *)allocator.allocate(sizeof(midterm_msgs__msg__Control__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = midterm_msgs__msg__Control__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
midterm_msgs__msg__Control__Sequence__destroy(midterm_msgs__msg__Control__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    midterm_msgs__msg__Control__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
midterm_msgs__msg__Control__Sequence__are_equal(const midterm_msgs__msg__Control__Sequence * lhs, const midterm_msgs__msg__Control__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!midterm_msgs__msg__Control__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
midterm_msgs__msg__Control__Sequence__copy(
  const midterm_msgs__msg__Control__Sequence * input,
  midterm_msgs__msg__Control__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(midterm_msgs__msg__Control);
    midterm_msgs__msg__Control * data =
      (midterm_msgs__msg__Control *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!midterm_msgs__msg__Control__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          midterm_msgs__msg__Control__fini(&data[i]);
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
    if (!midterm_msgs__msg__Control__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
