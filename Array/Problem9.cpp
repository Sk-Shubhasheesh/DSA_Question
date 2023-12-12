/* Problem 9 - Union of Two Sorted Array or Merge Two Sorted Array
 Problem link - https://www.codingninjas.com/studio/problems/sorted-array_6613259?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf

*/

// Bruteforce approach

#include <bits/stdc++.h>

using namespace std;

vector < int > FindUnion(int arr1[], int arr2[], int n, int m) {
  set < int > s;
  vector < int > Union;
  for (int i = 0; i < n; i++)
    s.insert(arr1[i]);
  for (int i = 0; i < m; i++)
    s.insert(arr2[i]);
  for (auto it: s)
    Union.push_back(it);
  return Union;
}

int main()

{
  int n = 10, m = 7;
  int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int arr2[] = {2, 3, 4, 4, 5, 11, 12};
  vector < int > Union = FindUnion(arr1, arr2, n, m);
  cout << "Union of arr1 and arr2 is  " << endl;
  for (auto & val: Union)
    cout << val << " ";
  return 0;
}


// Optimal Solution
#include<bits/stdc++.h>
vector < int > sortedArray(vector < int > a, vector < int > b) {
    // Write your code here
    int n1 = a.size();
    int n2 = b.size();
    int i =0;
    int j = 0;
    vector<int> UnionArr;
    while(i<n1 && j<n2){
        if(a[i] <= b[j]){
            if(UnionArr.size()==0 || UnionArr.back() != a[i]){
                UnionArr.push_back(a[i]);
            }
            i++;
        }
        else{
            if(UnionArr.size() ==0 || UnionArr.back() != b[j]){
                UnionArr.push_back(b[j]);
            }
            j++;
        }
    }
    while(j<n2){
        if(UnionArr.size() ==0 || UnionArr.back() != b[j]){
            UnionArr.push_back(b[j]);
        }
        j++;
    }
    while(i<n1){
        if(UnionArr.size() ==0 || UnionArr.back() != a[i]){
            UnionArr.push_back(a[i]);
            
        }
        i++;
    }