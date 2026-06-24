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

Node* insertAtHead(Node* head, int value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    return newNode;
}

Node* insertAtTail(Node* head, int value) {
    Node* newNode = new Node(value);

    if(head == NULL)
        return newNode;

    Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

Node* insertAtIndex(Node* head, int value, int index) {
    if(index == 0)
        return insertAtHead(head, value);

    Node* temp = head;

    for(int i = 0; i < index - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if(temp == NULL) {
        cout << "Invalid Index!" << endl;
        return head;
    }

    Node* newNode = new Node(value);
    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

void printList(Node* head) {
    Node* temp = head;

    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {

    Node* head = NULL;

    int n;
    cout << "Enter linked list size: ";
    cin >> n;

    cout << "Enter numbers: ";
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        head = insertAtTail(head, x);
    }

    int choice;
    cout << "\n1. Head\n2. Tail\n3. Any Index\n";
    cout << "Where do you want to insert? ";
    cin >> choice;

    if(choice == 1) {
        int value;
        cout << "Enter number you want to insert: ";
        cin >> value;

        head = insertAtHead(head, value);
    }

    else if(choice == 2) {
        int value;
        cout << "Enter number you want to insert: ";
        cin >> value;

        head = insertAtTail(head, value);
    }

    else if(choice == 3) {
        int index, value;

        cout << "Enter index you want to insert: ";
        cin >> index;

        cout << "Enter number you want to insert: ";
        cin >> value;

        head = insertAtIndex(head, value, index);
    }

    cout << "Final List: ";
    printList(head);

    return 0;
}
