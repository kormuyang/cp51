#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "vector.h"

template <typename T>
void CP::vector<T>::compress() {
    T *arr = new T[mSize]();
    for (size_t i = 0; i < mSize; ++i) {
        arr[i] = mData[i];
    }
    delete[] mData;
    mData = arr;
    mCap = mSize;
    return;
}

#endif
