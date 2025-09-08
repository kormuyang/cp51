#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "pair.h"

template <typename T1, typename T2>
bool CP::pair<T1, T2>::operator>=(const CP::pair<T1, T2> &other) const {
    if (this->first == other.first)
        return this->second > other.second || this->second == other.second;
    return this->first > other.first;
}

#endif
