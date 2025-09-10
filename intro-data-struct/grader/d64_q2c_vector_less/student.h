#ifndef __STUDENT_H_
#define __STUDENT_H_

#include "vector.h"

template <typename T>
bool CP::vector<T>::operator<(const CP::vector<T> &other) const {
    for (int i = 0; i < this->size() && i < other.size(); ++i) {
        if ((*this)[i] != other[i]) {
            return (*this)[i] < other[i];
        }
    }
    return this->size() < other.size();
}

#endif
