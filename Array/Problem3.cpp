/* Problem 3 - Check Sorted Array
Problem link -  https://www.codingninjas.com/studio/problems/ninja-and-the-sorted-check_6581957?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems
*/

// Solution
int isSorted(int n, vector<int> a) {
    // Write your code here.
    for(int i=1; i<n; i++){
        if(a[i]>= a[i-1]){

        }
        else {return false;}
    }
    return true;
}
