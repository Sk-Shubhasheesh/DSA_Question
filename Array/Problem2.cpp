/* Problem 2 - Second Largest Elements
Problem Link - https://www.codingninjas.com/studio/problems/ninja-and-the-second-order-elements_6581960?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems
*/

// Solution
int secondLargest(vector<int> &a, int n) {
    int largest = a[0];
    int slargest = -1;
    for(int i=1; i<n; i++){
        if(a[i]>largest){
            slargest = largest;
            largest = a[i];
        }
        else if(a[i] < largest && a[i] > slargest){
            slargest = a[i];
        }
    }
    return slargest;
}

int secondSmallest(vector<int> &a, int n){
    int smallest = a[0];
    int ssmallest = INT_MAX;
    for(int i=1; i<n; i++){
        if(a[i]<smallest){
            ssmallest = smallest;
            smallest = a[i];
        }
        else if(a[i]>smallest && a[i]<ssmallest){
            ssmallest = a[i];
        }
    }
    return ssmallest;

}
vector<int> getSecondOrderElements(int n, vector<int> a) {
    // Write your code here.
    int slargest = secondLargest(a, n);
    int ssmallest = secondSmallest(a, n);
    return {slargest, ssmallest};
}