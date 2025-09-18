#ifndef __STUDENT_H_
#define __STUDENT_H_

// can include anything
#include "vector.h"
#include <bits/stdc++.h>

template <typename T>
template <typename CompareT>
void CP::vector<T>::partial_sort(std::vector<iterator> &pos, CompareT comp) {
    // you can compare two data A and B of type T by calling comp(A,B)
    // which return true when A is less than B
    CP::vector<T> tmp(pos.size());
    for (size_t i = 0; i < pos.size(); ++i) {
        tmp[i] = *pos[i];
    }
    std::sort(tmp.begin(), tmp.end(), comp);
    std::sort(pos.begin(), pos.end());
    for (size_t i = 0; i < pos.size(); ++i) {
        *pos[i] = tmp[i];
    }
}

#endif
