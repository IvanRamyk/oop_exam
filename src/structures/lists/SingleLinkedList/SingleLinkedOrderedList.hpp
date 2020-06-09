//
// Created by ivan on 08.06.20.
//

#ifndef OOP_EXAM_SINGLELINKEDORDEREDLIST_HPP
#define OOP_EXAM_SINGLELINKEDORDEREDLIST_HPP

#include <iostream>


template <typename T>
struct SingleLinkedOrderedNode {
    T _value;
    SingleLinkedOrderedNode<T> * next;
    SingleLinkedOrderedNode() {
        next = nullptr;
    }
    explicit SingleLinkedOrderedNode(T _data) {
        _value = _data;
        next = nullptr;
    }
    T value(){
        return _value;
    }
};

template <typename T>
class SingleLinkedOrderedList {

private:
    SingleLinkedOrderedNode<T> * head;
    SingleLinkedOrderedNode<T> * tail;
public:
    using value_type = T;
    SingleLinkedOrderedList() {
        head = tail = nullptr;
    }
    void print() {
        auto cur = head;
        while (cur != nullptr) {
            std::cout << cur->_value << " ";
            cur = cur->next;
        }
        std::cout << "\n";
    }
    void insert(T data) {
        if (head == nullptr) {
            head = new SingleLinkedOrderedNode<T>(data);
            return;
        }
        auto node = new SingleLinkedOrderedNode<T>(data);
        if (data < head->_value) {
            node->next = head;
            head = node;
            return;
        }
        auto cur = head;
        auto prev = new SingleLinkedOrderedNode<T>;
        while (cur != nullptr && cur->_value < data) {
            prev = cur;
            cur = cur->next;
        }
        if (cur == nullptr) {
            prev->next = node;
            tail = node;
            return;
        }
        if (cur->_value == data) {
            cur->_value = data;
            delete node;
        }
        auto temp = prev->next;
        prev->next =node;
        node->next = temp;

    }

    void pop_back() {
        if (head == nullptr)
            return;
        if (head == tail)
            head = tail = nullptr;
        else {
            auto node = head;
            while (node->next != tail)
                node = node->next;
            auto temp = tail;
            tail = node;
            tail->next = nullptr;
            //delete temp;
        }
    }
    void pop_front() {
        if (head == nullptr)
            return;
        if (head == tail)
            head = tail = nullptr;
        else {
            auto temp = head;
            head = head->next;
            //delete temp;
        }
    }

    void erase(T value) {
        auto cur = head;
        auto prev = new SingleLinkedOrderedNode<T>;
        while (cur != nullptr && !(cur->_value == value)) {
            prev = cur;
            cur = cur->next;
        }
        if (cur == head)
            pop_front();
        if (cur == tail)
            pop_back();
        if (cur != nullptr) {
            prev->next = cur->next;
            //delete cur;
        }
    }

    SingleLinkedOrderedNode<T> * search(T value) {
        auto node = head;
        while (node != nullptr) {
            if (node->_value == value)
                break;
            else node = node->next;
        }
        return node;
    }

    std::vector <T> elements() {
        std::vector <T> res;
        auto node = head;
        while (node != nullptr) {
            res.push_back(node->value());
            node = node->next;
        }
        return res;
    }

};

#endif //OOP_EXAM_SINGLELINKEDORDEREDLIST_HPP
