#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to rotate the matrix by 90 degrees clockwise
// Idea: First transpose the matrix, then reverse each row.
// Time Complexity: O(n^2), where n is the number of rows (or columns) in the matrix.
// Space Complexity: O(1), no additional space is used.
void rotate(vector<vector<int>>& matrix) {
    // Transpose the matrix
    for(int i = 0; i < matrix.size(); i++){
        for(int j = i + 1; j < matrix.size(); j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reverse each row
    for(int i = 0; i < matrix.size(); i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Original matrix:" << endl;
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    // Test the rotate function
    rotate(matrix);
    cout << "Matrix after rotation:" << endl;
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}