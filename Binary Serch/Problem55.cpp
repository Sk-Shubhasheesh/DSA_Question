// Problem 55 - Finding Sqrt of a number using Binary Search
// Problem link - https://bit.ly/41AJb1p

// BruteForce using Linear Serch
#include <bits/stdc++.h>
using namespace std;

int floorSqrt(int n) {
    int ans = 0;
    //linear search on the answer space:
    for (long long i = 1; i <= n; i++) {
        long long val = i * i;
        if (val <= n) {
            ans = i;
        } else {
            break;
        }
    }
    return ans;
}

int main()
{
    int n = 36;
    int ans = floorSqrt(n);
    cout << "The floor of square root of " << n
         << " is: " << ans << "\n";
    return 0;
}

// Optimal 1 using  math function
int floorSqrt(int n) {
    int ans = sqrt(n);
    return ans;
}

// Optimal 1 using  binary serch
int floorSqrt(int n)
{
    // Write your code here.
    long long low = 1, high = n;
    while(low<=high){
        int mid = (low+high)/2;
        int val = mid*mid;
        if(val<=n){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return high;
}


