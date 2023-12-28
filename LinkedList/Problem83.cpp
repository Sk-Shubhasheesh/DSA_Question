// Problem 83 - Delete Head of a Doubly Linked List
// Problem link - https://tinyurl.com/mubc6f26
// Function to delete the head of the doubly linked list
Node* deleteHead(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr; 
    }

    Node* prev = head;      
    head = head->next;    
    head->back = nullptr;   
    prev->next = nullptr;  
    return head;          
}



