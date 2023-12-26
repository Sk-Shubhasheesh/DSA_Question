// Problem 76 - Serch element in LinkedList
// Problem link - https://tinyurl.com/27c9b349 

int searchInLinkedList(Node<int> *head, int k) {
    // Write your code here.
    Node<int>* temp = head;
    while(temp){
        if(temp-> data == k) return 1;
       temp = temp->next;
       
    }
}