// Problem 112 - Clone a LinkedList with Next and Random Pointers | Copy List with Random Pointers
// Problem Link: https://tinyurl.com/ytkm6xuz
void insertCopyInBetween(Node* head){
	Node* temp = head;
	while(temp != NULL){
		Node* nextElement = temp->next;
		Node* copy = new Node(temp->data);
		copy->next = nextElement;
		temp->next = copy;
		temp = nextElement;
	}
}
void connectRandomPointers(Node* head){
	Node* temp = head;
	while(temp!=NULL){
		Node* copyNode = temp->next;
		if(temp->random) copyNode->random = temp->random->next;
		else copyNode->random = nullptr;
		temp = temp->next->next;
	}
}
Node* getDeepCopyList(Node* head){
	Node* temp = head;
	Node* dummyNode = new Node(-1);
	Node* res = dummyNode;
	while(temp != NULL){
		res->next = temp->next;
		res = res->next;
		// disconnecting and going back inital state of LL
		temp ->next = temp->next->next;
		temp = temp->next;
	}
	return dummyNode->next;
}
Node *cloneLL(Node *head){
	// Write your code here
	insertCopyInBetween(head);
	connectRandomPointers(head);
	return getDeepCopyList(head);
}