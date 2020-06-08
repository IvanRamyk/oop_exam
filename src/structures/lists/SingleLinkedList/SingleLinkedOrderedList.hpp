//
// Created by ivan on 08.06.20.
//

#ifndef OOP_EXAM_SINGLELINKEDORDEREDLIST_HPP
#define OOP_EXAM_SINGLELINKEDORDEREDLIST_HPP

#include <iostream>

template <typename T>
struct SingleLinkedNode {
    T value;
    SingleLinkedNode<T> * next;
    SingleLinkedNode() {
        next = nullptr;
    }
    explicit SingleLinkedNode(T _data) {
        value = _data;
    }
};

template <typename T>
class SingleLinkedOrderedList {

private:
    SingleLinkedNode<T> * head;
    SingleLinkedNode<T> * tail;
public:
    using value_type = T;
    SingleLinkedOrderedList() {
        head = tail = nullptr;
    }
    void print() {
        auto cur = head;
        while (cur != nullptr) {
            std::cout << cur->value << " ";
            cur = cur->next;
        }
        std::cout << "\n";
    }
    void insert(T data) {
        if (head == nullptr) {
            head = new SingleLinkedNode<T>(data);
            return;
        }
        auto node = new SingleLinkedNode<T>(data);
        if (data < head->value) {
            node->next = head;
            head = node;
            return;
        }
        auto cur = head;
        auto prev = new SingleLinkedNode<T>;
        while (cur != nullptr && cur->value < data) {
            prev = cur;
            cur = cur->next;
        }
        if (cur == nullptr) {
            prev->next = node;
            tail = node;
            return;
        }
        if (cur->value == data) {
            cur->value = data;
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
            delete temp;
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
            delete temp;
        }
    }

    void erase(T value) {
        auto cur = head;
        auto prev = new SingleLinkedNode<T>;
        while (cur != nullptr && cur->value != value) {
            prev = cur;
            cur = cur->next;
        }
        if (cur == head)
            pop_front();
        if (cur == tail)
            pop_back();
        if (cur != nullptr) {
            prev->next = cur->next;
            delete cur;
        }
    }

    SingleLinkedNode<T> * search(T value) {
        auto node = head;
        while (node != nullptr)
            if (node->value == value)
                break;
            else node = node->next;
        return node;
    }

};

#endif //OOP_EXAM_SINGLELINKEDORDEREDLIST_HPP
