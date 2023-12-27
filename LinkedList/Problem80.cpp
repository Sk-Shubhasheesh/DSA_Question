//  Problem 80 - Insert Node At The Beginning
// Problem link - https://tinyurl.com/2bkezeab

Node* insertAtFirst(Node* list, int newValue) {
    // Write your code here
    Node* temp = new Node(newValue, list);
    return temp;
}