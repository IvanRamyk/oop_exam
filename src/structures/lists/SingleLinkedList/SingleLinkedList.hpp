//
// Created by ivan on 08.06.20.
//

#ifndef OOP_EXAM_SINGLELINKEDLIST_HPP
#define OOP_EXAM_SINGLELINKEDLIST_HPP

#include <iostream>

template <typename T>
struct SingleLinkedNode {
    T data;
    SingleLinkedNode<T> * next;
    SingleLinkedNode() {
        next = nullptr;
    }
    explicit SingleLinkedNode(T _data) {
        data = _data;
    }
};

template <typename T>
class SingleLinkedList {
private:
    SingleLinkedNode<T> * head;
    SingleLinkedNode<T> * tail;
    int cnt_nodes{};
public:
    SingleLinkedList() {
        head = tail = nullptr;
    }
    void push_back(T data) {
        ++cnt_nodes;
        auto node  = new SingleLinkedNode<T>(data);
        if (head == nullptr) {
            head = tail = node;
        }
        else {
            tail->next = node;
            tail = node;
        }
    }
    void print() {
        auto cur = head;
        while (cur != nullptr) {
            std::cout << cur->data << " ";
            cur = cur->next;
        }
        std::cout << "\n";
    }
    void push_front(T data) {
        ++cnt_nodes;
        auto node = new SingleLinkedNode<T>(data);
        if (head == nullptr) {
            head = tail = node;
        }
        else {
            node->next = head;
            head = node;
        }
    }
    void insert(int pos, T data) {
        if (pos > cnt_nodes)
            pos = cnt_nodes;
        auto node = head;
        if (pos == 0) {
            push_front(data);
            return;
        }
        cnt_nodes++;
        for (int i = 0; i < pos - 1; ++i) {
            node = node->next;
        }
        auto new_node = new SingleLinkedNode<T>(data);
        auto next_node = node->next;
        node->next = new_node;
        new_node->next = next_node;
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
        return node->data;
    }

    int size() {
        return cnt_nodes;
    }
};

#endif //OOP_EXAM_SINGLELINKEDLIST_HPP
