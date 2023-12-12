/*   Problem 21 - Longest Consecutive Sequence in an Array
     Problem Link - https://www.codingninjas.com/studio/problems/longest-successive-elements_6811740?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems

*/

// BruteForce Approach



#include <bits/stdc++.h>
using namespace std;

bool linearSearch(vector<int>&a, int num) {
    int n = a.size(); //size of array
    for (int i = 0; i < n; i++) {
        if (a[i] == num)
            return true;
    }
    return false;
}
int longestSuccessiveElements(vector<int>&a) {
    int n = a.size(); //size of array
    int longest = 1;
    //pick a element and search for its
    //consecutive numbers:
    for (int i = 0; i < n; i++) {
        int x = a[i];
        int cnt = 1;
        //search for consecutive numbers
        //using linear search:
        while (linearSearch(a, x + 1) == true) {
            x += 1;
            cnt += 1;
        }

        longest = max(longest, cnt);
    }
    return longest;
}

int main()
{
    vector<int> a = {100, 200, 1, 2, 3, 4};
    int ans = longestSuccessiveElements(a);
    cout << "The longest consecutive sequence is " << ans << "\n";
    return 0;
}


//Better Approach
#include <bits/stdc++.h>
int longestSuccessiveElements(vector<int>&a) {
    // Write your code here.
    if(a.size() == 0) return 0;
    sort(a.begin(), a.end());
    int n = a.size();
    int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1;
    for(int i=0; i<n; i++){
        if(a[i]-1 == lastSmaller){
            cnt = cnt+1;
            lastSmaller= a[i];
        }
        else if(lastSmaller != a[i]){
            cnt = 1;
            lastSmaller = a[i];
        }
        longest = max(longest, cnt);
    }
    return longest;
}