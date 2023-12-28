// Problem 89 - Insert Before the Kth Node of a Doubly Linked List


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

void print(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";  
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


// Function to insert before the Kth element 
Node* insertBeforeKthElement(Node* head, int k, int val){
    
    if(k==1){
        // K = 1 means node has to be insert before the head
        return insertBeforeHead(head, val);
    }
    Node* temp = head;
    
    int count = 0;
    while(temp!=NULL){
        count ++;
        if(count == k) break;
        temp = temp->next;
    }
    Node* prev = temp->back;
    Node* newNode = new Node(val, temp, prev);
    prev->next = newNode;
    temp->back = newNode;
    newNode->next = temp;
    newNode->back = prev;
    return head;
}


int main() {
    vector<int> arr = {12, 5, 8, 7, 4};
    Node* head = convertArr2DLL(arr);
    
    print(head);
    cout << endl << "Doubly Linked List After Inserting val on the kth position: " << endl;
    head = insertBeforeKthElement(head, 2, 10);
    print(head);

    return 0;
}