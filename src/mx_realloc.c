#include "../inc/libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    if (size == 0) {
        free(ptr);
        return NULL;
    }

    void *new_ptr = malloc(size);

    if (new_ptr == NULL) {
        return NULL;
    }

    if (ptr != NULL) {
        mx_memcpy(new_ptr, ptr, size);
        free(ptr);
    }

    return new_ptr;
}
