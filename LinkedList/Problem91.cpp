// Problem 91 - Reverse a DLL 
// Problem Link -https://tinyurl.com/mw45vuf6

// Bruteforce using Stack - Time Complexity : O(2N)

#include <bits/stdc++.h>
using namespace std;
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
Node* reverseDLL(Node* head){
    if(head==NULL || head->next == NULL){
        return head;
    }
    stack<int> st;
    Node* temp = head;
    while(temp!=NULL){
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while(temp!=NULL){
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}

int main() {
    vector<int> arr = {12, 5, 8, 7, 4};
    Node* head = convertArr2DLL(arr);
    cout << endl << "Doubly Linked List Initially:  " << endl;
    print(head);
    cout << endl << "Doubly Linked List After Reversing " << endl;
    
     // Insert a node with value 10 at the end
    head = reverseDLL(head);
    print(head);
}



// Optimal 
Node* reverseDLL(Node* head)
{   
    // Write your code here 
    if(head==NULL || head->next==NULL) return head;
    Node* last = NULL;
    Node* curr = head;
    while(curr!=NULL){
        last = curr->prev;
        curr->prev = curr->next;
        curr->next = last;
        curr = curr->prev; 
    }
    return last->prev;
}