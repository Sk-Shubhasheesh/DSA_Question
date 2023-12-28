// Problem 84 - Delete Last Node of a Doubly Linked List
// Problem link - https://tinyurl.com/c97uemyx

Node* deleteTail(Node* head) {
    if (head == nullptr || head->next == nullptr) {
     // If the list is empty or has only one node, return null
        return nullptr;  
    }
    
    Node* tail = head;
    while (tail->next != nullptr) {
     // Traverse to the last node (tail)
        tail = tail->next; 
    }
    
    Node* newTail = tail->back;
    newTail->next = nullptr;
    tail->back = nullptr;
    delete tail;  
    
    return head;
}