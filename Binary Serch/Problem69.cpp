// Problem 69 - Search in a row and column-wise sorted matrix
// Problem link - https://www.codingninjas.com/studio/problems/search-in-a-sorted-2d-matrix_6917532?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf


// Bruteforce



#include <bits/stdc++.h>
using namespace std;

bool searchElement(vector<vector<int>>& matrix, int target) {
    int n = matrix.size(), m = matrix[0].size();

    //traverse the matrix:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == target)
                return true;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    searchElement(matrix, 8) == true ? cout << "true\n" : cout << "false\n";
}

// Optimal
bool searchElement(vector<vector<int>> &MATRIX, int target) {
    // Write your code here.
    int n = MATRIX.size();
    int rowSize = MATRIX[0].size();
    int row =0, col =rowSize-1;
    while(row<n && col >=0){
        if(MATRIX[row][col] == target) return true;
        else if(MATRIX[row][col] < target) row++;
        else col--;
    }
    return false;
}