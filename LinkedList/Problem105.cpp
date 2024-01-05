// Problem 105 - Remove duplicates from sorted DLL
// Problem Link: https://tinyurl.com/5n8ndcuu
Node * removeDuplicates(Node *head)
{
    // Write your code here
    Node* temp = head;
    while(temp!=NULL && temp->next != NULL){
        Node* newNode= temp->next;
        while(newNode != NULL && newNode->data == temp->data){
            newNode = newNode->next;
        }
        temp->next = newNode;
        if(newNode) newNode->prev = temp;
        temp = temp->next;
    }
    return head;
}