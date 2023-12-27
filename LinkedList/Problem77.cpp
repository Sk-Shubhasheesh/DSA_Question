// Problem 77 -  Delete Head of a Given Linked List
// Problem link - https://www.codingninjas.com/studio/problems/delete-head-of-a-given-linked-list_9941216

Node * deleteHead(Node *head) {
    // Write your code here.
    if(head == NULL) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}