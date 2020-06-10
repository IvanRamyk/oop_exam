//
// Created by hryhorchuk117 on 10/06/2020.
//

#ifndef OOP_EXAM_QUADRATICHASH_H
#define OOP_EXAM_QUADRATICHASH_H

#include <vector>
#include "../../src/Date/Date.hpp"
#include "../../src/Server/Server.hpp"


template <class T> class QuadraticHash {
public:
    explicit QuadraticHash(const std::vector<T>& vec);

    typename std::vector<T>::iterator search(const T& item) const;

    std::vector<T> getData() const;


private:
    std::vector<T> _data;
    std::vector<bool> _added;

    void add(const T& item);
};

template<class T>
std::vector<T> QuadraticHash<T>::getData() const {
    return _data;
}

template<class T>
typename std::vector<T>::iterator QuadraticHash<T>::search(const T &item) const {
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
    _data.resize(vec.size());
    _added.resize(vec.size());
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

#endif //OOP_EXAM_QUADRATICHASH_H
