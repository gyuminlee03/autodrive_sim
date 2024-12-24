// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from midterm_msgs:msg/WallList.idl
// generated code does not contain a copyright notice
#include "midterm_msgs/msg/detail/wall_list__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `walls`
#include "midterm_msgs/msg/detail/wall__functions.h"

bool
midterm_msgs__msg__WallList__init(midterm_msgs__msg__WallList * msg)
{
  if (!msg) {
    return false;
  }
  // walls
  if (!midterm_msgs__msg__Wall__Sequence__init(&msg->walls, 0)) {
    midterm_msgs__msg__WallList__fini(msg);
    return false;
  }
  return true;
}

void
midterm_msgs__msg__WallList__fini(midterm_msgs__msg__WallList * msg)
{
  if (!msg) {
    return;
  }
  // walls
  midterm_msgs__msg__Wall__Sequence__fini(&msg->walls);
}

bool
midterm_msgs__msg__WallList__are_equal(const midterm_msgs__msg__WallList * lhs, const midterm_msgs__msg__WallList * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // walls
  if (!midterm_msgs__msg__Wall__Sequence__are_equal(
      &(lhs->walls), &(rhs->walls)))
  {
    return false;
  }
  return true;
}

bool
midterm_msgs__msg__WallList__copy(
  const midterm_msgs__msg__WallList * input,
  midterm_msgs__msg__WallList * output)
{
  if (!input || !output) {
    return false;
  }
  // walls
  if (!midterm_msgs__msg__Wall__Sequence__copy(
      &(input->walls), &(output->walls)))
  {
    return false;
  }
  return true;
}

midterm_msgs__msg__WallList *
midterm_msgs__msg__WallList__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  midterm_msgs__msg__WallList * msg = (midterm_msgs__msg__WallList *)allocator.allocate(sizeof(midterm_msgs__msg__WallList), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(midterm_msgs__msg__WallList));
  bool success = midterm_msgs__msg__WallList__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
midterm_msgs__msg__WallList__destroy(midterm_msgs__msg__WallList * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    midterm_msgs__msg__WallList__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
midterm_msgs__msg__WallList__Sequence__init(midterm_msgs__msg__WallList__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  midterm_msgs__msg__WallList * data = NULL;

  if (size) {
    data = (midterm_msgs__msg__WallList *)allocator.zero_allocate(size, sizeof(midterm_msgs__msg__WallList), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = midterm_msgs__msg__WallList__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        midterm_msgs__msg__WallList__fini(&data[i - 1]);
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
midterm_msgs__msg__WallList__Sequence__fini(midterm_msgs__msg__WallList__Sequence * array)
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
      midterm_msgs__msg__WallList__fini(&array->data[i]);
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

midterm_msgs__msg__WallList__Sequence *
midterm_msgs__msg__WallList__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  midterm_msgs__msg__WallList__Sequence * array = (midterm_msgs__msg__WallList__Sequence *)allocator.allocate(sizeof(midterm_msgs__msg__WallList__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = midterm_msgs__msg__WallList__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
midterm_msgs__msg__WallList__Sequence__destroy(midterm_msgs__msg__WallList__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    midterm_msgs__msg__WallList__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
midterm_msgs__msg__WallList__Sequence__are_equal(const midterm_msgs__msg__WallList__Sequence * lhs, const midterm_msgs__msg__WallList__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!midterm_msgs__msg__WallList__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
midterm_msgs__msg__WallList__Sequence__copy(
  const midterm_msgs__msg__WallList__Sequence * input,
  midterm_msgs__msg__WallList__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(midterm_msgs__msg__WallList);
    midterm_msgs__msg__WallList * data =
      (midterm_msgs__msg__WallList *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!midterm_msgs__msg__WallList__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          midterm_msgs__msg__WallList__fini(&data[i]);
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
    if (!midterm_msgs__msg__WallList__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
