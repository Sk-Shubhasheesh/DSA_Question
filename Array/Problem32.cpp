// Problem 32 - Program to generate Pascal’s Triangle
/*roblem Statement: This problem has 3 variations. They are stated below:

Variation 1: Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle.

Variation 2: Given the row number n. Print the n-th row of Pascal’s triangle.

Variation 3: Given the number of rows n. Print the first n rows of Pascal’s triangle.


*/ 

// Variation 1

#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r) {
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

int pascalTriangle(int r, int c) {
    int element = nCr(r - 1, c - 1);
    return element;
}

int main()
{
    int r = 5; // row number
    int c = 3; // col number
    int element = pascalTriangle(r, c);
    cout << "The element at position (r,c) is: "
            << element << "n";
    return 0;
}


// Variation 2
int nCr(int n, int r) {
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

void pascalTriangle(int n) {
    // printing the entire row n:
    for (int c = 1; c <= n; c++) {
        cout << nCr(n - 1, c - 1) << " ";
    }
    cout << "n";
}

//Variation 3
vector<int>generateRow(int row){
    long long ans = 1;
    vector<int>ansRow;
    ansRow.push_back(1);
    for(int col =1; col<row; col++){
        ans = ans * (row-col);
        ans = ans / (col);
        ansRow.push_back(ans);
    }
    return ansRow;
}
vector<vector<int>> pascalTriangle(int N) {
    // Write your code here.
    vector<vector<int>>ans;
    for(int i=1; i<=N; i++){
        ans.push_back(generateRow(i));
    }
    return ans;
}