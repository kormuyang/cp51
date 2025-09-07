#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "stack.h"

template <typename T> void CP::stack<T>::reverse(size_t first, size_t last) {
    if (first >= last)
        return;
    first = std::min(first, mSize - 1);
    last = std::min(last, mSize - 1);
    size_t n = last - first + 1;
    for (size_t i = 0; i < n / 2; i++) {
        std::swap(mData[mSize - 1 - first - i], mData[mSize - 1 - last + i]);
    }
    return;
}

#endif
