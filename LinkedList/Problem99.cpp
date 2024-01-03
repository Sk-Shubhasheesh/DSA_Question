// Problem 99 - Detect a loop or cycle in LinkedList
// Problem Link: https://tinyurl.com/3rxwup5c


// BruteForce Approach using Hashmap
#include <bits/stdc++.h>
bool detectCycle(Node *head)
{
	//	Write your code here
    unordered_set<Node*> hashTable;
    while(head != NULL) {
        if(hashTable.find(head) != hashTable.end()) return true;
        hashTable.insert(head);
        head = head->next;
    }
    return false;
}
// Optimal Approach using Tortoise-Hare-Approach
bool detectCycle(Node *head)
{
	//	Write your code here
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast) return true;
    }
    return false;
}