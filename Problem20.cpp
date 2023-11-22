/*   Problem 20 - Leaders in an Array
     Problem link - https://www.codingninjas.com/studio/problems/superior-elements_6783446?utm_source=striver&utm_medium=website&utm_campaign=codestudio_a_zcourse&leftPanelTabValue=SUBMISSION


*/
//BruteForce Approach



#include<bits/stdc++.h>
using namespace std;

vector<int> printLeadersBruteForce(int arr[], int n) {

  vector<int> ans;
  
  for (int i = 0; i < n; i++) {
    bool leader = true;

    //Checking whether arr[i] is greater than all 
    //the elements in its right side
    for (int j = i + 1; j < n; j++)
      if (arr[j] > arr[i]) {
          
        // If any element found is greater than current leader
        // curr element is not the leader.
        leader = false;
        break;
      }

    // Push all the leaders in ans array.
    if (leader)
    ans.push_back(arr[i]);

  }
  
  return ans;
}

int main() {
    
  // Array Initialization.
  int n = 6;
  int arr[n] = {10, 22, 12, 3, 0, 6};

  vector<int> ans = printLeadersBruteForce(arr,n);
  
  for(int i = 0;i<ans.size();i++){
      
      cout<<ans[i]<<" ";
  }
  
  cout<<endl;
  return 0;
}



// Optimal Approach
#include<bits/stdc++.h>
vector<int> superiorElements(vector<int>&a) {
    // Write your code here.
    vector<int>ans;
    int maxi = INT_MIN;
    int n = a.size();
    for(int i=n-1; i>=0; i--){
        if(a[i]>maxi){
            ans.push_back(a[i]);
            maxi = max(maxi, a[i]);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;

}