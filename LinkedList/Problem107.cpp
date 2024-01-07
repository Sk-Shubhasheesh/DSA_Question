// Problem 107 - Rotate a LinkedList
// Problem Link: https://tinyurl.com/ye23ua58



Node* findNthNode(Node* temp, int k){
     int cnt = 1;
     while(temp!=NULL){
          if(cnt == k) return temp;
          cnt++;
          temp = temp->next;
     }
     return temp;
}
Node *rotate(Node *head, int k) {
     // Write your code here.
     if(head == NULL || k == 0) return head;
     Node* tail = head;
     int len = 1;
     while(tail->next != NULL){
          tail = tail->next;
          len +=1;
     }
     if(k%len == 0) return head;
     k = k%len;
     tail->next = head;
     Node* newLastNode = findNthNode(head, len-k);
     head = newLastNode->next;
     newLastNode->next = NULL;
     return head;
}