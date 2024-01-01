//  Odd Even Linked List || Rearrange Odd and Even Places
// Problem link -  https://tinyurl.com/47fu86tm

//Optimal Approach
Node* oddEvenList(Node* head)
{
	// Write your code here.
    if (head == NULL || head->next == NULL) 
        return head;
    Node* odd = head; 
    Node* even = head->next; 
    Node* evenHead = head->next;

    while (even != NULL && even->next != NULL) {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }

    odd->next = evenHead;
    return head;
}

