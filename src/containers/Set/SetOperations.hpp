//
// Created by ivan on 08.06.20.
//

#ifndef OOP_EXAM_SETOPERATIONS_HPP
#define OOP_EXAM_SETOPERATIONS_HPP

#include "../../structures/balanced_searched_trees/SplayTree.hpp"

template <typename Structure>
struct SetOperations;

template <typename T>
struct SetOperations <SplayTree<T>> {
    using value_type = typename SplayTree<T>::value_type;
    static auto insert (SplayTree<T>& container, const value_type& value)
    {
        container.insert(value);
    }

    static auto count(SplayTree<T>& container, const value_type& value)
    {
        return container.search(value) != nullptr;
    }

    static auto search(SplayTree<T>& container, const value_type& value)
    {
        return container.search(value);
    }

    static auto erase(SplayTree<T>& container, const value_type& value)
    {
        container.remove(container.search(value));
    }
};





#endif //OOP_EXAM_SETOPERATIONS_HPP
