//
// Created by hryhorchuk117 on 10/06/2020.
//

#ifndef OOP_EXAM_SORT_H
#define OOP_EXAM_SORT_H

#include <vector>
#include <functional>
#include <chrono>

template <class T> class Sort {
public:
    explicit Sort(const std::vector<T>& data);

    explicit Sort()= default;

    void selectionSort(const std::function<bool(T, T)>& compare);

    void heapSort(const std::function<bool(T, T)>& compare);

    void mergeSort(const std::function<bool(T, T)>& compare);

    void countingSort(const std::function<bool(T, T)>& compare);

    void insertionSort(const std::function<bool(T, T)>& compare);

    void quickSort(const std::function<bool(T, T)>& compare);

    void radixSort(const std::function<bool(T, T)>& compare);

    void setStartTime();

    double getTime() const;

    std::vector<T> getData() const;
private:
    std::vector<T> _data;
    std::chrono::time_point<std::chrono::high_resolution_clock> _start = std::chrono::high_resolution_clock::now();

    void merge(std::vector<T>& vec, int iLeft, int iRight, int iEnd, std::vector<T>& temp, const std::function<bool(T, T)> &compare);

    void mergePart(std::vector<T>& vec, std::vector<T>& temp, const std::function<bool(T, T)> &compare);

    template <class iter>
    void quickPartSort(iter begin, iter end, const std::function<bool(T, T)> &compare);

    template <class iter>
    iter partition(iter begin, iter end, const std::function<bool(T, T)> &compare);
};

//
// Created by hryhorchuk117 on 10/06/2020.
//
#include <map>


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
        int index = i;
        for (int j = i; j < _data.size(); ++j) {
            if (compare(_data[j], min)) {
                min = _data[j];
                index = j;
            }
        }
        std::swap(_data[index], _data[i]);
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
    insertionSort(compare);
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

template<class T>
void Sort<T>::countingSort(const std::function<bool(T, T)> &compare) {
    std::vector<int> temp(_data.size());
    for (auto it = begin(_data); it < end(_data); ++it) {
        ++temp[it->type];
    }

    for (int i = 1; i < temp.size(); ++i) {
        temp[i] += temp[i - 1];
    }

    for (int i = static_cast<int>(temp.size() - 1); i >= 0; --i) {
        temp[i] = temp[i - 1];
    }
    temp[0] = 0;

    std::vector<int> res(_data.size());
    for (auto it = begin(_data); it < end(_data); ++it) {
        res[temp[it->type]] = *it;
        ++temp[it->type];
    }
    _data = res;
}

template<class T>
void Sort<T>::insertionSort(const std::function<bool(T, T)> &compare) {
    for (int i = 1; i <= _data.size(); ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if (compare(_data[j], _data[j - 1])) {
                std::swap(_data[j], _data[j - 1]);
            } else {
                break;
            }
        }
    }
}

template<class T>
void Sort<T>::quickSort(const std::function<bool(T, T)> &compare) {
    quickPartSort(begin(_data), end(_data), compare);
}

template<class T>
template<class iter>
iter Sort<T>::partition(iter begin, iter end, const std::function<bool(T, T)> &compare) {
    iter pivot = end - 1;
    auto temp = *begin;
    *begin = *pivot;
    *pivot = temp;

    iter i = begin;
    for (iter j = begin; j <= end - 2; j++) {
        if (compare(*j, *pivot)) {
            auto temp = *i;
            *i = *j;
            *j = temp;
            ++i;
        }
    }

    iter new_pivot = i;
    temp = *new_pivot;
    *new_pivot = *pivot;
    *pivot = temp;
    return new_pivot;
}


template<class T>
template<class iter>
void Sort<T>::quickPartSort(iter begin, iter end, const std::function<bool(T, T)> &compare) {
    if (begin < end) {
        iter pivot = partition(begin, end, compare);
        quickPartSort(begin, pivot, compare);
        quickPartSort(pivot + 1, end, compare);
    }
}

int getNumber (int n, int k) {
    for (int i = 0; i < k; ++i) {
        n /= 10;
    }
    return n % 10;
}

template<class T>
void Sort<T>::radixSort(const std::function<bool(T, T)> &compare) {
    int MAX = INT32_MAX;
    int k = 0;
    while(MAX != 0) {
        std::vector<int> temp(_data.size());
        for (auto it = begin(_data); it < end(_data); ++it) {
            ++temp[getNumber(it->health, k)];
        }

        for (int i = 1; i < temp.size(); ++i) {
            temp[i] += temp[i - 1];
        }

        for (int i = static_cast<int>(temp.size() - 1); i >= 0; --i) {
            temp[i] = temp[i - 1];
        }
        temp[0] = 0;

        std::vector<int> res(_data.size());
        for (auto it = begin(_data); it < end(_data); ++it) {
            res[temp[getNumber(it->health, k)]] = *it;
            ++temp[getNumber(it->health, k)];
        }
        _data = res;

        MAX /= 10;
        ++k;
    }
}

template<class T>
double Sort<T>::getTime() const {
    auto _finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = _finish - _start;
    return elapsed.count();
}

template<class T>
void Sort<T>::setStartTime() {
    _start = std::chrono::high_resolution_clock::now();
}


#endif //OOP_EXAM_SORT_H
