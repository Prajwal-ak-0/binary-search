#include <iostream>
#include <vector>

using namespace std;

/*
Idea: Search for a target value in a 2D matrix where each row and column is sorted.

Approach:
1. Start from the top-right corner of the matrix.
2. If the current element equals the target, return true.
3. If the current element is greater than the target, move left.
4. If the current element is less than the target, move down.
5. Continue until you traverse all rows or reach the leftmost column.
6. Return false if the target is not found.

Time Complexity: O(n + m) - We traverse at most n rows and m columns.
Space Complexity: O(1) - Only a few extra variables are used.
*/

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();

    int i = 0, j = n - 1;

    while (i < m && j >= 0) {
        if (matrix[i][j] == target)
            return true;
        else if (matrix[i][j] > target)
            j--;
        else
            i++;
    }

    return false;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10, 13, 14, 17}
    };
    int target = 5;

    bool result = searchMatrix(matrix, target);

    // Test case explanation:
    // 2D Vector:
    // [
    //   [1, 4, 7, 11],
    //   [2, 5, 8, 12],
    //   [3, 6, 9, 16],
    //   [10, 13, 14, 17]
    // ]
    // Target: 5
    // The target value 5 is present in the matrix at position (1, 1).
    // Expected output: true

    cout << "The target " << target << " is " << (result ? "found" : "not found") << " in the matrix." << endl;

    target = 15;
    result = searchMatrix(matrix, target);

    // Test case explanation:
    // 2D Vector:
    // [
    //   [1, 4, 7, 11],
    //   [2, 5, 8, 12],
    //   [3, 6, 9, 16],
    //   [10, 13, 14, 17]
    // ]
    // Target: 15
    // The target value 15 is not present in the matrix.
    // Expected output: false

    cout << "The target " << target << " is " << (result ? "found" : "not found") << " in the matrix." << endl;

    return 0;
}