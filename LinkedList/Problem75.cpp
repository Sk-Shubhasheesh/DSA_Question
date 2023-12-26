// Problem 75 - Find the length of LL or Count nodes of linked list
// Problem link - https://tinyurl.com/kvdu6t2s 


int length(Node *head)
{
	//Write your code here
    int cnt = 0;
    Node* temp = head;
    while(temp){
       temp = temp->next;
       cnt++;
    }
  