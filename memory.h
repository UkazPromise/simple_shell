#ifndef MEMORY_H_INCLUDED
#define MEMORY_H_INCLUDED

#include <stdlib.h>

/* memory.c */
/**
 * @brief Reallocates a memory block using malloc and free.
 *
 * @param ptr Pointer to the memory previously allocated.
 * @param old_size Size, in bytes, of the allocated space for ptr.
 * @param new_size New size, in bytes, of the new memory block.
 * @return Memory reallocated.
 */
void *_realloc(void *ptr, size_t old_size, size_t new_size);

/* free.c */
/**
 * @brief Frees a single pointer.
 *
 * @param ptr Pointer to free.
 */
void free_memory_p(void *ptr);

/**
 * @brief Frees a double pointer and its contents.
 *
 * @param ptr Double pointer to free.
 */
void free_memory_pp(void **ptr);

#endif /* MEMORY_H_INCLUDED */
