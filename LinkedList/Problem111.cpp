// Problem 111 - Sort a Linked List
// Problem Link: https://bit.ly/4aSKrTF
Node* findMiddle(Node* head){
	Node* slow = head;
	Node* fast = head->next;
	while(fast != NULL && fast->next != NULL){
		slow = slow ->next;
		fast = fast->next->next;
	}
	return slow;
}

Node* mergeTwoLists(Node* list1, Node* list2){
	Node* dummyNode = new Node(-1);
	Node* temp = dummyNode;
	while(list1!=NULL && list2!=NULL){
		if(list1 ->data < list2->data){
			temp->next = list1;
			temp = list1;
			list1 = list1->next;
		} else{
			temp->next = list2;
			temp = list2;
			list2 = list2->next;
		}
	}
	if(list1) temp->next = list1;
	else temp->next = list2;
	return dummyNode->next;
}
Node *sortLL(Node *head)
{
    // Write your code here.
	if(head == NULL || head->next == NULL) return head;
	Node* middle = findMiddle(head);
	Node* right = middle->next;
	middle->next = nullptr;
	Node* left = head;
	left = sortLL(left);
	right = sortLL(right);
	return mergeTwoLists(left, right);
}