# harena

A simple arena allocator implementation in C.

## Description

An arena allocator is a memory management technique that allocates a large block of memory upfront and then serves smaller allocations from it sequentially. This approach provides fast allocations and efficient bulk deallocation, making it ideal for scenarios where you need to allocate many objects that share the same lifetime.

## Features

- O(1) allocation time
- 8-byte alignment for allocations
- Save/restore functionality for snapshot-like behavior
- Bulk deallocation (reset/destroy)
- Standard and zero-initialized (calloc) allocation

## API

```c
t_harena harena_create(const size_t capacity);
```
Creates a new arena with the specified capacity.

```c
void *harena_alloc(t_harena *h, const size_t bytes);
```
Allocates `bytes` from the arena. Returns NULL if allocation fails.

```c
void *harena_calloc(t_harena *h, const size_t bytes);
```
Allocates `bytes` from the arena and initializes memory to zero.

```c
size_t harena_save(t_harena *h);
```
Returns the current offset, allowing you to save the arena state for later restoration.

```c
void harena_restore(t_harena *h, const size_t offset);
```
Restores the arena to a previously saved offset, effectively "freeing" allocations made after that point.

```c
void harena_reset(t_harena *h);
```
Resets the arena offset to 0, invalidating all allocations.

```c
void harena_destroy(t_harena *h);
```
Frees the underlying memory and resets the arena.

## Building

```bash
make
```

This produces `harena.a`, a static library.

## Usage

```c
#include "harena.h"

int main(void)
{
    t_harena arena = harena_create(1024); // 1KB arena

    int *numbers = harena_alloc(&arena, 10 * sizeof(int));
    // Use numbers...

    harena_destroy(&arena);
    return (0);
}
```

## Testing

```bash
make test
```

## Dependencies

- [libft](https://github.com/42School/libft) - 42 School standard C library
