#include <iostream>
using namespace std;

// Define the structure of a Node
struct Node {
    int data;
    Node* next;
};

// Function to insert a node at the end of the list
void insertAtEnd(Node** head, int newData) {
    Node* newNode = new Node();  // Create a new node
    newNode->data = newData;     // Set the data
    newNode->next = nullptr;     // Set next to null (end of list)

    if (*head == nullptr) {
        // If the list is empty, make the new node the head
        *head = newNode;
    } else {
        // Otherwise, find the last node and append the new node
        Node* temp = *head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to delete a node by value
void deleteNode(Node** head, int key) {
    if (*head == nullptr) return;  // If the list is empty, do nothing

    // Case 1: The node to delete is the head
    if ((*head)->data == key) {
        Node* temp = *head;        // Temporarily store the head node
        *head = (*head)->next;     // Move the head to the next node
        delete temp;               // Free the old head
        return;
    }

    // Case 2: Find the node to delete (which is not the head)
    Node* current = *head;
    while (current->next != nullptr && current->next->data != key) {
        current = current->next;   // Traverse the list to find the node
    }

    // If the node was not found
    if (current->next == nullptr) {
        cout << "Node with value " << key << " not found." << endl;
        return;
    }

    // Case 3: Node is found, delete it
    Node* temp = current->next;    // Store the node to delete
    current->next = temp->next;    // Unlink the node
    delete temp;                   // Free the memory
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

    // Insert some nodes
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    // Print the initial list
    cout << "Original Linked List: ";
    printList(head);

    // Delete the node with value 20
    deleteNode(&head, 20);
    cout << "After deleting 20: ";
    printList(head);

    // Delete the head node (10)
    deleteNode(&head, 10);
    cout << "After deleting 10 (head): ";
    printList(head);

    // Try to delete a node that doesn't exist
    deleteNode(&head, 100);
    cout << "After attempting to delete 100: ";
    printList(head);

    return 0;
}
