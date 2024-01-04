// Problem 102 - Find the starting point of the Loop/Cycle in LinkedList 
// Problem link - Problem Link: https://tinyurl.com/4c5a64xv

Node *firstNode(Node *head)
{
    //    Write your code here.
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast){
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}