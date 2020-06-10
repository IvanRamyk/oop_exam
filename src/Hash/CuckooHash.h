//
// Created by hryhorchuk117 on 10/06/2020.
//

#ifndef OOP_EXAM_CUCKOOHASH_H
#define OOP_EXAM_CUCKOOHASH_H

#include <vector>
#include <chrono>
#include "../../src/Date/Date.hpp"
#include "../../src/Server/Server.hpp"


template <class T> class CuckooHash {
public:
    explicit CuckooHash(const std::vector<T>& vec);

    typename std::vector<T>::iterator search(const T& item) const;

    std::pair<std::vector<T>, std::vector<T>> getData() const;

    void setStartTime();

    double getTime() const;

private:
    std::vector<T> _data1;
    std::vector<T> _data2;
    std::vector<bool> _added1;
    std::vector<bool> _added2;
    std::chrono::time_point<std::chrono::high_resolution_clock> _start = std::chrono::high_resolution_clock::now();

    void add(const T& item);
};

template<class T>
std::pair<std::vector<T>, std::vector<T>> CuckooHash<T>::getData() const {
    return {_data1, _data2};
}

template<class T>
typename std::vector<T>::iterator CuckooHash<T>::search(const T &item) const {
    if (_data1[item.toInt() % _data1.size()] == item) {
        return begin(_data1) + item.toInt() % _data1.size();
    }

    if (_data2[(item.toInt() / _data2.size()) % _data2.size()]) {
        return begin(_data2) + (item.toInt() / _data2.size()) % _data2.size();
    }

    return end(_data1);
}

template<class T>
CuckooHash<T>::CuckooHash(const std::vector<T> &vec) {
    _data1.resize(vec.size()*2);
    _data2.resize(vec.size()*2);
    _added1.resize(vec.size());
    _added2.resize(vec.size());
    for (const auto& item : vec) {
        add(item);
    }
}

template<class T>
void CuckooHash<T>::add(const T& item) {
    bool added = false;
    auto curr = item;
    int currTable = 1;
    while (!added) {
        if (currTable) {
            if (!_added1[curr.toInt() % _data1.size()]) {
                _added1[curr.toInt() % _data1.size()] = true;
                added = true;
                _data1[curr.toInt() % _data1.size()] = curr;
            } else {
                auto temp = _data1[curr.toInt() % _data1.size()];
                _data1[curr.toInt() % _data1.size()] = curr;
                curr = temp;
            }
            currTable = 0;
        } else {
            if (!_added2[(curr.toInt() / _data2.size()) % _data2.size()]) {
                _added2[(curr.toInt() / _data2.size()) % _data2.size()] = true;
                added = true;
                _data2[(curr.toInt() / _data2.size()) % _data2.size()] = curr;
            } else {
                auto temp = _data2[(curr.toInt() / _data2.size()) % _data2.size()];
                _data2[(curr.toInt() / _data2.size()) % _data2.size()] = curr;
                curr = temp;
            }
            currTable = 1;
        }
    }
}

    template<class T>
    double CuckooHash<T>::getTime() const {
        auto _finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = _finish - _start;
        return elapsed.count();
    }

    template<class T>
    void CuckooHash<T>::setStartTime() {
        _start = std::chrono::high_resolution_clock::now();
    }



#endif //OOP_EXAM_CUCKOOHASH_H
