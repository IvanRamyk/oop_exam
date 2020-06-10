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

    explicit Sort()= default;

    void setData(std::vector<T> data) {_data = data;}

    void selectionSort(const std::function<bool(T, T)>& compare);

    void heapSort(const std::function<bool(T, T)>& compare);

    void mergeSort(const std::function<bool(T, T)>& compare);

    void countingSort(const std::function<bool(T, T)>& compare);

    void insertionSort(const std::function<bool(T, T)>& compare);

    void quickSort(const std::function<bool(T, T)>& compare);

    void radixSort(const std::function<bool(T, T)>& compare);

    std::vector<T> getData() const;
private:
    std::vector<T> _data;

    void merge(std::vector<T>& vec, int iLeft, int iRight, int iEnd, std::vector<T>& temp, const std::function<bool(T, T)> &compare);

    void mergePart(std::vector<T>& vec, std::vector<T>& temp, const std::function<bool(T, T)> &compare);

    template <class iter>
    void quickPartSort(iter begin, iter end, const std::function<bool(T, T)> &compare);

    template <class iter>
    iter partition(iter begin, iter end, const std::function<bool(T, T)> &compare);
};


#endif //OOP_EXAM_SORT_H
