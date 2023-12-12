/* Problem 22 - Print 2D Array & Serch Element into Array */
// C++ program to print 
// 2D array using for loop
#include <iostream>
using namespace std;

int main() {
const int row = 3, col = 3;
int serch = 7;
// Declaring array
int arr[row][col] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
// printing the array
for(int i = 0; i < row; i++){
    for(int j = 0; j < col; j++){
	cout << arr[i][j] << " ";
    }
    cout << endl;
} 
// Search element into 2D Array
for(int i = 0; i < row; i++){
    for(int j = 0; j < col; j++){
        if(arr[i][j] == serch){
            cout<<"Yes"<<endl;
        }
    }  
} 
}



