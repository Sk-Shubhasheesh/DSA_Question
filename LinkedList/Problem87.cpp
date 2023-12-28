// Problem 87 - Insert At The Front of a Doubly Linked List
// Problem link - https://tinyurl.com/58fyn6d8

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Define a Node class for doubly linked list
class Node {
public:
    int data;   
    Node* next;     
    Node* back;     
    Node(int data1, Node* next1, Node* back1) {
        data = data1;
        next = next1;
        back = back1;
    }
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

// Function to insert new node before head
Node* insertBeforeHead(Node* head, int val){
    // Create new node with data as val
    Node* newHead = new Node(val , head, nullptr);
    head->back = newHead;
    
    return newHead;
}

int main() {
    vector<int> arr = {12, 5, 8, 7, 4};
    Node* head = convertArr2DLL(arr);
    
    print(head);
    cout << endl << "Doubly Linked List After Inserting 6 before head: " << endl;
    head = insertBeforeHead(head, 6);
    print(head);

    return 0;
}