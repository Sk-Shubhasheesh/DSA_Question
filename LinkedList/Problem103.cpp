// Problem 103 -  Delete all occurrences of a Key in DLL
// Problem Link: https://tinyurl.com/yc7znssk
Node * deleteAllOccurrences(Node* head, int k) {
    // Write your code here
    Node* temp = head;
    while(temp!=NULL){
        if(temp->data == k){
            if(temp == head){
                head = head->next;
            }
            Node* nextNode = temp->next;
            Node* prevNode = temp->prev;
            if(nextNode != NULL) nextNode->prev = prevNode;
            if(prevNode!=NULL) prevNode->next = nextNode;
            free(temp);
            temp = temp->next;
        } else{
            temp = temp->next;
        }
    }
    return head;
}