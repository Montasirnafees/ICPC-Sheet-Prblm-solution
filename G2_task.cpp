#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

void printList(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data<<" ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {

    // Create: 10 -> 20 -> 30 -> 60 -> 100
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(60);
    head->next->next->next->next = new Node(100);

    cout << "Original List: ";
    printList(head);

    // (a) Insert 50 at beginning
    Node* newNode1 = new Node(50);
    newNode1->next = head;
    head = newNode1;

    cout << "After inserting 50 at beginning: ";
    printList(head);

    // (b) Insert 40 after 30
    Node* temp = head;

    while (temp != NULL && temp->data != 30) {
        temp = temp->next;
    }

    if (temp != NULL) {
        Node* newNode2 = new Node(40);
        newNode2->next = temp->next;
        temp->next = newNode2;
    }

    cout << "After inserting 40 after 30: ";
    printList(head);

    // (c) Insert 500 at end
    Node* newNode3 = new Node(500);

    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode3;

    cout << "After inserting 500 at end: ";
    printList(head);

    return 0;
}
