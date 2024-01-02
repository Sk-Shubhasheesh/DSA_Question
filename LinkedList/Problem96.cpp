// Problem 96 - Reverse a LinkedList 
//Problem Link: https://tinyurl.com/2ajt9262

Node* reverseLinkedList(Node *head)
{
    // Write your code here
     if(head == NULL || head-> next == NULL){
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    while(temp!=NULL){
        Node* front = temp->next;
        temp->next = prev;
        prev=temp;
        temp = front;
    }
    return prev;
}
