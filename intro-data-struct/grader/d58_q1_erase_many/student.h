#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "vector.h"
#include <bits/stdc++.h>

template <typename T>
void CP::vector<T>::erase_many(const std::vector<int> &pos) {
    std::vector<int> sortedPos = pos;
    sortedPos.push_back(-1);
    sortedPos.push_back(mSize);
    std::sort(sortedPos.begin(), sortedPos.end());
    T *arr = new T[mCap]();
    int idx = 0;
    for (int i = 1; i < sortedPos.size(); ++i) {
        for (int j = sortedPos[i - 1] + 1; j < sortedPos[i]; ++j) {
            arr[idx++] = mData[j];
        }
    }
    delete[] mData;
    mData = arr;
    mSize = idx;
    return;
}

#endif
