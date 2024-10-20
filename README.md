### Singly Linked List - Theory and Concepts

A **singly linked list** is one of the most fundamental types of **linked lists**, which is a dynamic data structure used to store a sequence of elements. Unlike arrays, where elements are stored contiguously in memory, in a linked list, each element (called a **node**) is stored in a **separate memory location** and linked together by pointers.

Let's break down the theory of **singly linked lists** step by step.

---

### 1. **Definition of a Singly Linked List:**

A **singly linked list** is a collection of nodes where each node contains:
1. **Data**: The value of the node.
2. **Next Pointer**: A reference (or pointer) to the next node in the sequence.

The **first node** is called the **head** of the linked list, and the **last node** points to `nullptr` (or `NULL`), indicating the end of the list.

**Key Points**:
- In a singly linked list, each node only knows about the next node, not the previous one.
- Singly linked lists are **dynamic**: they can grow and shrink in size by adding or removing nodes, without needing to allocate or reallocate memory for the entire list like arrays.
  
---

### 2. **Basic Structure of a Node:**

In a singly linked list, each element is represented by a **node**. A node is an object or structure that contains two fields:
- **Data**: Stores the actual value of the node.
- **Next Pointer**: Stores the address of the next node in the list.

Here's how a typical node is represented in C++:

```cpp
struct Node {
    int data;      // The value stored in the node
    Node* next;    // Pointer to the next node in the list
};
```

---

### 3. **Operations on Singly Linked Lists:**

Here are some of the common operations you can perform on a singly linked list:

#### **i. Insertion**
- **At the Beginning**: Adding a node at the head of the list.
- **At the End**: Adding a node at the tail of the list.
- **In the Middle**: Adding a node at a specific position in the list.

#### **ii. Deletion**
- **From the Beginning**: Removing the node from the head.
- **From the End**: Removing the last node (which requires traversing the entire list).
- **From the Middle**: Removing a node from a specific position.

#### **iii. Traversal**
- Visiting each node in the list, starting from the head, and accessing the data stored in each node.

#### **iv. Searching**
- Searching for a specific value by traversing the list and comparing the data in each node.

#### **v. Reversal**
- Reversing the order of nodes in the list, so that the last node becomes the head, and the head becomes the last node.

---

### 4. **Advantages of Singly Linked Lists:**

1. **Dynamic Size**: Linked lists are dynamic in nature, meaning they can easily grow or shrink as needed (unlike arrays, which are fixed in size after allocation).
   
2. **Efficient Insertions/Deletions**: Inserting or deleting a node at the beginning or middle of a linked list can be done in `O(1)` time (if you have a pointer to the node), while insertions or deletions in arrays typically take `O(n)` due to shifting elements.

3. **Memory Efficiency**: A linked list doesn't require pre-allocation of memory like an array. It uses exactly as much memory as required for the number of nodes.

---

### 5. **Disadvantages of Singly Linked Lists:**

1. **No Random Access**: In arrays, you can directly access an element by its index in constant time `O(1)`. In linked lists, to access a specific node, you need to **traverse** the list from the head, which takes `O(n)` time in the worst case.

2. **Memory Overhead**: Each node in a linked list requires extra memory for storing the pointer to the next node. This can add up when dealing with large lists.

3. **Slower Search Time**: To search for a value in a singly linked list, you must traverse the list from the head, which takes `O(n)` time. In contrast, searching in an array is faster with techniques like **binary search** (`O(log n)`), assuming the array is sorted.

---

### 6. **Applications of Singly Linked Lists:**

- **Dynamic Memory Allocation**: Singly linked lists are often used in memory management systems where memory is allocated and deallocated dynamically.
  
- **Implementing Stacks and Queues**: Linked lists are used to implement stacks (LIFO) and queues (FIFO) because of their efficient insertions and deletions.
  
- **Undo Functionality**: Applications that require "undo" functionality (like text editors) can use linked lists to keep track of previous states.
  
- **Graph Representations**: Linked lists can be used to represent adjacency lists in graph representations.

---

### 7. **Singly Linked List vs Other Data Structures:**

- **Compared to Arrays**:
  - **Insertion/Deletion**: Faster in linked lists (`O(1)` at the head) compared to arrays (`O(n)`).
  - **Access**: Slower in linked lists (`O(n)`) compared to arrays (`O(1)`).
  - **Size**: Dynamic in linked lists, fixed in arrays (though dynamic arrays like vectors can grow, they still need to reallocate memory periodically).

- **Compared to Doubly Linked Lists**:
  - A doubly linked list has pointers to both the **next** and the **previous** nodes, allowing traversal in both directions, whereas singly linked lists can only be traversed in one direction.
  - Singly linked lists consume less memory because they store only one pointer per node, while doubly linked lists store two pointers.

---

### 8. **Singly Linked List Visualization:**

Here's a basic visual representation of a singly linked list:

```
Head --> [Data | Next] --> [Data | Next] --> [Data | Next] --> NULL
```

Where each `[Data | Next]` represents a node in the list, and `NULL` represents the end of the list.

---

### 9. **Basic Operations with C++ Code Examples**:

#### **i. Insertion at the Beginning**:
```cpp
void insertAtBeginning(Node** head, int newData) {
    // Allocate a new node
    Node* newNode = new Node();
    
    // Put in the data
    newNode->data = newData;
    
    // Make next of new node as head
    newNode->next = *head;
    
    // Move the head to point to the new node
    *head = newNode;
}
```

#### **ii. Insertion at the End**:
```cpp
void insertAtEnd(Node** head, int newData) {
    // Allocate a new node
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = NULL;
    
    // If the list is empty, make the new node as the head
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    // Traverse to the last node
    Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    
    // Change the next of last node
    last->next = newNode;
}
```

#### **iii. Deletion of a Node**:
```cpp
void deleteNode(Node** head, int key) {
    // Store head node
    Node* temp = *head;
    Node* prev = NULL;
    
    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head = temp->next;  // Change head
        delete temp;          // Free old head
        return;
    }
    
    // Search for the key to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    
    // If key was not present in the list
    if (temp == NULL) return;
    
    // Unlink the node from the linked list
    prev->next = temp->next;
    
    // Free memory
    delete temp;
}
```

#### **iv. Traversal**:
```cpp
void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}
```

---

### 10. **Summary**:

- A **singly linked list** consists of nodes, each containing data and a pointer to the next node.
- Operations like insertion, deletion, and traversal can be efficiently performed, especially when compared to arrays.
- Singly linked lists are great when frequent insertions and deletions are needed, but they have slower access times due to the lack of direct indexing.
  
*By Qazi Absaar Baseer UD DIN*
