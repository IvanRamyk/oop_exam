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
#include "../../structures/lists/SingleLinkedList/SingleLinkedOrderedList.hpp"
#include "../../Hash/CuckooHash.h"
#include "../../Hash/HopscotchHash.h"

template <typename Structure>
struct SetOperations;

template <typename T, class C>
struct SetOperations <SplayTree<T, C>> {
    using value_type = typename SplayTree<T>::value_type;
    static auto insert (SplayTree<T, C>& container, const value_type& value)
    {
        container.insert(value);
    }

    static auto count(SplayTree<T, C>& container, const value_type& value)
    {
        auto c = container.search(value);
        return c != nullptr;
    }

    static auto search(SplayTree<T, C>& container, const value_type& value)
    {
        return container.search(value);
    }

    static auto erase(SplayTree<T, C>& container, const value_type& value)
    {
        container.remove(container.search(value));
    }

    static auto elements(SplayTree<T, C>& container)
    {
        return container.elements();
    }
};

template <typename T, typename C>
struct SetOperations <SingleLinkedOrderedList<T, C>> {
    using value_type = typename SingleLinkedOrderedList<T>::value_type;
    static auto insert (SingleLinkedOrderedList<T, C>& container, const value_type& value)
    {
        container.insert(value);
    }

    static auto count(SingleLinkedOrderedList<T, C>& container, const value_type& value)
    {
        return container.search(value) != nullptr;
    }

    static auto search(SingleLinkedOrderedList<T, C>& container, const value_type& value)
    {
        return container.search(value);
    }

    static auto erase(SingleLinkedOrderedList<T, C>& container, const value_type& value)
    {
        container.erase(value);
    }

    static auto elements(SingleLinkedOrderedList<T, C>& container)
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

template <typename T>
struct SetOperations <CuckooHash<T>> {
    using value_type = typename CuckooHash<T>::value_type;
    static auto insert (CuckooHash<T>& container, const value_type& value)
    {
        container.add(value);
    }

    static auto count(CuckooHash<T>& container, const value_type& value)
    {
        return container.count(value);
    }

    static auto search(CuckooHash<T>& container, const value_type& value)
    {
        return container.search(value);
    }

    static auto erase(CuckooHash<T>& container, const value_type& value)
    {
        container.erase(value);
    }

    static auto elements(CuckooHash<T>& container)
    {
        //return container.elements();
        return std::vector<T> {};
    }
};


template <typename T>
struct SetOperations <HopscotchHash<T>> {
    using value_type = typename HopscotchHash<T>::value_type;
    static auto insert (HopscotchHash<T>& container, const value_type& value)
    {
        container.add(value);
    }

    static auto count(HopscotchHash<T>& container, const value_type& value)
    {
        return container.count(value);
    }

    static auto search(HopscotchHash<T>& container, const value_type& value)
    {
        return container.search(value);
    }

    static auto erase(HopscotchHash<T>& container, const value_type& value)
    {
        container.erase(value);
    }

    static auto elements(HopscotchHash<T>& container)
    {
        //return container.elements();
        return std::vector<T> {};
    }
};





#endif //OOP_EXAM_SETOPERATIONS_HPP
