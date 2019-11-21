#ifndef ARRAY_H_
#define ARRAY_H_

#include <stdint.h>
#include "generics.h"

def_all(uint8_t)
def_all(int8_t)
def_all(uint16_t)
def_all(int16_t)
def_all(uint32_t)
def_all(int32_t)
def_all(uint64_t)
def_all(int64_t)


#define unsigned char u_char
def_all(char)
def_all(short)
def_all(int)
def_all(float)
def_all(double)


#define var(T) \
array_##T

#define alloc(T, len) \
alloc_memory_##T(len);

#define Array(T, len) \
alloc(T, len);

#define realloc(T, obj, len) \
realloc_memory_##T(obj, len);

#define get(T, obj, pos, status) \
get_##T(obj, pos, status);

#define set(T, obj, pos, value) \
set_##T(obj, pos, value);

#define free_array(T, obj) \
free_array_##T(obj);

#endif