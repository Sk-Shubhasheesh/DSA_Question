// Problem 36 - Count the number of subarrays with given xor K
// Problem link - https://www.codingninjas.com/studio/problems/subarrays-with-xor-k_6826258?utm_source=striver&utm_medium=website&utm_campaign=codestudio_a_zcourse&leftPanelTabValue=PROBLEM

// Bruteforce Approach - Time Complexity: O(N3), Space Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

int subarraysWithXorK(vector<int> a, int k) {
    int n = a.size(); //size of the given array.
    int cnt = 0;

    // Step 1: Generating subarrays:
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {

            //step 2:calculate XOR of all
            // elements:
            int xorr = 0;
            for (int K = i; K <= j; K++) {
                xorr = xorr ^ a[K];
            }

            // step 3:check XOR and count:
            if (xorr == k) cnt++;
        }
    }
    return cnt;
}

int main()
{
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = subarraysWithXorK(a, k);
    cout << "The number of subarrays with XOR k is: "
         << ans << "\n";
    return 0;
}

// better approach = Time Complexity: O(N2), Space Complexity: O(1) 
int subarraysWithXorK(vector<int> a, int k) {
    int n = a.size(); //size of the given array.
    int cnt = 0;

    // Step 1: Generating subarrays:
    for (int i = 0; i < n; i++) {
        int xorr = 0;
        for (int j = i; j < n; j++) {

            //step 2:calculate XOR of all
            // elements:
            xorr = xorr ^ a[j];

            // step 3:check XOR and count:
            if (xorr == k) cnt++;
        }
    }
    return cnt;
}

// optimal approach = Time Complexity: O(N) or O(N*logN), Space Complexity: O(N) 
#include <bits/stdc++.h>
int subarraysWithSumK(vector < int > a, int b) {
    // Write your code here
    unordered_map<int, int> mp;
    int n = a.size();
    int ans = 0;
    int prefix_xor = 0;
    for(int i=0; i<n; i++){
        prefix_xor ^= a[i];
        if(prefix_xor == b) ans++;
        ans += mp[prefix_xor^b];
        mp[prefix_xor]++;
    }
    return ans;
}