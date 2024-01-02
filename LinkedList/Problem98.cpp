// Problem 98 - Find the middle element of the LinkedList
// Problem Link: https://tinyurl.com/ykfyj5cd


Node *findMiddle(Node *head) {
    // Write your code here
    if(head == NULL || head-> next == NULL){
        return head;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
