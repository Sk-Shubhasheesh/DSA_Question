// Problem 59 - Find the Smallest Divisor Given a Threshold
// Problem Link - https://bit.ly/3W84GWq

// Bruteforce Approach
#include <bits/stdc++.h>
using namespace std;

int smallestDivisor(vector<int>& arr, int limit) {
    int n = arr.size(); //size of array.
    //Find the maximum element:
    int maxi = *max_element(arr.begin(), arr.end());

    //Find the smallest divisor:
    for (int d = 1; d <= maxi; d++) {
        //Find the summation result:
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += ceil((double)(arr[i]) / (double)(d));
        }
        if (sum <= limit)
            return d;
    }
    return -1;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int limit = 8;
    int ans = smallestDivisor(arr, limit);
    cout << "The minimum divisor is: " << ans << "\n";
    return 0;
}

// Optimal using Binary Serch
#include <bits/stdc++.h>
int sumByD(vector<int> &arr, int div) {
    int n = arr.size(); //size of array
    //Find the summation of division values:
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ceil((double)(arr[i]) / (double)(div));
    }
    return sum;
}
int smallestDivisor(vector<int>& arr, int limit)
{
	// Write your code here.
	int low = 1, high = *max_element(arr.begin(), arr.end());
	while(low<=high){
		int mid = (low+high)/2;
		if(sumByD(arr, mid) <= limit){
			high = mid-1;
		} else{
			low = mid+1;
		}
	}
	return low;
}