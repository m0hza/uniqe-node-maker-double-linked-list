Doubly Linked List Implementation in C++
This C++ program implements a basic doubly linked list with various operations like adding nodes, deleting nodes, and printing the list. The code is designed to be easy to understand and maintain, with meaningful variable names and helper functions to simplify operations.

Features:
Appending nodes to the list: The addtolast() function adds a new node to the end of the list.
Adding nodes to the beginning: The appeand() function inserts a node at the beginning of the list.
Inserting nodes at specific positions: The InPlace() function allows inserting a node at any given position within the list.
Deleting nodes by value or position: The deletebydata() and deletebypos() functions enable the removal of nodes either by their value or by their position in the list.
Summing even numbers: The evensum() function calculates and displays the sum of all even numbers in the list.
Destruction of the list: The destroy() function deletes all nodes and frees up memory.
Key Components:
1. Node Structure:
The node structure is the building block of the doubly linked list. It contains:

data: The value stored in the node.
next: A pointer to the next node in the list.
prev: A pointer to the previous node in the list.
cpp
Copy code
struct node {
    int data;
    node* next;
    node* prev;
    node() { next = prev = nullptr; data = 0; }
};
2. Node Maker Function:
The nodemaker() function is a helpful utility that simplifies the creation of new nodes. This function initializes the node's data and sets its next and prev pointers to nullptr. This encapsulation makes it easier to create and manage nodes.

cpp
Copy code
node* nodemaker(int v) {
    node* NewNode = new node();
    NewNode->data = v;
    NewNode->next = nullptr;
    NewNode->prev = nullptr;
    return NewNode;
}
3. Linked List Class:
The linkedlist class manages the doubly linked list operations. The class contains:

A head pointer to the first node.
A tail pointer to the last node.
A counter variable to keep track of the number of nodes in the list.
It provides various operations like adding, deleting, printing, and calculating the sum of even nodes, as described in the Features section.

4. Meaningful Variable Names:
The variables used throughout the program have meaningful names that clearly describe their purpose:

head: Points to the first node in the list.
tail: Points to the last node in the list.
counter: Tracks the number of nodes in the list.
finder, mover, summer, ToBeDeleted, etc., are used as temporary pointers during the list traversal or manipulation, making it clear what their role is in each operation.
5. Main Program:
The main() function drives the program by asking the user for input and offering options to interact with the linked list. It allows the user to:

Add nodes at various positions.
Delete nodes by data or position.
Print the list or destroy it.
