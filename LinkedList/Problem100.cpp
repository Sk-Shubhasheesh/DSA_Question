// Problem 100 - Find the length of the Loop in LinkedList
// Problem Link: https://tinyurl.com/5n78kcda

// Bruteforce using map
#include <bits/stdc++.h>
int lengthOfLoop(Node *head) {
    // Write your code here
    unordered_map<Node*, int> nodePositionMap;

    Node* current = head;
    int position = 0;

    while (current != nullptr) {
        // If the current node is already visited, it means there is a cycle
        if (nodePositionMap.find(current) != nodePositionMap.end()) {
            int cycleStart = nodePositionMap[current];
            return position - cycleStart;
        }

        nodePositionMap[current] = position;
        current = current->next;
        position++;
    }

    // No cycle found
    return 0;
}

// Optimal using Tortoise-Hare-Approach
int count(Node* slow, Node*fast){
    int cnt = 1;
    fast = fast->next;
    while(fast != slow){
        cnt++;
        fast = fast->next;
    }
    return cnt;
}
int lengthOfLoop(Node *head) {
    // Write your code here
    Node* fast = head;
    Node* slow = head;
    while(fast!=NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(fast == slow) return count(slow, fast);
    }
    return 0;
}