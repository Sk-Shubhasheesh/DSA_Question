// Problem - Merge k sorted lists
// Problem link - https://www.codingninjas.com/studio/problems/merge-k-sorted-lists_992772?interviewProblemRedirection=true&leftPanelTabValue=PROBLEM
Node* mergeKLists(vector<Node*> &listArray){
    // Write your code here.
    priority_queue<pair<int, Node*>,
    vector<pair<int, Node*>>, greater<pair<int, Node*>>> pq;
    for(int i=0; i<listArray.size(); i++){
        if(listArray[i]){
            pq.push({listArray[i]->data, listArray[i]});
        }
    }
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        if(it.second->next){
            pq.push({it.second->next->data, it.second->next});
        }
        temp->next = it.second;
        temp = temp->next;
    }
    return dummyNode->next;
}
