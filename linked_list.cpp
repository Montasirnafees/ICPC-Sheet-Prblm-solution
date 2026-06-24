#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};

void printList(Node* head) {
    Node* temp = head;

    while(temp != NULL) {
        cout << temp->value<<" ";
        temp = temp->next;
    }
    cout << endl;
}

// Create original list: 10 -> 20 -> 30 -> 60 -> 100
Node* createList() {

    Node* head = new Node;
    head->value = 10;
    head->next = NULL;

    Node* node2 = new Node;
    node2->value = 20;
    node2->next = NULL;
    head->next = node2;

    Node* node3 = new Node;
    node3->value = 30;
    node3->next = NULL:
    node2->next = node3;

    Node* node4 = new Node;
    node4->value = 60;
    node4->next = NULL;
    node3->next = node4;

    Node* node5 = new Node;
    node5->value = 100;
    node5->next = NULL;
    node4->next = node5;

    return head;
}

int main() {

    // (a) Insert 50 at beginning
    Node* head1 = createList();

    Node* newNode1 = new Node;
    newNode1->value = 50;
    newNode1->next = head1;
    head1 = newNode1;

    cout << "(a) ";
    printList(head1);

    // (b) Insert 40 after 30
    Node* head2 = createList();

    Node* temp = head2;

    while(temp != NULL && temp->value != 30) {
        temp = temp->next;
    }

    Node* newNode2 = new Node;
    newNode2->value = 40;

    newNode2->next = temp->next;
    temp->next = newNode2;

    cout << "(b) ";
    printList(head2);

    // (c) Insert 500 at end
    Node* head3 = createList();

    Node* newNode3 = new Node;
    newNode3->value = 500;
    newNode3->next = NULL;

    temp = head3;

    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode3;

    cout << "(c) ";
    printList(head3);

    return 0;
}
