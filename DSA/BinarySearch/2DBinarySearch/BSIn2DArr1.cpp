#include <iostream>
#include <vector>

using namespace std;

/*
Idea: Search for a target value in a 2D matrix where each row is sorted and the first element of each row is greater than the last element of the previous row.

Approach:
1. Treat the 2D matrix as a 1D array.
2. Use binary search to find the middle index.
3. Calculate the corresponding row and column from the middle index.
4. If the middle element equals the target, return true.
5. If the middle element is greater than the target, adjust the end pointer.
6. If the middle element is less than the target, adjust the start pointer.
7. Continue until the start pointer exceeds the end pointer.
8. Return false if the target is not found.

Time Complexity: O(log(m * n)) - Binary search reduces the search space by half each time.
Space Complexity: O(1) - Only a few extra variables are used.
*/

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int s = 0, e = m * n - 1;

    while (s <= e) {
        int md = s + (e - s) / 2;

        int r = md / n, c = md % n;

        if (matrix[r][c] == target)
            return true;
        else if (matrix[r][c] > target)
            e = md - 1;
        else
            s = md + 1;
    }

    return false;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 3;

    bool result = searchMatrix(matrix, target);

    // Test case explanation:
    // 2D Vector:
    // [
    //   [1, 3, 5, 7],
    //   [10, 11, 16, 20],
    //   [23, 30, 34, 60]
    // ]
    // Target: 3
    // The target value 3 is present in the matrix at position (0, 1).
    // Expected output: true

    cout << "The target " << target << " is " << (result ? "found" : "not found") << " in the matrix." << endl;

    target = 13;
    result = searchMatrix(matrix, target);

    // Test case explanation:
    // 2D Vector:
    // [
    //   [1, 3, 5, 7],
    //   [10, 11, 16, 20],
    //   [23, 30, 34, 60]
    // ]
    // Target: 13
    // The target value 13 is not present in the matrix.
    // Expected output: false

    cout << "The target " << target << " is " << (result ? "found" : "not found") << " in the matrix." << endl;

    return 0;
}