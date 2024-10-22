**Doubly Linked Lists**

### What is a Doubly Linked List (DLL)?

A **doubly linked list (DLL)** is a type of **linked list** in which each node contains three fields:
1. **Data**: The value stored in the node.
2. **Next Pointer**: A pointer to the **next node** in the sequence.
3. **Previous Pointer**: A pointer to the **previous node** in the sequence.

This allows traversal in **both directions** (forward and backward) through the list, unlike a **singly linked list**, where traversal is only possible in one direction.

---

### Structure of a Doubly Linked List Node:

In a doubly linked list, each node contains:
1. **Data**: The actual information (e.g., an integer, a string, etc.).
2. **Next Pointer**: A pointer to the next node in the list.
3. **Previous Pointer**: A pointer to the previous node in the list.

In C++, this structure can be represented like this:

```cpp
struct Node {
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node
    Node* prev;     // Pointer to the previous node
};
```

---

### Basic Operations on a Doubly Linked List

#### 1. **Insertion**: 
   - **At the Beginning**: Insert a new node at the head of the list.
   - **At the End**: Insert a new node at the end of the list.
   - **At a Specific Position**: Insert a new node at a given position in the list.

#### 2. **Deletion**: 
   - **From the Beginning**: Remove the node at the head of the list.
   - **From the End**: Remove the node at the tail of the list.
   - **From a Specific Position**: Remove a node from a specific position.

#### 3. **Traversal**: 
   - **Forward Traversal**: Start from the head and move toward the tail.
   - **Backward Traversal**: Start from the tail and move toward the head.

#### 4. **Searching**: 
   - Search for a node with a specific value by traversing through the list.

---

### Basic C++ Code for a Doubly Linked List

Let's go through the **implementation** of a doubly linked list in C++. We'll cover the following operations:

1. **Insertion** (at the beginning, end, and middle).
2. **Deletion** (from the beginning, end, and a specific position).
3. **Traversal** (both forward and backward).
4. **Searching** for a value in the list.

---

### Full Code Example for Doubly Linked List in C++

```cpp
#include <iostream>
using namespace std;

// Define a node structure for doubly linked list
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

// Function to insert a node at the beginning of the doubly linked list
void insertAtBeginning(Node** head, int newData) {
    Node* newNode = createNode(newData);
    
    if (*head == nullptr) {
        *head = newNode;  // If the list is empty, new node becomes the head
    } else {
        newNode->next = *head;  // Link the new node to the current head
        (*head)->prev = newNode;  // Link the current head back to the new node
        *head = newNode;  // Update the head to the new node
    }
}

// Function to insert a node at the end of the doubly linked list
void insertAtEnd(Node** head, int newData) {
    Node* newNode = createNode(newData);

    if (*head == nullptr) {
        *head = newNode;  // If the list is empty, new node becomes the head
    } else {
        Node* temp = *head;
        while (temp->next != nullptr) {  // Traverse to the last node
            temp = temp->next;
        }
        temp->next = newNode;  // Link the last node to the new node
        newNode->prev = temp;  // Link the new node back to the last node
    }
}

// Function to insert a node at a specific position
void insertAtPosition(Node** head, int newData, int position) {
    if (position <= 1) {
        insertAtBeginning(head, newData);
        return;
    }

    Node* newNode = createNode(newData);
    Node* temp = *head;

    // Traverse to the position just before the insertion point
    for (int i = 1; i < position - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Invalid position!" << endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Function to delete a node from the beginning
void deleteFromBeginning(Node** head) {
    if (*head == nullptr) {
        cout << "List is already empty!" << endl;
        return;
    }

    Node* temp = *head;
    *head = (*head)->next;

    if (*head != nullptr) {
        (*head)->prev = nullptr;  // Update the prev pointer of the new head
    }

    delete temp;  // Free the memory of the old head
}

// Function to delete a node from the end
void deleteFromEnd(Node** head) {
    if (*head == nullptr) {
        cout << "List is already empty!" << endl;
        return;
    }

    Node* temp = *head;
    while (temp->next != nullptr) {  // Traverse to the last node
        temp = temp->next;
    }

    if (temp->prev != nullptr) {
        temp->prev->next = nullptr;  // Update the next pointer of the previous node
    } else {
        *head = nullptr;  // If only one node was present, the list becomes empty
    }

    delete temp;  // Free the memory of the last node
}

// Function to delete a node from a specific position
void deleteFromPosition(Node** head, int position) {
    if (*head == nullptr || position <= 1) {
        deleteFromBeginning(head);
        return;
    }

    Node* temp = *head;

    // Traverse to the node at the specified position
    for (int i = 1; i < position && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Invalid position!" << endl;
        return;
    }

    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }

    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    }

    delete temp;  // Free the memory of the node at the specified position
}

// Function to search for a value in the doubly linked list
bool search(Node* head, int target) {
    while (head != nullptr) {
        if (head->data == target) {
            return true;  // Target value found
        }
        head = head->next;
    }
    return false;  // Target value not found
}

// Function to traverse and display the list forward
void displayForward(Node* head) {
    cout << "List (Forward): ";
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to traverse and display the list backward
void displayBackward(Node* tail) {
    cout << "List (Backward): ";
    while (tail != nullptr) {
        cout << tail->data << " ";
        tail = tail->prev;
    }
    cout << endl;
}

// Function to find the tail (last node) of the list
Node* findTail(Node* head) {
    if (head == nullptr) {
        return nullptr;
    }
    while (head->next != nullptr) {
        head = head->next;
    }
    return head;
}

// Main function to test the doubly linked list
int main() {
    Node* head = nullptr;

    // Insertion operations
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtBeginning(&head, 5);
    insertAtPosition(&head, 25, 4);  // Insert 25 at position 4

    // Display the list in forward and backward directions
    displayForward(head);
    Node* tail = findTail(head);
    displayBackward(tail);

    // Searching for a value
    if (search(head, 20)) {
        cout << "Value 20 found in the list." << endl;
    } else {
        cout << "Value 20 not found in the list." << endl;
    }

    // Deletion operations
    deleteFromBeginning(&head);
    deleteFromEnd(&head);
    deleteFromPosition(&head, 3);

    // Display the

 list again after deletions
    displayForward(head);
    tail = findTail(head);
    displayBackward(tail);

    return 0;
}
```

---

### Explanation of the Code:

#### **1. Node Structure**:
- The structure `Node` contains:
  - `data`: To store the value of the node.
  - `next`: A pointer to the next node.
  - `prev`: A pointer to the previous node.

#### **2. Basic Operations**:

##### **Insertion**:
- **`insertAtBeginning`**: This inserts a new node at the head of the doubly linked list. It updates both `next` and `prev` pointers appropriately.
- **`insertAtEnd`**: This inserts a new node at the end of the list. It traverses the list to the last node and appends the new node.
- **`insertAtPosition`**: This inserts a node at a specific position in the list by traversing to the correct position.

##### **Deletion**:
- **`deleteFromBeginning`**: This removes the first node from the list and updates the `prev` pointer of the new head.
- **`deleteFromEnd`**: This removes the last node by traversing to the end of the list.
- **`deleteFromPosition`**: This removes a node at a specific position by updating the `next` and `prev` pointers of the surrounding nodes.

##### **Traversal**:
- **`displayForward`**: Traverses the list from the head to the end, printing the data in each node.
- **`displayBackward`**: Traverses the list from the tail (last node) to the head, printing the data in reverse order.

##### **Searching**:
- **`search`**: This function searches for a given value in the doubly linked list and returns `true` if the value is found, otherwise returns `false`.

---

### Example Output:

```
List (Forward): 5 10 20 25 30 
List (Backward): 30 25 20 10 5 
Value 20 found in the list.
List (Forward): 10 20 25 
List (Backward): 25 20 10 
```

### Key Points:

1. **Double Pointers** (`prev` and `next`):
   - Doubly linked lists require you to maintain two pointers: one for the **next node** and one for the **previous node**.
   - This allows you to traverse the list in both directions, which is useful for operations like **reversing the list** or **traversing backward**.

2. **Advantages of Doubly Linked Lists**:
   - **Bidirectional Traversal**: You can traverse the list in both directions.
   - **Efficient Deletion**: Unlike singly linked lists, you can easily delete a node when you have a pointer to it because you can access both the previous and next nodes directly.

3. **Disadvantages**:
   - **Extra Memory**: Each node requires an extra pointer (`prev`), which uses more memory compared to singly linked lists.
   - **More Complex Operations**: When inserting or deleting nodes, both the `next` and `prev` pointers need to be updated, making the operations slightly more complex.

---

### Conclusion:

Doubly linked lists offer flexibility in traversal and modification but come at the cost of additional memory and complexity in pointer management. They are especially useful when you need **bidirectional traversal** or when you need to frequently delete nodes from both ends of the list.

*By Qazi Absaar Baseer UD DIN*