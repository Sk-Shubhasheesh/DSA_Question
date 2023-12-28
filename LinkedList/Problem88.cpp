// Problem 88 - Insert before the tail of a Doubly Linked List
// Problem link - https://www.codingninjas.com/studio/problems/insert-at-end-of-doubly-linked-list_10491197

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class Node {
public:
    int data;   
    Node* next;     
    Node* back;     
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
    Node* head = new Node(arr[0]);
    Node* prev = head;            

    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next = temp; 
        prev = temp;       
    }
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
Node* insertBeforeHead(Node* head, int val){
    // Create new node with data as val
    Node* newHead = new Node(val , head, nullptr);
    head->back = newHead;
    
    return newHead;
}

Node* insertBeforeTail(Node* head, int val){
    // Edge case, if dll has only one elements
    if(head->next==NULL){
        // If only one element
        return insertBeforeHead(head, val);
    }
    
    Node* tail = head;
    while(tail->next!=NULL){
        tail = tail->next;
    }
    Node* prev = tail->back;
    Node* newNode = new Node(val, tail, prev);
    prev->next = newNode;
    tail->back = newNode;
    return head;
}
int main() {
    vector<int> arr = {12, 5, 8, 7, 4};
    Node* head = convertArr2DLL(arr);
    
    print(head);
    cout << endl << "Doubly Linked List After Inserting 6 before tail: " << endl;
    head = insertBeforeTail(head, 6);
    print(head);

    return 0;
}