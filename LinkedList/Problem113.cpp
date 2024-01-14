 // Problem 113 -  Design a Browser History 
 // Problem Link: https://bit.ly/3tHiY6k
 class Node {
public:
    string data;
    Node* next;
    Node* back;
    Node() : data(0), next(nullptr), back(nullptr){};
    Node(string x) : data(x), next(nullptr), back(nullptr) {};
    Node(string x, Node *next, Node *random) : data(x), next(next), back(random){};

};
class Browser
{   Node* currentPage;
    public:
    
    Browser(string &homepage)
    {
        // Write you code here
        currentPage = new Node(homepage);
    }

    void visit(string &url)
    {
        // Write you code here
        Node* newNode = new Node(url);
        currentPage->next = newNode;
        newNode->back = currentPage;
        currentPage = newNode;
    }

    string back(int steps)
    {
        // Write you code here
         while(steps) {
            if(currentPage->back){
                currentPage = currentPage->back;
            } else break;
            steps--;
        }
        return currentPage->data;
    }

    string forward(int steps)
    {
        // Write you code here
         while(steps) {
            if(currentPage->next){
                currentPage = currentPage->next;
            } else break;
            steps--;
        }
        return currentPage->data;
       
    }
};