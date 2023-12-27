// Problem 79 - Delete a Node from Kth position of Linked List
// Problem link - https://www.codingninjas.com/studio/problems/delete-node-in-ll_5881
Node *deleteNode(Node *head, int pos)
{
    // Write your code here.
	int k = pos;
	if (head == NULL)
        return head;

    // If k is 1, delete the first node
    if (k == 0) {
        Node* temp = head;
        head = head->next;
        delete (temp);
        return head;
    }

    // Traverse the list to find the k-th node
    Node* temp = head;
    Node* prev = NULL;
    int cnt = 0;

    while (temp != NULL) {
        cnt++;
        // If the k-th node is found
        if (cnt == k+1) {
            // Adjust the pointers to skip the k-th node
            prev->next = prev->next->next;
            // Delete the k-th node
            delete temp;
            break;
        }
        // Move to the next node
        prev = temp;
        temp = temp->next;
    }

    return head;
}