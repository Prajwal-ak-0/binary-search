#include <iostream>
#include <vector>
using namespace std;

// Function to perform spiral traversal of a matrix
// Idea: Use four boundaries (top, bottom, left, right) to traverse the matrix in a spiral order.
// Time Complexity: O(m * n), where m is the number of rows and n is the number of columns in the matrix.
// Space Complexity: O(1), as no extra space is used except for the result vector.
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    if (matrix.empty()) return res;

    int top = 0, bottom = matrix.size() - 1;
    int left = 0, right = matrix[0].size() - 1;

    while (top <= bottom && left <= right) {
        // Traverse from left to right
        for (int i = left; i <= right; ++i) {
            res.push_back(matrix[top][i]);
        }
        top++;

        // Traverse from top to bottom
        for (int i = top; i <= bottom; ++i) {
            res.push_back(matrix[i][right]);
        }
        right--;

        // Traverse from right to left
        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                res.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        // Traverse from bottom to top
        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                res.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return res;
}

int main() {
    // Example test cases
    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<vector<int>> matrix2 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    vector<int> result1 = spiralOrder(matrix1);
    vector<int> result2 = spiralOrder(matrix2);

    cout << "Test Case 1: ";
    for (int num : result1) cout << num << " ";
    cout << endl; // Expected Output: 1 2 3 6 9 8 7 4 5

    cout << "Test Case 2: ";
    for (int num : result2) cout << num << " ";
    cout << endl; // Expected Output: 1 2 3 4 8 12 11 10 9 5 6 7

    return 0;
}

/*
Test Cases:
1. Input: matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}
   Expected Output: 1 2 3 6 9 8 7 4 5
   Explanation: The matrix is traversed in a spiral order.

2. Input: matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}}
   Expected Output: 1 2 3 4 8 12 11 10 9 5 6 7
   Explanation: The matrix is traversed in a spiral order.
*/