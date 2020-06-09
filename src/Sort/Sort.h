//
// Created by hryhorchuk117 on 10/06/2020.
//

#ifndef OOP_EXAM_SORT_H
#define OOP_EXAM_SORT_H

#include <vector>
#include <functional>

template <class T> class Sort {
public:
    explicit Sort(const std::vector<T>& data);

    void selectionSort(const std::function<bool(T, T)>& compare);

    std::vector<T> getData() const;
private:
    std::vector<T> _data;
};


#endif //OOP_EXAM_SORT_H
