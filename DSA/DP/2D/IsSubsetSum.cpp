#include <iostream>
#include <vector>
using namespace std;

// Recursive function to check if there is a subset with the given sum
// Idea: Use backtracking to include or exclude each element and check if the subset sum equals the target sum.
// Approach: Recursively include or exclude each element and check if the current sum equals the target sum.
// Time Complexity: O(2^n), where n is the number of elements in the array.
// Space Complexity: O(n), for the recursion stack.
bool solve(vector<int> arr, int sum, int i, int curr_sum) {
    if (sum == curr_sum) return true;

    if (i == arr.size()) {
        return sum == curr_sum;
    }

    return solve(arr, sum, i + 1, curr_sum + arr[i]) || solve(arr, sum, i + 1, curr_sum);
}

// Function to check if there is a subset with the given sum
// Idea: Use the recursive `solve` function to check if there is a subset with the given sum.
// Time Complexity: O(2^n), where n is the number of elements in the array.
// Space Complexity: O(n), for the recursion stack.
bool isSubsetSum(vector<int> arr, int sum) {
    return solve(arr, sum, 0, 0);
}

int main() {
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;

    cout << "Is there a subset with sum " << sum << "? " << (isSubsetSum(arr, sum) ? "Yes" : "No") << endl;

    return 0;
}

/*
Test Case:
Input: arr = {3, 34, 4, 12, 5, 2}, sum = 9
Expected Output: Yes
Explanation: There is a subset {4, 5} with sum 9.
*/