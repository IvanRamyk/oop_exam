//
// Created by hryhorchuk117 on 10/06/2020.
//

#include "Sort.h"


template<class T>
Sort<T>::Sort(const std::vector<T>& data) {
    _data = data;
}

template<class T>
std::vector<T> Sort<T>::getData() const {
    return _data;
}

template<class T>
void Sort<T>::selectionSort(const std::function<bool(T, T)>& compare) {
    for (int i = 0; i < _data.size(); ++i) {
        auto min = _data[i];
        for (int j = i; j < _data.size(); ++j) {
            if (compare(min, _data[i])) {
                min = _data[i];
            }
        }
        std::swap(min, _data[i]);
    }
}
