#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "queue.h"
#include <bits/stdc++.h>

template <typename T>
std::vector<T> CP::queue<T>::to_vector(int k) const {
    std::vector<T> res;
    for (size_t i = 0; i < k && i < mSize; ++i) {
        res.push_back(mData[(mFront + i) % mCap]);
    }
    return res;
}

template <typename T>
CP::queue<T>::queue(iterator from, iterator to) {
    mSize = 0;
    for (auto it = from; it != to; ++it) {
        ++mSize;
    }
    mData = new T[mSize]();
    size_t idx = 0;
    for (auto it = from; it != to; ++it) {
        mData[idx++] = *it;
    }
    mCap = mSize; 
    mFront = 0;
}

#endif
