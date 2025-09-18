#ifndef __STUDENT_H_
#define __STUDENT_H_

// you can include any other file here
// you are allow to use any data structure
#include "vector.h"
#include <bits/stdc++.h>

template <typename T>
void CP::vector<T>::uniq() {
    T *arr = new T[mCap]();
    std::vector<std::pair<T, size_t>> v1(mSize);
    for (size_t i = 0; i < mSize; i++) {
        v1[i] = {mData[i], i};
    }
    std::sort(v1.begin(), v1.end());
    std::vector<std::pair<size_t, T>> v2;
    if (!v1.empty()) {
        v2.push_back({v1[0].second, v1[0].first});
    }
    for (size_t i = 1; i < mSize; i++) {
        if (v1[i].first != v1[i - 1].first) {
            v2.push_back({v1[i].second, v1[i].first});
        }
    }
    std::sort(v2.begin(), v2.end());
    size_t idx = 0;
    for (auto &[f, s] : v2) {
        arr[idx++] = s;
    }
    delete[] mData;
    mData = arr;
    mSize = idx;
}

#endif
