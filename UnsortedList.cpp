#include "UnsortedList.h"

template<class T>
UnsortedList<T>::UnsortedList() {
    head = nullptr;
    currPos = nullptr;
    length = 0;
}

template<class T>
UnsortedList<T>::~UnsortedList() {
    MakeEmpty();
}

template<class T>
void UnsortedList<T>::MakeEmpty() {

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    length = 0;
}

template<class T>
bool UnsortedList<T>::IsFull() const {

    try {
        Node* temp = new Node;
        delete temp;
    }
    catch (...) {
        return true;
    }
    return false;
}

template<class T>
int UnsortedList<T>::GetLength() const {
    return length;
}

template<class T>
bool UnsortedList<T>::Contains(T someItem) {

    Node* currNode = head;

    while (currNode != nullptr) {
        if (currNode->value == someItem) {
            return true;
        }
        currNode = currNode->next; // move to next item
    }
    return false;
}

template<class T>
void UnsortedList<T>::AddItem(T item) {

    if (IsFull())
        return;

    Node* nodeToAdd = new Node;
    nodeToAdd->value = item;
    nodeToAdd->next = head;
    head = nodeToAdd;
    length++;

}

template<class T>
void UnsortedList<T>::DeleteItem(T item) {

    Node* currNode = head;
    Node* prevNode = nullptr;

    while (currNode != nullptr) {
        if (currNode->value == item) {
            if (head == currNode) {
                head = currNode->next;
            }
            else {
                prevNode->next = currNode->next;
            }
            delete currNode;
            length--;
            return;
        }
        prevNode = currNode;
        currNode = currNode->next; //move to next node
    }
}

template<class T>
void UnsortedList<T>::ResetIterator() {
    currPos = head;
}

template<class T>
T UnsortedList<T>::GetNextItem() {
    T itemToReturn = currPos->value;
    currPos = currPos->next;
    return itemToReturn;
}
