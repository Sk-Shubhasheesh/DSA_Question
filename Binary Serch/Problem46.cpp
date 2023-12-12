// Problem 46 - Ceil The Floor
// Problem link - https://bit.ly/3ocI0HW 

#include<bits/stdc++.h>
int findFloor(vector<int> &arr, int n, int x) {
	int low = 0, high = n - 1;
	int ans = -1;

	while (low <= high) {
		int mid = (low + high) / 2;
		// maybe an answer
		if (arr[mid] <= x) {
			ans = arr[mid];
			//look for smaller index on the left
			low = mid + 1;
		}
		else {
			high = mid - 1; // look on the right
		}
	}
	return ans;
}

int findCeil(vector<int> &arr, int n, int x) {
	int low = 0, high = n - 1;
	int ans = -1;

	while (low <= high) {
		int mid = (low + high) / 2;
		// maybe an answer
		if (arr[mid] >= x) {
			ans = arr[mid];
			//look for smaller index on the left
			high = mid - 1;
		}
		else {
			low = mid + 1; // look on the right
		}
	}
	return ans;
}
pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	// Write your code here.
	int f = findFloor(a, n, x);
	int c = findCeil(a, n, x);
	return make_pair(f, c);
}