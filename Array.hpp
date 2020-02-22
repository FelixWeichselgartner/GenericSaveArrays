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
    Array_##T(unsigned int len, T error_return) {  \
        this->_len = len;  \
        this->error_return = error_return; \
        this->reserve(); \
    } \
    ~Array_##T() { \
        this->del(); \
    } \
    T get(unsigned int pos) const { \
        if (this->_ptr != NULL) { \
            if (pos >= this->_len) { \
                std::cout << "get out of bound -> len:" << this->_len << ", pos:" << pos << std::endl; \
                return this->error_return; \
            } else { \
                return this->_ptr[pos]; \
            } \
        } else { \
            printf("your obj is NULL.\n"); \
            return this->error_return; \
        } \
    } \
    void set(unsigned int pos, T value) { \
        if (this->_ptr != NULL) { \
            if (pos >= this->_len) { \
                std::cout << "set out of bound -> len:" << this->_len << ", pos:" << pos << std::endl; \
            } else { \
                this->_ptr[pos] = value; \
            } \
        } else { \
            std::cout << "your obj is NULL." << std::endl; \
        } \
    } \
    int length() { \
        return this->_len; \
    } \
private: \
    T* _ptr; \
    T error_return; \
    unsigned int _len; \
};

#define Array_Type(T) Array_##T
#define Array(T, l, r) Array_##T(l, r)

#endif
