//
// Created by ivan on 08.06.20.
//

#ifndef OOP_EXAM_MAP_HPP
#define OOP_EXAM_MAP_HPP

#include <cassert>
#include "../Set/Set.hpp"

template <typename Tkey, typename Tvalue>
struct Pair {
    Tkey key;
    Tvalue value;
};

template <typename Tkey, typename Tvalue>
bool operator <(Pair<Tkey, Tvalue> left, Pair<Tkey, Tvalue> right) {
    return left.key < right.key;
}

template <typename Tkey, typename Tvalue>
bool operator ==(Pair<Tkey, Tvalue> left, Pair<Tkey, Tvalue> right) {
    return left.key == right.key;
}

template <typename Tkey, typename Tvalue>
bool operator >(Pair<Tkey, Tvalue> left, Pair<Tkey, Tvalue> right) {
    return left.key > right.key;
}



template <typename Tkey, typename Tvalue, template <typename> class Container>
class Map {
public:
    using Tset = Set<Container<Pair<Tkey, Tvalue>>>;

    void insert(Tkey key, Tvalue value) {
        if (count(key))
            erase(key);
        set.insert({key, value});
    }

    Tvalue getValue(Tkey key) {
        auto temp = set.search({key, Tvalue()});
        assert(temp != nullptr && "Key must be exist");
        return temp->value().value;
    }

    bool count(Tkey key) {
        return set.count({key, Tvalue()});
    }

    void erase(Tkey key) {
        set.erase({key, Tvalue()});
    }

private:
    Tset set;
};


#endif //OOP_EXAM_MAP_HPP
