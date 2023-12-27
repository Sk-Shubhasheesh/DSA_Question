// Problem 81 - Insert at End/Tail of LL
// Problem link - https://www.codingninjas.com/studio/problems/insert-at-end_9886933
Node* insertEnd(Node* head, int k) {
    // Write your code here.
    if(head == NULL){
        return new Node(k);
    }
    Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    Node* newNode = new Node(k);
    temp->next = newNode;
    return head;
}