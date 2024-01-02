// Problem 97 - Check if a LinkedList is Palindrome or Not
// Problem Link: https://tinyurl.com/2p869csv
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
bool isPalindrome(Node *head)
{
    // write your code here
    if(head == NULL || head-> next == NULL)return head;
    Node* slow = head;
    Node* fast = head;
    while(fast->next != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* newHead = reverseLinkedList(slow->next);
    Node* first = head;
    Node* second = newHead;
    while(second!=NULL){
        if(first->data != second->data){
            reverseLinkedList(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }
    reverseLinkedList(newHead);
    return true;
}