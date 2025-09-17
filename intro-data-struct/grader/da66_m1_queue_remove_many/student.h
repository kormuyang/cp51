#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "queue.h"
#include <bits/stdc++.h>

template <typename T>
void CP::queue<T>::remove_many(std::vector<size_t> pos) {
    std::sort(pos.begin(), pos.end());
    T *arr = new T[mCap]();
    size_t prev = -1, idx = 0;
    for (size_t i = 0; i < pos.size() && pos[i] < mSize; i++) {
        for (size_t j = prev + 1; j < pos[i]; j++) {
            arr[idx++] = mData[(mFront + j) % mCap];
        }
        prev = pos[i];
    }
    for (size_t j = prev + 1; j < mSize; j++) {
        arr[idx++] = mData[(mFront + j) % mCap];
    }
    delete[] mData;
    mData = arr;
    mSize = idx;
    mFront = 0;
}

#endif
