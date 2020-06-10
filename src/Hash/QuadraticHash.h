//
// Created by hryhorchuk117 on 10/06/2020.
//

#ifndef OOP_EXAM_QUADRATICHASH_H
#define OOP_EXAM_QUADRATICHASH_H

#include <vector>
#include <iterator>
#include <chrono>
#include "../../src/Date/Date.hpp"
#include "../../src/Server/Server.hpp"


template <class T> class QuadraticHash {
public:
    explicit QuadraticHash(const std::vector<T>& vec);

    auto search(const T& item) const;

    std::vector<T> getData() const;

    void setStartTime();

    double getTime() const;

    void add(const T& item);

    void deleteCopy();

private:
    std::vector<T> _data;
    std::vector<bool> _added;
    std::chrono::time_point<std::chrono::high_resolution_clock> _start = std::chrono::high_resolution_clock::now();
};

template<class T>
std::vector<T> QuadraticHash<T>::getData() const {
    return _data;
}

template<class T>
auto QuadraticHash<T>::search(const T &item) const {
    int i = 0;
    while (true) {
        if (_data[(item.toInt() + i*i) % _data.size()] == item) {
            return begin(_data) + (item.toInt() + i*i) % _data.size();
        } else {
            ++i;
        }
    }
}

template<class T>
QuadraticHash<T>::QuadraticHash(const std::vector<T> &vec) {
    int size = 1000;
    _data.resize(size);
    _added.resize(size);
    for (const auto& item : vec) {
        add(item);
    }
}

template<class T>
void QuadraticHash<T>::add(const T& item) {
    bool added = false;
    int i = 0;
    while (!added) {
        if (!_added[(item.toInt() + i*i) % _added.size()]) {
            added = true;
            _added[(item.toInt() + i*i) % _added.size()] = true;
            _data[(item.toInt() + i*i) % _added.size()] = item;
        } else {
            ++i;
        }
    }
}

template<class T>
double QuadraticHash<T>::getTime() const {
    auto _finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = _finish - _start;
    return elapsed.count();
}

template<class T>
void QuadraticHash<T>::setStartTime() {
    _start = std::chrono::high_resolution_clock::now();
}

template<class T>
void QuadraticHash<T>::deleteCopy() {
    for (int i = 0; i < _data.size(); ++i) {
        for (int j = i + 1; j < _data.size(); ++j) {
            if (_data[i] == _data[j]) {
                _data[j] = {};
                _added[j] = false;
            }
        }
    }
}

#endif //OOP_EXAM_QUADRATICHASH_H
