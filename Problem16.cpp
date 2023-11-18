/* Problem 16 - Find the Majority Element that occurs more than N/2 times

   Problem link - https://www.codingninjas.com/studio/problems/majority-element_6783241?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems

*/

// BruteForce Approach
#include <bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> v) {

    //size of the given array:
    int n = v.size();

    for (int i = 0; i < n; i++) {
        //selected element is v[i]
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            // counting the frequency of v[i]
            if (v[j] == v[i]) {
                cnt++;
            }
        }

        // check if frquency is greater than n/2:
        if (cnt > (n / 2))
            return v[i];
    }

    return -1;
}

int main()
{
    vector<int> arr = {2, 2, 1, 1, 1, 2, 2};
    int ans = majorityElement(arr);
    cout << "The majority element is: " << ans << endl;
    return 0;
}


// better Approach - Using Hashing -
#include <bits/stdc++.h>
int majorityElement(vector<int> v) {
	// Write your code here
	map<int, int>mapp;
	for(int i=0; i<v.size(); i++){
		mapp[v[i]]++;
	}
	for(auto it: mapp){
		if(it.second > (v.size()/2)){
			return it.first;
		}
	}
	return -1;
	

}

