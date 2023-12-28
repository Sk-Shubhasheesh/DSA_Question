// Problem 85 - Delete the kth node of a Doubly Linked List
// Problem link - https://tinyurl.com/ytau6hwn

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Define a Node class for doubly linked list
class Node {
public:
    int data;       // Data stored in the node
    Node* next;     // Pointer to the next node in the list (forward direction)
    Node* back;     // Pointer to the previous node in the list (backward direction)

    // Constructor for a Node with both data, a reference to the next node, and a reference to the previous node
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }

    // Constructor for a Node with data, and no references to the next and previous nodes (end of the list)
    Node(int data1) {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

// Function to convert an array to a doubly linked list
Node* convertArr2DLL(vector<int> arr) {
   // Create the head node with the first element of the array
    Node* head = new Node(arr[0]); 
   // Initialize 'prev' to the head node

    Node* prev = head;             
    for (int i = 1; i < arr.size(); i++) {
        // Create a new node with data from the array and set its 'back' pointer to the previous node
        Node* temp = new Node(arr[i], nullptr, prev);
        // Update the 'next' pointer of the previous node to point to the new node

        prev->next = temp;    
        // Move 'prev' to the newly created node for the next iteration
   
       prev = temp;         
     }
    // Return the head of the doubly linked list

    return head;  
}

// Function to print the elements of the doubly linked list
void print(Node* head) {
    while (head != nullptr) {
        // Print the data in the current node
        cout << head->data << " "; 
        // Move to the next node
        head = head->next;         
    }
}

// Function to delete the head of the doubly linked list
Node* deleteHead(Node* head) {
    if (head == nullptr || head->next == nullptr) {
      // Return NULL if the list is empty or contains only one element
        return nullptr; 
    }
    Node* prev = head;      
    head = head->next;    
    head->back = nullptr;   
    prev->next = nullptr;  
    return head;          
}

// Function to delete the tail of the doubly linked list
Node* deleteTail(Node* head) {
    if (head == nullptr || head->next == nullptr) {
     // If the list is empty or has only one node, return null
        return nullptr;  
    }
    
    Node* tail = head;
    while (tail->next != nullptr) {
     // Traverse to the last node (tail)
        tail = tail->next; 
    }
    
    Node* newTail = tail->back;
    newTail->next = nullptr;
    tail->back = nullptr;
    
    // Free memory of the deleted node
    delete tail;  
    
    return head;
}

// Function to remove the Kth element from the doubly linked list
Node* removeKthElement(Node* head, int k){
    if(head==NULL){
        return NULL;
    }
    int count = 0;
    Node* kNode = head;
    while(kNode!=NULL){
        count++;
        if(count==k){
            break;
        }
        kNode = kNode->next;
    }
    Node* prev = kNode->back;
    Node* front = kNode->next;
    
    if(prev==NULL && front == NULL){
        delete kNode;
        return NULL;
    }
    else if (prev==NULL){
        return deleteHead(head);
    }
    else if(front == NULL){
        return deleteTail(head);
    }
    
    prev->next = front;
    front->back = prev;
    
    kNode->next = NULL;
    kNode->back = NULL;
    
    delete kNode;
    
    return head;
}

int main() {
    vector<int> arr = {12, 5, 8, 7, 4};
    Node* head = convertArr2DLL(arr);
    
    print(head);
    cout << endl << "Doubly Linked List after its 3rd element is removed: " << endl;
    head = removeKthElement(head, 3);
    print(head);

    return 0;
}