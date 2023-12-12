// Problem 38 - Merge two Sorted Arrays Without Extra Space
// Problem Link: https://bit.ly/3jLQGSS

/*  BruteForce Approach => Time Complexity: O(n+m) + O(n+m)
This approach is not the exact solution according to the question as in this approach we are going to use an
extra space i.e. an array. But it is definitely one of the solutions if the question does not contain the 
constraint of not using any extra space. And also this approach will help to understand the optimal approaches.

*/ 



#include <bits/stdc++.h>
using namespace std;

void merge(long long arr1[], long long arr2[], int n, int m) {

    //Declare a 3rd array and 2 pointers:
    long long arr3[n + m];
    int left = 0;
    int right = 0;

    int index = 0;

    //Insert the elements from the 2 arrays
    // into the 3rd array using left and right
    // pointers:

    while (left < n && right < m) {
        if (arr1[left] <= arr2[right]) {
            arr3[index] = arr1[left];
            left++, index++;
        }
        else {
            arr3[index] = arr2[right];
            right++, index++;
        }
    }

    // If right pointer reaches the end:
    while (left < n) {
        arr3[index++] = arr1[left++];
    }

    // If left pointer reaches the end:
    while (right < m) {
        arr3[index++] = arr2[right++];
    }

    // Fill back the elements from arr3[]
    // to arr1[] and arr2[]:
    for (int i = 0; i < n + m; i++) {
        if (i < n) arr1[i] = arr3[i];
        else arr2[i - n] = arr3[i];
    }
}

int main()
{
    long long arr1[] = {1, 4, 8, 10};
    long long arr2[] = {2, 3, 9};
    int n = 4, m = 3;
    merge(arr1, arr2, n, m);
    cout << "The merged arrays are: " << "\n";
    cout << "arr1[] = ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << "\narr2[] = ";
    for (int i = 0; i < m; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}



// Optimal Approach = Time Complexity: O(min(n, m)) + O(n*logn) + O(m*logm)
#include <bits/stdc++.h>
#include<vector>
void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b){
	// Write your code here.
	int N = a.size();
	int M = b.size();
	int left = N-1;
	int right = 0;
	while(left>=0 && right<M){
		if(a[left]>b[right]){
			swap(a[left], b[right]);
			left--, right++;
		}
		else{
			break;
		}
	}
	sort(a.begin(), a.end());
    sort(b.begin(), b.end());
	
}