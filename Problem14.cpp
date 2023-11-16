/*  Problem 14- Two Sum Problem
    Problem link - https://www.codingninjas.com/studio/problems/reading_6845742?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems

*/

// Bruteforce - or each element of the given array, we will try to search for another element such that its sum is equal to the target. If such two numbers exist, we will return the indices or “YES” accordingly.
#include <bits/stdc++.h>
using namespace std;

string twoSum(int n, vector<int> &arr, int target) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) return "YES";
        }
    }
    return "NO";
}

int main()
{
    int n = 5;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    string ans = twoSum(n, arr, target);
    cout << "This is the answer for variant 1: " << ans << endl;
    return 0;
}

// Better Approach(using Hashing): 
#include <bits/stdc++.h>
using namespace std;

string twoSum(int n, vector<int> &arr, int target) {
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        int moreNeeded = target - num;
        if (mpp.find(moreNeeded) != mpp.end()) {
            return "YES";   //  return {mpp[moreNeeded], i};
        }
        mpp[num] = i;
    }
    return "NO";
}

// Optimized Approach(using two-pointer)
#include <bits/stdc++.h>
string read(int n, vector<int> book, int target)
{
    // Write your code here.
    sort(book.begin(), book.end());
    int left =0; 
    int right = n-1;
    while(left<right){
        int sum = book[left] + book[right];
        if(sum == target){
            return "YES";
        }
        else if(sum<target){
            left++;
        }
        else{
            right--;
        }

    }
    return "NO";
}