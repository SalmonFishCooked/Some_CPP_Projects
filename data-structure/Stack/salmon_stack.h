#pragma once
#include <iostream>
using namespace std;

template<typename T>
struct Node
{
    T val;
    Node<T> *next;
    Node(): next(nullptr) {}
    Node(T current): val(current), next(nullptr) {}
};

//class salmon_stack
template<typename T>
class salmon_stack
{
public:
    salmon_stack();
    void push(T current_data);
    void pop();
    int size();
    bool empty();
    T top();
private:
    Node<T> *head;
    int length;
};

//functions
template<typename T>
void salmon_stack<T>::push(T current_data)
{
    Node<T> *tnode = new Node<T>(current_data);
    tnode->next = head->next;
    head->next = tnode;
    ++length;
}

template<typename T>
salmon_stack<T>::salmon_stack()
{
    head = new Node<T>;
    length = 0;
}

template<typename T>
void salmon_stack<T>::pop()
{
    if(head->next != nullptr)
    {
        Node<T> *tnode = new Node<T>;
        tnode = head->next;
        head->next = head->next->next;
        delete[] tnode;
        --length;
    }
}

template<typename T>
T salmon_stack<T>::top()
{
    if(head->next != nullptr)
    {
        return head->next->val;
    }
}

template<typename T>
int salmon_stack<T>::size()
{
    return length;
}

template<typename T>
bool salmon_stack<T>::empty()
{
    return length == 0;
}
