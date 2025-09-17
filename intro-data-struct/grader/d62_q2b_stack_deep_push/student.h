#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "stack.h"

template <typename T>
void CP::stack<T>::deep_push(size_t pos, const T &value) {
    CP::stack<T> tmp;
    for (int i = 0; i < pos; i++) {
        tmp.push(this->top());
        this->pop();
    }
    this->push(value);
    for (int i = 0; i < pos; i++) {
        this->push(tmp.top());
        tmp.pop();
    }
    return;
}

#endif
