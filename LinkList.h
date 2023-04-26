//
//  LinkList.h
//  Polynomial
//
//  Created by 小雪糕 on 2023/4/26.
//

#ifndef LinkList_h
#define LinkList_h

#include <iostream>
#include <vector>
using namespace std;

template <class T>
struct Node {
    T data;
    Node<T> *next;
};

template <class T>
class LinkList {
private:
    Node<T> *head;
    int length;
public:
    LinkList();
    LinkList(vector<T> &, int);
    ~LinkList();
    void insert_data(T, int);
    T drop_data(int);
    T get_data(int);
    vector<int> get_pos(T);
    int get_length();
    void print_all();
};

template <class T>
LinkList<T>::LinkList() {
    length = 0;
    head = NULL;
}

template <class T>
LinkList<T>::LinkList(vector<T> &array, int N) {
    length = N;
    head = new Node<T>;
    Node<T> *p = head;
    int cnt(0);
    for (auto i : array) {
        cnt++;
        p->data = i;
        if (cnt == N) {
            p->next = NULL;
        }
        else {
            p->next = new Node<T>;
            p = p->next;
        }
    }
}

template <class T>
LinkList<T>::~LinkList() {
    Node<T> *p = head;
    while (p) {
        Node<T> *temp = p;
        p = p->next;
        delete temp;
        temp = NULL;
    }
    p = NULL;
    head = NULL;
}

template <class T>
void LinkList<T>::insert_data(T data, int pos) {
    Node<T> *p = head;
    while (pos > 2) {
        pos--;
        p = p->next;
    }
    Node<T> *temp = new Node<T>;
    temp->data = data;
    if (pos == 1) {
        temp->next = p;
        head = temp;
    }
    else {
        temp->next = p->next;
        p->next = temp;
    }
    length++;
}

template <class T>
T LinkList<T>::drop_data(int pos) {
    T res;
    Node<T> *p = head;
    while (pos > 2) {
        pos--;
        p = p->next;
    }
    Node<T> *temp = p->next;
    if (pos == 1) {
        res = p->data;
        delete p;
        p = NULL;
        head = temp;
    }
    else {
        p->next = temp->next;
        res = temp->data;
        delete temp;
        temp = NULL;
    }
    length--;
    return res;
}

template <class T>
T LinkList<T>::get_data(int pos) {
    Node<T> *p = head;
    while (--pos) {
        p = p->next;
    }
    return p->data;
}

template <class T>
vector<int> LinkList<T>::get_pos(T data) {
    Node<T> *p = head;
    vector<int> vec;
    for (int i = 1; i <= length; i++) {
        if (p->data == data) {
            vec.push_back(i);
        }
        p = p->next;
    }
    return vec;
}

template <class T>
int LinkList<T>::get_length() {
    return length;
}

template <class T>
void LinkList<T>::print_all() {
    Node<T> *p = head;
    while (p) {
        cout << p->data << ' ';
        p = p->next;
    }
    cout << endl;
}

#endif /* LinkList_h */
