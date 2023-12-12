/*    Problem 10 - Intersection of two sorted arrays
      Problem link - https://www.codingninjas.com/studio/problems/intersection-of-2-arrays_1082149?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems


*/


// Bruteforce
#include<bits/stdc++.h>
using namespace std;

  vector<int> intersectionOfArrays(vector<int>A, vector<int>B){
    
  vector <int> ans;
  
  // to maintain visited
  vector <int> visited(B.size(), 0);  
  int i = 0, j = 0;
  
  for (i = 0; i < A.size(); i++) {
      
    for (j = 0; j < B.size(); j++) {

      if (A[i] == B[j] && visited[j] == 0) { 
      
        //if element matches and has not been matched with any other before
        ans.push_back(B[j]);
        visited[j] = 1;

        break;
      } 
      
      else if (B[j] > A[i]) break; 
      //because array is sorted , element will not be beyond this
    }
  }
  
  return ans;
    
}

int main() {
    
  // Array Initialisation.
  vector < int > A {1,2,3,3,4,5,6,7};
  vector < int > B {3,3,4,4,5,8};

  vector<int> ans = intersectionOfArrays(A,B);
  
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }

  return 0;
}

// Optimal Solution
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
	// Write your code here.
    int i = 0 , j = 0;
    vector<int>ans;
    while(i<n && j<m){
        if(arr1[i]==arr2[j]){
            ans.push_back(arr1[i]);
            i++;
            j++;
        } else if(arr1[i]<arr2[j]){
            i++;
        } else{
            j++;
        }
    }
    return ans;
}