#ifndef __STUDENT_H_
#define __STUDENT_H_

// You can include library here
#include "vector.h"
#include <bits/stdc++.h>

template <typename T>
void CP::vector<T>::uniq(std::vector<CP::vector<T>::iterator> itrs) {
    std::sort(itrs.begin(), itrs.end());
    std::set<T> st;
    std::vector<size_t> pos;
    for (size_t i = 0; i < itrs.size(); i++) {
        if (st.find(*itrs[i]) == st.end()) {
            st.insert(*itrs[i]);
        } else {
            pos.push_back(itrs[i] - mData);
        }
    }
    T *arr = new T[mCap]();
    size_t idx = 0, j = 0;
    for (size_t i = 0; i < mSize; i++) {
        if (j == pos.size() || i != pos[j]) {
            arr[idx++] = mData[i];
        } else {
            j++;
        }
    }
    delete[] mData;
    mData = arr;
    mSize = idx;
}

#endif
