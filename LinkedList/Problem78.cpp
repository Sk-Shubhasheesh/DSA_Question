// Problem 78 - Delete Tail Node Of Linked List
// Problem link - https://tinyurl.com/4rejnxbw

Node *deleteLast(Node *list){
    // Write your code here
    if(list == NULL || list->next == NULL) return NULL;
    Node* temp = list;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return list;
}