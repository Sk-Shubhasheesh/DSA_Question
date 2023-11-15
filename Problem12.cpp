/*  Problem 12 - Count Maximum Consecutive One’s in the array
    Problem link - https://www.codingninjas.com/studio/problems/maximum-consecutive-ones_3843993?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_Arrayproblems

*/

//Optimal Solution
int consecutiveOnes(vector<int>& arr){
    //Write your code here.
    int maxi = 0;
    int cnt = 0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] == 1){
            cnt ++;
            maxi = max(maxi, cnt); 
            
        } else{
            cnt = 0;
        }
            
    }
    return maxi;
}