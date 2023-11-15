/* Problem 13 - Find the number that appears once, and the other numbers twice or Find the Unique number in array
   Problem link - https://www.codingninjas.com/studio/problems/find-the-single-element_6680465?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems

*/

// Bruteforce Approach - For every element present in the array, we will do a linear search and count the occurrence. If for any element, the occurrence is 1, we will return it.



#include <bits/stdc++.h>
using namespace std;

int getSingleElement(vector<int> &arr) {
    // Size of the array:
    int n = arr.size();

    //Run a loop for selecting elements:
    for (int i = 0; i < n; i++) {
        int num = arr[i]; // selected element
        int cnt = 0;

        //find the occurrence using linear search:
        for (int j = 0; j < n; j++) {
            if (arr[j] == num)
                cnt++;
        }

        // if the occurrence is 1 return ans:
        if (cnt == 1) return num;
    }

    //This line will never execute
    //if the array contains a single element.
    return -1;
}

int main()
{
    vector<int> arr = {4, 1, 2, 1, 2};
    int ans = getSingleElement(arr);
    cout << "The single element is: " << ans << endl;
    return 0;
}

// Better Approach - Using Hasshing

int getSingleElement(vector<int> &arr) {

    //size of the array:
    int n = arr.size();

    // Find the maximum element:
    int maxi = arr[0];
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, arr[i]);
    }

    // Declare hash array of size maxi+1
    // And hash the given array:
    vector<int> hash(maxi + 1, 0);
    for (int i = 0; i < n; i++) {
        hash[arr[i]]++;
    }

    //Find the single element and return the answer:
    for (int i = 0; i < n; i++) {
        if (hash[arr[i]] == 1)
            return arr[i];
    }

    //This line will never execute
    //if the array contains a single element.
    return -1;
}


// Optimal Solution - Using Xor
int getSingleElement(vector<int> &arr){
	// Write your code here.
	int xorr = 0;
	for(int i=0; i<arr.size(); i++){
		xorr = xorr^arr[i];
	}
	return xorr;	
}