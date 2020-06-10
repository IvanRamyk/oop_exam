//
//
// Created by ivan on 08.06.20.
//

#ifndef OOP_EXAM_SETOPERATIONS_HPP
#define OOP_EXAM_SETOPERATIONS_HPP

#include <vector>

#include "../../structures/balanced_searched_trees/SplayTree.hpp"
#include "../../structures/balanced_searched_trees/BPlusTree.hpp"
#include "../../structures/balanced_searched_trees/AVLTree.hpp"
#include "../../structures/lists/SingleLinkedList/SingleLinkedOrderedList.hpp"

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
        auto c = container.search(value);
        return c != nullptr;
    }

    static auto search(SplayTree<T>& container, const value_type& value)
    {
        return container.search(value);
    }

    static auto erase(SplayTree<T>& container, const value_type& value)
    {
        container.remove(container.search(value));
    }

    static auto elements(SplayTree<T>& container)
    {
        return container.elements();
    }
};

template <typename T>
struct SetOperations <SingleLinkedOrderedList<T>> {
    using value_type = typename SingleLinkedOrderedList<T>::value_type;
    static auto insert (SingleLinkedOrderedList<T>& container, const value_type& value)
    {
        container.insert(value);
    }

    static auto count(SingleLinkedOrderedList<T>& container, const value_type& value)
    {
        return container.search(value) != nullptr;
    }

    static auto search(SingleLinkedOrderedList<T>& container, const value_type& value)
    {
        return container.search(value);
    }

    static auto erase(SingleLinkedOrderedList<T>& container, const value_type& value)
    {
        container.erase(value);
    }

    static auto elements(SingleLinkedOrderedList<T>& container)
    {
        return container.elements();
    }
};


template <typename T>
struct SetOperations <AVLTree<T>> {
    using value_type = typename AVLTree<T>::value_type;
    static auto insert (AVLTree<T>& container, const value_type& value)
    {
        container.insert(value);
    }

    static auto count(AVLTree<T>& container, const value_type& value)
    {
        return container.search(value) != nullptr;
    }

    static auto search(AVLTree<T>& container, const value_type& value)
    {
        return container.search(value);
    }

    static auto erase(AVLTree<T>& container, const value_type& value)
    {
        container.remove(value);
    }

    static auto elements(AVLTree<T>& container)
    {
        //return container.elements();
        return std::vector<T> {};
    }
};




#endif //OOP_EXAM_SETOPERATIONS_HPP
