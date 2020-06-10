//
// Created by hryhorchuk117 on 10/06/2020.
//

#ifndef OOP_EXAM_HOPSCOTCHHASH_H
#define OOP_EXAM_HOPSCOTCHHASH_H

#include <vector>
#include "../../src/Date/Date.hpp"
#include "../../src/Server/Server.hpp"


template <class T> class HopscotchHash {
public:
    explicit HopscotchHash(const std::vector<T>& vec);

    typename std::vector<T>::iterator search(const T& item) const;

    std::vector<T> getData() const;


private:
    std::vector<T> _data;
    std::vector<bool> _added;

    void add(const T& item);
};

template<class T>
std::vector<T> HopscotchHash<T>::getData() const {
    return _data;
}

template<class T>
typename std::vector<T>::iterator HopscotchHash<T>::search(const T &item) const {
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
    _data.resize(vec.size()*2);
    _added.resize(vec.size()*2);
    for (const auto& item : vec) {
        add(item);
    }
}

template<class T>
void HopscotchHash<T>::add(const T& item) {
    int curr = item.toInt() % _data.size();
    while (_added[curr]) {
        ++curr;
        curr %= _data.size();
    }
    _added[curr] = true;
    _data[curr] = item;
}


#endif //OOP_EXAM_HOPSCOTCHHASH_H
