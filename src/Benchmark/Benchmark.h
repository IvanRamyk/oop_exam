//
// Created by hryhorchuk117 on 10/06/2020.
//

#ifndef OOP_EXAM_BENCHMARK_H
#define OOP_EXAM_BENCHMARK_H

#include <functional>
#include <chrono>
#include "../../src/Sort/Sort.h"

class Benchmark {
public:
    template<class T, class G> double getSortTime(T& function, std::function<bool(G, G)>& param) const;
};

template<class T, class G>
double Benchmark::getSortTime(T &function, std::function<bool(G, G)> &param) const {
    auto start = std::chrono::high_resolution_clock::now();

    function(param);

    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;

    return elapsed.count();
}

#endif //OOP_EXAM_BENCHMARK_H
