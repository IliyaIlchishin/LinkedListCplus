#include <iostream>
#include <string>
using namespace std;

class LinkedList {
private:
    class Node {
    public:
        int value;
        Node* nextNode;
    };

    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    ~LinkedList() {
        Node* node = head;
        while (node != nullptr) {
            Node* nextNode = node->nextNode;
            delete node;
            node = nextNode;
        }
    }

    void addLast(int value) {
        Node* node = new Node();
        node->value = value;
        node->nextNode = nullptr;
        if (head == nullptr) {
            head = node;
        } else {
            tail->nextNode = node;
        }
        tail = node;
    }

    void add(int value, Node* previousNode) {
        if (previousNode == nullptr) {
            addLast(value);
            return;
        }
        Node* node = new Node();
        node->value = value;
        node->nextNode = previousNode->nextNode;
        previousNode->nextNode = node;
        if (previousNode == tail) {
            tail = node;
        }
    }

    void push(int value) {
        Node* node = new Node();
        node->value = value;
        node->nextNode = head;
        head = node;
        if (tail == nullptr) {
            tail = head;
        }
    }

    int pop() {
        if (head == nullptr) {
            throw std::runtime_error("Stack is empty");
        }
        int result = head->value;
        Node* node = head;
        head = head->nextNode;
        delete node;
        if (head == nullptr) {
            tail = nullptr;
        }
        return result;
    }

    void reverse() {
        Node* node = head;
        Node* temp = head;
        head = tail;
        tail = temp;
        while (node != nullptr) {
            temp = node->nextNode;
            node->nextNode = node;
            node = node->nextNode;
            node->nextNode = temp;
            node = temp;
        }
    }

    void print() {
        Node* node = head;
        while (node != nullptr) {
            std::cout << node->value << " ";
            node = node->nextNode;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList a;
    a.addLast(275);
    a.addLast(35);
    a.addLast(12);
    int b = a.pop();

    a.print();

    return 0;
}
