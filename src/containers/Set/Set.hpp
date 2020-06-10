//
// Created by ivan on 08.06.20.
//

#ifndef OOP_EXAM_SET_HPP
#define OOP_EXAM_SET_HPP

#include "SetOperations.hpp"


template <typename Structure>
class Set {
public:

    using value_type = typename Structure::value_type;
    using Impl = SetOperations<Structure>;

    inline auto _elements()
    {
        return Impl::elements(_container);
    }
    inline auto insert(const value_type &value)
    {
        return Impl::insert(_container, value);
    }

    inline auto count(const value_type &value)
    {
        return Impl::count(_container, value);
    }

    inline auto search(const value_type &value)
    {
        return Impl::search(_container, value);
    }

    inline auto erase(const value_type &value)
    {
        return Impl::erase(_container, value);
    }

private:
    Structure _container;
};

template <typename Structure>
Set<Structure> Union(Set<Structure> A, Set<Structure> B) {
    Set<Structure> res = A;
    auto elements = B._elements();
    for (auto el : elements){
        res.insert(el);
    }
    return res;
}

template <typename Structure>
Set<Structure> operator -(Set<Structure> A, Set<Structure> B) {
    Set<Structure> res = A;
    auto elements = B._elements();
    for (auto el : elements){
        res.erase(el);
    }
    return res;
}

template <typename Structure>
Set<Structure> Intersection(Set<Structure> A, Set<Structure> B) {
    Set<Structure> res;
    auto elements = B._elements();
    for (auto el : elements){
        if (A.count(el))
            res.insert(el);
    }
    return res;
}

template <typename Structure>
Set<Structure> SymmetricDifference(Set<Structure> A, Set<Structure> B) {
    return Union(A, B) - Intersection(A, B);
}

#endif //OOP_EXAM_SET_HPP
