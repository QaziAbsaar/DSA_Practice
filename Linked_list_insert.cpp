#include <iostream>
using namespace std;

// Define the structure of a Node
struct Node {
    int data;
    Node* next;
};

// Function to insert a node at the beginning of the list
void insertAtBeginning(Node** head, int newData) {
    Node* newNode = new Node();  // Create a new node
    newNode->data = newData;     // Set the data
    newNode->next = *head;       // Point the new node's next to the current head
    *head = newNode;             // Update head to point to the new node
}

// Function to insert a node at the end of the list
void insertAtEnd(Node** head, int newData) {
    Node* newNode = new Node();  // Create a new node
    newNode->data = newData;
    newNode->next = nullptr;     // The new node will be the last node, so its next is null

    if (*head == nullptr) {
        // If the list is empty, the new node becomes the head
        *head = newNode;
    } else {
        // Otherwise, traverse to the last node and append the new node
        Node* temp = *head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAtPosition(Node** head, int newData, int position) {
    // Create a new node
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = nullptr;

    // If the position is 1, insert at the head
    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node* temp = *head;
    int count = 1;

    // Traverse the list until the (position-1)th node or end of the list
    while (temp != nullptr && count < position) {
        temp = temp->next;
        count++;
    }

    // If the position is beyond the current list size
    if (temp == nullptr) {
        cout << "Invalid position!" << endl;
        delete newNode;  // Free the memory allocated for the new node
        return;
    }

    // Insert the new node at the desired position
    newNode->next = temp->next;
    temp->next = newNode;
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
    Node* head = nullptr;  // Initialize an empty list

    // Insert some nodes at the beginning
    insertAtBeginning(&head, 10);
    insertAtBeginning(&head, 20);

    
    // Insert some nodes at the end
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtPosition(&head, 80 , 5);


    // Print the linked list
    cout << "Linked List: ";
    printList(head);

    return 0;
}
