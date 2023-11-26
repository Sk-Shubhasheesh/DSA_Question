/*  Problem 27 - Rotate Matrix/Image by 90 degree
    Problem link

*/

// BruteForce Approach

#include<bits/stdc++.h>

using namespace std;
vector < vector < int >> rotate(vector < vector < int >> & matrix) {
    int n = matrix.size();
    vector < vector < int >> rotated(n, vector < int > (n, 0));
    for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        rotated[j][n - i - 1] = matrix[i][j];
    }
    }
    return rotated;
}

int main() {
    vector < vector < int >> arr;
    arr =  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector < vector < int >> rotated = rotate(arr);
    cout << "Rotated Image" << endl;
    for (int i = 0; i < rotated.size(); i++) {
    for (int j = 0; j < rotated[0].size(); j++) {
        cout << rotated[i][j] << " ";
    }
    cout << "n";
    }

}


// Optimal Solution
#include<bits/stdc++.h>
#include<vector>
void rotateMatrix(vector<vector<int>> &mat){
	// Write your code here.
	int n = mat.size();
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			swap(mat[i][j], mat[j][i]);
		}
	}
	for(int i=0; i<n; i++){
		reverse(mat[i].begin(), mat[i].end());
	}
	
}