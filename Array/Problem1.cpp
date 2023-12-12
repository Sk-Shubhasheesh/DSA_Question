/* Problem 1 - Largest Element in the Array
Problem link - https://www.codingninjas.com/studio/problems/largest-element-in-the-array-largest-element-in-the-array_5026279
*/

// Solution
#include <bits/stdc++.h> 
int largestElement(vector<int> &arr, int n) {
    // Write your code here.
    int largest = arr[0];
    for(int i=1; i<n; i++){
        if(arr[i]>largest) largest = arr[i];
    }
    return largest;
}
