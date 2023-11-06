/* Problem - Remove Duplicates in-place from Sorted Array
Problem link - https://www.codingninjas.com/studio/problems/remove-duplicates-from-sorted-array_1102307?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems


*/

/* Bruteforece Approach - We have to think of a data structure that does not store duplicate elements. So can we use a Hash set

#include<bits/stdc++.h>

using namespace std;
int removeDuplicates(int arr[], int n) {
  set < int > set;
  for (int i = 0; i < n; i++) {
    set.insert(arr[i]);
  }
  int k = set.size();
  int index = 0;
  for (int x: set) {
    arr[index] = x;
    index++;
  }
  return k;
}
int main() {
  int arr[] = {1,1,2,2,2,3,3};
  int n = sizeof(arr)/sizeof(arr[0]);
  int k = removeDuplicates(arr, n);
  cout << "The array after removing duplicate elements is " << endl;
  for (int i = 0; i < k; i++) {
    cout << arr[i] << " ";
  }
}

*/


/* Optimal Solution using two pointer approach
We can think of using two pointers ‘i’ and ‘j’, we move ‘j’ till we don’t get a number 
arr[j] which is different from arr[i]. As we got a unique number we will increase the i 
pointer and update its value by arr[j].
*/
int removeDuplicates(vector<int> &arr, int n) {
	// Write your code here.
	int i = 0;
	for(int j=1; j<n; j++){
		if(arr[j] != arr[i]){
			arr[i+1] = arr[j];
			i++;
		}
	}
	return i+1;
}