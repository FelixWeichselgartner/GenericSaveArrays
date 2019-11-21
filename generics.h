#ifndef GENERICS_H_
#define GENERICS_H_

#include <stdlib.h>

#define def_array(T) \
typedef struct { \
    T* ptr; \
    int max; \
} array_##T; 


#define def_alloc_memory(T) \
array_##T* alloc_memory_##T(int len) { \
    array_##T* obj = malloc(sizeof(array_##T)); \
    if (obj != NULL) { \
        obj->max = len; \
        obj->ptr = malloc(len * sizeof(T)); \
    } \
    return obj; \
}

#define def_realloc_memory(T) \
int realloc_memory_##T(array_##T* obj, int len) { \
    if (obj == NULL) { \
        return 0; \
    } else { \
        if (obj->max == len) { \
            return 1; \
        } else { \
            obj->ptr = (T*)realloc(obj->ptr, len * sizeof(T)); \
            if (obj->ptr == NULL) { \
                return 0; \
            } else { \
                obj->max = len; \
                return 1; \
            } \
        } \
    } \
} 

#define def_get(T) \
T get_##T(array_##T* obj, int pos, int* status) { \
    if (obj != NULL) { \
        if (pos >= obj->max || pos < 0) { \
            printf("get out of bound -> len:%i, pos:%i", obj->max, pos); \
            *status = 0; \
            return 0; \
        } else { \
            *status = 1; \
            return obj->ptr[pos]; \
        } \
    } else { \
        *status = 0; \
        return 0; \
    } \
}

#define def_set(T) \
int set_##T(array_##T* obj, int pos, T value) { \
    if (obj != NULL) { \
        if (pos >= obj->max && pos < 0) { \
            printf("set out of bound -> len:%i, pos:%i", obj->max, pos); \
            return 0; \
        } else { \
            obj->ptr[pos] = value; \
            return 1; \
        } \
    } else { \
        return 0; \
    } \
}

#define def_free_array(T) \
void free_array_##T(array_##T* obj) { \
    free(obj->ptr); \
}

#define def_all(T) \
def_array(T) \
def_alloc_memory(T) \
def_realloc_memory(T) \
def_get(T) \
def_set(T) \
def_free_array(T)

#endif