/*
 * stack-stage3.h
 *
 * Implements a simple stack class using dynamic arrays.
 * This may be implemented in 3 stages:
 *   Stage 1: non-template stack class storing strings,
 *            unsafe copies/assignments
 *   Stage 2: template stack class, unsafe copies/assignments
 *   Stage 3: template stack class, safe copies/assignments
 *
 * Note: no underflow detection is performed.  Performing pop() or top()
 * on an empty stack results in undefined behavior (possibly crashing your
 * program)!
 *
 * Author: Sophie Kawi
 */


#ifndef _STACK_STAGE3_H
#define _STACK_STAGE3_H

#include <cstddef>

template <typename T>
class stack {
  public:
    stack() : _data(new T[4]), _capacity(4), _count(0) {
    }

    ~stack() {
        delete[] _data;
    }

    stack(const stack &other)
      : _data(new T[other._capacity]),
        _capacity(other._capacity),
        _count(other._count) {
        for (std::size_t i = 0; i < _count; i++) {
            _data[i] = other._data[i];
        }
    }

    stack &operator=(const stack &other) {
        if (this == &other) {
            return *this;
        }

        T *newData = new T[other._capacity];
        for (std::size_t i = 0; i < other._count; i++) {
            newData[i] = other._data[i];
        }

        delete[] _data;
        _data = newData;
        _capacity = other._capacity;
        _count = other._count;

        return *this;
    }

    void push(const T &value) {
        if (_count == _capacity) {
            std::size_t newCapacity = _capacity * 2;
            T *newData = new T[newCapacity];

            for (std::size_t i = 0; i < _count; i++) {
                newData[i] = _data[i];
            }

            delete[] _data;
            _data = newData;
            _capacity = newCapacity;
        }

        _data[_count] = value;
        _count++;
    }

    void pop() {
        _count--;
    }

    T top() {
        return _data[_count - 1];
    }

    std::size_t size() {
        return _count;
    }

    bool is_empty() {
        return _count == 0;
    }

  private:
    T *_data;
    std::size_t _capacity;
    std::size_t _count;
};

#endif

/***
 * DO NOT put unscoped 'using namespace std;' in header files!
 * Instead use the std:: prefix where required in class definitions, as
 * demonstrated in the stack starter code for stage1.
 */
