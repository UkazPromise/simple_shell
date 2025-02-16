#include "memory.h"
#include <stdlib.h>

/**
 * _realloc - Reallocates a memory block using malloc and free
 *
 * @ptr: Pointer to the memory previously allocated
 * @old_size: Size, in bytes, of the allocated space for ptr
 * @new_size: New size, in bytes of the new memory block
 *
 * Return: Memory reallocated
 **/
void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
    char *s, *aux;

    if (new_size == old_size)
        return ptr;

    if (ptr == NULL)
    {
        s = malloc(new_size);
        return s;
    }

    if (new_size == 0 && ptr != NULL)
    {
        free(ptr);
        return NULL;
    }

    s = malloc(new_size);
    if (s == NULL)
        return NULL;

    aux = ptr;
    memcpy(s, aux, (old_size < new_size) ? old_size : new_size);
    free(ptr);

    return s;
}
