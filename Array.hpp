#ifndef ARRAY_HPP_
#define ARRAY_HPP_

#include <iostream>
#include "stdlib.h"

#define cArray(T) \
class Array_##T { \
public: \
    bool reserve() { \
        this->_ptr = new T[this->_len]; \
        return this->_ptr != NULL; \
    } \
    bool realloc_memory(int len) { \
        if (this->_ptr == NULL) { \
            return false; \
        } else { \
            if (this->_len == len) { \
                return true; \
            } else { \
                this->_ptr = (T*)realloc(this->_ptr, len * sizeof(T)); \
                if (this->_ptr == NULL) { \
                    return false; \
                } else { \
                    this->_len = len; \
                    return true; \
                } \
            } \
        } \
    } \
    void del() { \
        delete this->_ptr; \
    } \
    Array_##T() { \
        this->_len = 0; \
    } \
    Array_##T(int len) {  \
        this->_len = len;  \
        this->reserve(); \
    } \
    ~Array_##T() { \
        this->del(); \
    } \
    T get(int pos) { \
        if (this->_ptr != NULL) { \
            if (pos >= this->_len || pos < 0) { \
                std::cout << "get out of bound -> len:" << this->_len << ", pos:" << pos << std::endl; \
                return 0; \
            } else { \
                return this->_ptr[pos]; \
            } \
        } else { \
            printf("your obj is NULL.\n"); \
            return 0; \
        } \
    } \
    void set(int pos, T value) { \
        if (this->_ptr != NULL) { \
            if (pos >= this->_len && pos < 0) { \
                std::cout << "set out of bound -> len:" << this->_len << ", pos:" << pos << std::endl; \
            } else { \
                this->_ptr[pos] = value; \
            } \
        } else { \
            std::cout << "your obj is NULL." << std::endl; \
        } \
    } \
private: \
    T* _ptr; \
    int _len; \
};

#define Array_Type(T) Array_##T
#define Array(T, l) Array_##T(l)

#endif