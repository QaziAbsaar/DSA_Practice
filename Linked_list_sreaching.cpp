#include <iostream>
using namespace std;

// Define the structure of a Node
struct Node {
    int data;
    Node* next;
};

// Function to insert a node at the end of the list (helper function to create the list)
void insertAtEnd(Node** head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = nullptr;

    if (*head == nullptr) {
        *head = newNode;
        return;
    }

    Node* temp = *head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Function to search for an element in the linked list
bool searchElement(Node* head, int target) {
    Node* current = head;  // Start from the head of the list
    while (current != nullptr) {
        if (current->data == target) {
            return true;    // Element found
        }
        current = current->next;  // Move to the next node
    }
    return false;  // Element not found in the list
}

// Function to print the linked list
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    // Insert some nodes into the linked list
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    // Print the linked list
    cout << "Linked List: ";
    printList(head);

    // Search for an element in the list
    int target = 20;
    if (searchElement(head, target)) {
        cout << "Element " << target << " found in the list." << endl;
    } else {
        cout << "Element " << target << " not found in the list." << endl;
    }

    // Search for an element not in the list
    target = 50;
    if (searchElement(head, target)) {
        cout << "Element " << target << " found in the list." << endl;
    } else {
        cout << "Element " << target << " not found in the list." << endl;
    }

    return 0;
}
