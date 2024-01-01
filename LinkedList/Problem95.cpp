// Problem 95 - Delete Kth Node From End
// Problem Link: https://tinyurl.com/4txecfpz

Node* removeKthNode(Node* head, int K)
{
    // Write your code here.
    Node* fast = head;
    Node* slow= head;
    for(int i=0; i<K; i++) fast = fast->next;
    if(fast == NULL) return  head->next;
    while(fast->next != NULL){
        fast = fast-> next;
        slow = slow->next;
    }
    Node* delNode = slow->next;
    slow->next = slow->next->next;
    free(delNode);
    return head;
}
