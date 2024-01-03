// Problem 101 - Delete Middle Node of LL
// Problem Link: https://tinyurl.com/y2r52yz8

// Optimal using Tortoise-Hare-Approach
Node* deleteMiddle(Node* head){
    // Write your code here.
    if(head == NULL || head->next == NULL) return NULL;
    Node* slow = head;
    Node* fast = head; // skip one step of slow and moving fast
    fast= fast->next->next;
    while(fast!=NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* temp = slow->next;
    slow->next = slow->next->next;
    delete (temp);
    return head;
}
