/*
 * stack-stage1.cpp
 *
 * Method definitions for the stack implementation (stage 1).
 *
 * Author: Sophie Kawi
 */

#include "stack-stage1.h"

stack::stack()
  : _data(new std::string[4]), _capacity(4), _count(0) {
}

void stack::push(const std::string &value) {
    // if full, resize
    if (_count == _capacity) {
        size_t newCapacity = _capacity * 2;
        std::string *newData = new std::string[newCapacity];

        for (size_t i = 0; i < _count; i++) {
            newData[i] = _data[i];
        }

        delete[] _data;
        _data = newData;
        _capacity = newCapacity;
    }

    _data[_count] = value;
    _count++;
}

void stack::pop() {
    _count--;
}

std::string stack::top() {
    return _data[_count - 1];
}

size_t stack::size() {
    return _count;
}

bool stack::is_empty() {
    return _count == 0;
}
