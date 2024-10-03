#include <iostream>
#include <vector>

using namespace std;

/*
Idea: Find the first occurrence of a target value in a sorted array using binary search.

Approach:
1. Initialize left and right pointers.
2. Use binary search to find the middle value.
3. If the middle value equals the target, update the result and continue searching in the left half.
4. If the middle value is less than the target, move the left pointer to mid + 1.
5. If the middle value is greater than the target, move the right pointer to mid - 1.
6. Return the result.

Time Complexity: O(log n) - Binary search reduces the search space by half each time.
Space Complexity: O(1) - Only a few extra variables are used.
*/

int findFirstOccurrence(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            result = mid;
            right = mid - 1; // Continue searching in the left half
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

/*
Idea: Find the last occurrence of a target value in a sorted array using binary search.

Approach:
1. Initialize left and right pointers.
2. Use binary search to find the middle value.
3. If the middle value equals the target, update the result and continue searching in the right half.
4. If the middle value is less than the target, move the left pointer to mid + 1.
5. If the middle value is greater than the target, move the right pointer to mid - 1.
6. Return the result.

Time Complexity: O(log n) - Binary search reduces the search space by half each time.
Space Complexity: O(1) - Only a few extra variables are used.
*/

int findLastOccurrence(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    int result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            result = mid;
            left = mid + 1; // Continue searching in the right half
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;
}

/*
Idea: Find the row with the maximum number of 1s in a 2D sorted array using binary search.

Approach:
1. Iterate through each row.
2. Use binary search to find the first and last occurrence of 1 in the row.
3. Calculate the number of 1s in the row.
4. Update the row index with the maximum number of 1s.

Time Complexity: O(n log m) - We perform binary search on each row.
Space Complexity: O(1) - Only a few extra variables are used.
*/

int rowWithMax1sBinarySearch(vector<vector<int>>& arr) {
    int maxRowIndex = -1;
    int maxOnesCount = 0;

    for (int i = 0; i < arr.size(); i++) {
        int first = findFirstOccurrence(arr[i], 1);
        int last = findLastOccurrence(arr[i], 1);

        if (first != -1 && last != -1) {
            int onesCount = last - first + 1;
            if (onesCount > maxOnesCount) {
                maxOnesCount = onesCount;
                maxRowIndex = i;
            }
        }
    }

    return maxRowIndex;
}

/*
Idea: Find the row with the maximum number of 1s in a 2D sorted array using a linear approach.

Approach:
1. Start from the top-right corner of the matrix.
2. Move left if the current element is 1 and update the row index.
3. Move down if the current element is 0.
4. Continue until you traverse all rows or reach the leftmost column.

Time Complexity: O(n + m) - We traverse at most n rows and m columns.
Space Complexity: O(1) - Only a few extra variables are used.
*/

int rowWithMax1sLinear(vector<vector<int>>& arr) {
    int n = arr.size();
    int m = arr[0].size();
    
    int maxRowIndex = -1;
    int j = m - 1;
    
    for (int i = 0; i < n; ++i) {
        while (j >= 0 && arr[i][j] == 1) {
            j--;
            maxRowIndex = i;
        }
    }
    
    return maxRowIndex;
}

int main() {
    vector<vector<int>> arr = {
        {0, 0, 0, 1},
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 0, 0, 0}
    };

    int result1 = rowWithMax1sBinarySearch(arr);
    int result2 = rowWithMax1sLinear(arr);

    // Test case explanation:
    // 2D Vector:
    // [
    //   [0, 0, 0, 1],
    //   [0, 1, 1, 1],
    //   [1, 1, 1, 1],
    //   [0, 0, 0, 0]
    // ]
    // The row with the maximum number of 1s is row 2 (0-indexed).
    // Expected output: 2

    cout << "Using binary search approach, the row with the maximum number of 1s is " << result1 << endl;
    cout << "Using linear approach, the row with the maximum number of 1s is " << result2 << endl;

    return 0;
}