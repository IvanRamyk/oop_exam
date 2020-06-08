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
    int cnt_nodes{};
public:
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
        while (cur->value < data) {

        }


    }
    void pop_back() {
        if (head == nullptr)
            return;
        cnt_nodes--;
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
        cnt_nodes--;
        if (head == tail)
            head = tail = nullptr;
        else {
            auto temp = head;
            head = head->next;
            delete temp;
        }
    }
    void erase(int pos) {
        if (pos >= cnt_nodes)
            return;
        if (pos == 0)
            pop_front();
        else if (pos == cnt_nodes - 1)
            pop_back();
        else {
            cnt_nodes--;
            auto prev = new SingleLinkedNode<T>;
            auto node = head;
            for (int i = 0; i < pos; ++i) {
                prev = node;
                node = node->next;
            }
            prev->next = node->next;
            delete node;
        }
    }

    T select(int pos) {
        auto node = head;
        for (int i = 0; i < pos; ++i)
            node = node->next;
        return node->value;
    }

    int size() {
        return cnt_nodes;
    }
};

#endif //OOP_EXAM_SINGLELINKEDORDEREDLIST_HPP
