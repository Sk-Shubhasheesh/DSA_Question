// Problem 86 - Delete the given node from the Doubly Linked List
// Problem link - https://tinyurl.com/2aady8f7
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Define a Node class for doubly linked list
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
   // Create the head node with the first element of the array
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


void deleteNode(Node* temp){
    Node* prev = temp->back;
    Node* front = temp->next;
    
    // edge case if temp is the tail node
    if(front==NULL){
        prev->next = nullptr;
        temp->back = nullptr;
        free (temp);
        return;
    }
    prev->next = front;
    front->back = prev;
    temp->next = nullptr;
    temp->back = nullptr;
    free(temp);
    return;
}



int main() {
    vector<int> arr = {12, 5, 8, 7, 4};
    Node* head = convertArr2DLL(arr);
    
    print(head);
    cout << endl << "Doubly Linked List after node with data '5' is removed: " << endl;
    deleteNode(head->next);
    print(head);

    return 0;
}