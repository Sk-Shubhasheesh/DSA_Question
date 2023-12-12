//  Problem 24 - Print Row index with Max Sum

#include <iostream>
using namespace std;
int main() {
    int sum = INT8_MIN, index=-1;
    int arr[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for(int i=0; i<3; i++){
        int total = 0;
        for(int j=0; j<3; j++){
            total +=arr[i][j];
        }
        if(sum < total){
            sum = total;
            index =i;
        }
    }
    cout<<index<<endl;

} 





