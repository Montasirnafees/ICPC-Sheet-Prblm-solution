#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};

void printList(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->value<<" ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {

    // Create: 10 -> 20 -> 30 -> 60 -> 100

    Node* head = new Node;
    head->value = 10;
    head->next = NULL;

    Node* node2 = new Node;
    node2->value = 20;
    node2->next = NULL;
    head->next = node2;

    Node* node3 = new Node;
    node3->value = 30;
    node3->next = NULL;
    node2->next = node3;

    Node* node4 = new Node;
    node4->value = 60;
    node4->next = NULL;
    node3->next = node4;

    Node* node5 = new Node;
    node5->value = 100;
    node5->next = NULL;
    node4->next = node5;

    cout << "Original List: ";
    printList(head);

    // (a) Insert 50 at beginning

    Node* newNode1 = new Node;
    newNode1->value = 50;
    newNode1->next = head;
    head = newNode1;

    cout << "After inserting 50 at beginning: ";
    printList(head);

    // (b) Insert 40 after 30

    Node* temp = head;

    while (temp != NULL && temp->value != 30) {
        temp = temp->next;
    }

    if (temp != NULL) {
        Node* newNode2 = new Node;
        newNode2->value = 40;

        newNode2->next = temp->next;
        temp->next = newNode2;
    }

    cout << "After inserting 40 after 30: ";
    printList(head);

    // (c) Insert 500 at end

    Node* newNode3 = new Node;
    newNode3->value = 500;
    newNode3->next = NULL;

    temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode3;

    cout << "After inserting 500 at end: ";
    printList(head);

    return 0;
}
