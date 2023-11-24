// Problem 25 - Print Diagonal Sum
#include <iostream>
using namespace std;
int main() {
    int arr[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int row = 3, col=3;
    int first = 0, second = 0;
    // first diagonal sum
    for(int i=0; i<row; i++){
        first += arr[i][i];
    }
    //Second diagonal sum
    int j=col-1;
    for (int i = 0; j >= 0; i++, j--) {
        second += arr[i][j];
    }

    cout<<first<<endl;
    cout<<second<<endl;
} 
