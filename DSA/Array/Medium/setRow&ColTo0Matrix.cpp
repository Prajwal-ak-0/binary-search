#include <iostream>
#include <vector>
#include <utility>

using namespace std;

// Function to set the entire row and column to 0
void solve(vector<vector<int>>& matrix, int row, int col) {
    for (int j = 0; j < matrix[0].size(); ++j) {
        matrix[row][j] = 0;
    }
    for (int i = 0; i < matrix.size(); ++i) {
        matrix[i][col] = 0;
    }
}

// Approach 1: Using additional space to store zero positions
// Idea: Store the positions of zeros in a vector and then set the corresponding rows and columns to zero.
// Time Complexity: O(m * n), where m is the number of rows and n is the number of columns.
// Space Complexity: O(k), where k is the number of zeros in the matrix.
void setZeroes1(vector<vector<int>>& matrix) {
    vector<pair<int, int>> vec;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] == 0) {
                vec.push_back(make_pair(i, j));
            }
        }
    }

    for (auto v : vec) {
        solve(matrix, v.first, v.second);
    }
}

// Approach 2: Using the first row and column as markers
// Idea: Use the first row and column to mark the rows and columns that need to be zeroed.
// Time Complexity: O(m * n), where m is the number of rows and n is the number of columns.
// Space Complexity: O(1), no additional space is used.
void setZeroes2(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    bool firstRowZero = false;
    bool firstColZero = false;

    // Check if the first row needs to be zeroed
    for (int j = 0; j < cols; ++j) {
        if (matrix[0][j] == 0) {
            firstRowZero = true;
            break;
        }
    }

    // Check if the first column needs to be zeroed
    for (int i = 0; i < rows; ++i) {
        if (matrix[i][0] == 0) {
            firstColZero = true;
            break;
        }
    }

    // Use the first row and first column to mark zeroed rows and columns
    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Zero out rows based on the first column
    for (int i = 1; i < rows; ++i) {
        if (matrix[i][0] == 0) {
            for (int j = 1; j < cols; ++j) {
                matrix[i][j] = 0;
            }
        }
    }

    // Zero out columns based on the first row
    for (int j = 1; j < cols; ++j) {
        if (matrix[0][j] == 0) {
            for (int i = 1; i < rows; ++i) {
                matrix[i][j] = 0;
            }
        }
    }

    // Zero out the first row if needed
    if (firstRowZero) {
        for (int j = 0; j < cols; ++j) {
            matrix[0][j] = 0;
        }
    }

    // Zero out the first column if needed
    if (firstColZero) {
        for (int i = 0; i < rows; ++i) {
            matrix[i][0] = 0;
        }
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    cout << "Original matrix:" << endl;
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    // Test Approach 1
    vector<vector<int>> matrix1 = matrix;
    setZeroes1(matrix1);
    cout << "Matrix after setZeroes1:" << endl;
    for (const auto& row : matrix1) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    // Test Approach 2
    vector<vector<int>> matrix2 = matrix;
    setZeroes2(matrix2);
    cout << "Matrix after setZeroes2:" << endl;
    for (const auto& row : matrix2) {
        for (const auto& elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}