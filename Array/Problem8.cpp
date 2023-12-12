/*  Problem 8 - Linear Serch
Problem link - https://www.codingninjas.com/studio/problems/linear-search_6922070?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems&leftPanelTabValue=PROBLEM

*/

int linearSearch(int n, int num, vector<int> &arr)
{
    // Write your code here.
    for(int i=0; i<n; i++){
        if(arr[i] == num) return i;
       
    }
    return -1;
}