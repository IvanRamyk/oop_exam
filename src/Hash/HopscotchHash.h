//
// Created by hryhorchuk117 on 10/06/2020.
//

#ifndef OOP_EXAM_HOPSCOTCHHASH_H
#define OOP_EXAM_HOPSCOTCHHASH_H

#include <vector>
#include <chrono>
#include "../../src/Date/Date.hpp"
#include "../../src/Server/Server.hpp"


template <class T> class HopscotchHash {
public:
    using value_type = T;
    explicit HopscotchHash(const std::vector<T>& vec = {});

    auto search(const T& item) const;

    std::vector<T> getData() const;

    void setStartTime();

    double getTime() const;

    void add(const T& item);

    void deleteCopy();

    void erase(const T& item);

    bool count(const T& item) const ;

private:
    std::vector<T> _data;
    std::vector<bool> _added;
    std::chrono::time_point<std::chrono::high_resolution_clock> _start = std::chrono::high_resolution_clock::now();
};

template<class T>
std::vector<T> HopscotchHash<T>::getData() const {
    return _data;
}

template<class T>
auto HopscotchHash<T>::search(const T &item) const {
    for (int i = item.toInt() % _data.size(); i < _data.size(); ++i) {
        i %= _data.size();
        if (_data[i] == item) {
            return begin(_data) + i;
        }
    }
    return end(_data);
}

template<class T>
HopscotchHash<T>::HopscotchHash(const std::vector<T> &vec) {
    int size = 1000;
    _data.resize(size);
    _added.resize(size);
    for (const auto& item : vec) {
        add(item);
    }
}

template<class T>
void HopscotchHash<T>::add(const T& item) {
    auto c = item;
    int curr = c.toInt() % _data.size();
    while (_added[curr]) {
        ++curr;
        curr %= _data.size();
    }
    _added[curr] = true;
    _data[curr] = item;
}

template<class T>
double HopscotchHash<T>::getTime() const {
    auto _finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = _finish - _start;
    return elapsed.count();
}

template<class T>
void HopscotchHash<T>::setStartTime() {
    _start = std::chrono::high_resolution_clock::now();
}


template<class T>
void HopscotchHash<T>::deleteCopy() {
    for (int i = 0; i < _data.size(); ++i) {
        for (int j = i + 1; j < _data.size(); ++j) {
            if (_data[i] == _data[j]) {
                _data[j] = {};
                _added[j] = false;
            }
        }
    }
}

template<class T>
void HopscotchHash<T>::erase(const T& item) {
    auto it = search(item);
    if (it != end(_data)) {
        _data.erase(it);
    }
}

template<class T>
bool HopscotchHash<T>::count(const T &item) const {
    return search(item) != _data.end();
}

#endif //OOP_EXAM_HOPSCOTCHHASH_H
