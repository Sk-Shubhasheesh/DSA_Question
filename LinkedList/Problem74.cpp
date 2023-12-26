// Problem 74 - Traversa a LinkedList

#include<bits/stdc++.h>
using namespace std;
class Node{
    public: // access modifier
    int data; // the data value
    Node* next; // the pointer to the next value
    public:
    Node (int data1){
        data=data1;  // Initialize data with the provided value
        next=nullptr;  // Initialize next as null since it's the end of the list

    }
};
Node* constructLL(vector<int>& arr) {
    // Write your code here
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
    
}
int main(){
    vector<int> arr={2,5,8,7};
    Node* head = constructLL(arr);
    Node* temp = head;
    while(temp){
       cout << temp->data << " ";
       temp = temp->next;
    }
    
}