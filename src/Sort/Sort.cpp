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

template<class T>
void Sort<T>::heapSort(const std::function<bool(T, T)> &compare) {
    for (int j = 0; j < _data.size(); j++) {
        for (int i = _data.size() / 2 -1 - j/2; i > -1; i--) {
            if (2 * i + 2 <= _data.size() - 1-j) {
                if (compare(_data[2 * i + 2], _data[2 * i + 1])) {
                    if (compare(_data[i], _data[2 * i + 1])) {
                        std::swap(_data[i], _data[2 * i + 1]);
                    }
                }
                else
                if (compare(_data[i], _data[2 * i + 1])) {
                    std::swap(_data[i], _data[2 * i + 2]);
                }
            }
            else
            if (2 * i + 1 <= _data.size() - 1-j)
                if (compare(_data[i], _data[2 * i + 1]))
                    std::swap(_data[i], _data[2 * i + 1]);
        }
        std::swap(_data[0], _data[_data.size() - 1 - j]);
    }
}

template<class T>
void Sort<T>::mergeSort(const std::function<bool(T, T)> &compare) {
    std::vector<T> new_vec = _data;

    std::vector<T> temp(new_vec.size());
    mergePart(new_vec, temp, compare);

    for (int j = 0; j < _data.size(); ++j) {
        _data[j] = new_vec[j];
    }
}

template <class T>
void Sort<T>::merge(std::vector<T>& vec, int iLeft, int iRight, int iEnd, std::vector<T>& temp, const std::function<bool(T, T)> &compare) {
    int i = iLeft, j = iRight;
    for (int k = iLeft; k < iEnd; k++) {
        if (i < iRight && (j >= iEnd || compare(vec[i], vec[j]))) {
            temp[k]= vec[i];
            i = i + 1;
        } else {
            temp[k] = vec[j];
            j = j + 1;
        }
    }
}

template <class T>
void Sort<T>::mergePart(std::vector<T>& vec, std::vector<T>& temp, const std::function<bool(T, T)> &compare) {
    for (int width = 1; width < vec.size(); width = 2 * width) {
        for (int i = 0; i < vec.size(); i = i + 2 * width) {
            merge(vec, i, std::min(i + width, (int)vec.size()),
                  std::min(i + 2 * width, (int)vec.size()), temp, compare);
        }
        vec = temp;
    }
}