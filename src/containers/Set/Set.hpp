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
    Structure _container;
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

};



#endif //OOP_EXAM_SET_HPP
