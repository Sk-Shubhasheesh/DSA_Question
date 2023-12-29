// Problem 90 - Insert at end of Doubly Linked List
// Problem link - https://tinyurl.com/26yh8tv7

Node * insertAtTail(Node *head, int k) {
    // Write your code here
    if(head == NULL) return new Node(k);
    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    Node* newNode = new Node(k, nullptr, tail);
    tail->next = newNode;
    return head;
}