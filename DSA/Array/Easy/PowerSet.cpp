#include <iostream>
#include <vector>
using namespace std;

// Recursive function to generate all subsets
// Idea: Use backtracking to generate all possible subsets by including or excluding each element.
// Approach: Recursively include or exclude each element and add the current subset to the answer when all elements are considered.
// Time Complexity: O(2^n), where n is the number of elements in the input array.
// Space Complexity: O(n), for the recursion stack.
void solve(vector<vector<int>> &ans, int i, vector<int> &nums, vector<int> &curr) {
    if (i == nums.size()) {
        ans.push_back(curr);
        return;
    }
    curr.push_back(nums[i]);
    solve(ans, i + 1, nums, curr);
    curr.pop_back();
    solve(ans, i + 1, nums, curr);
}

// Function to generate all subsets of a given set
// Idea: Use the recursive `solve` function to generate all subsets.
// Time Complexity: O(2^n), where n is the number of elements in the input array.
// Space Complexity: O(n), for the recursion stack.
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> curr;
    solve(ans, 0, nums, curr);
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> result = subsets(nums);

    cout << "Subsets:" << endl;
    for (const auto& subset : result) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}

/*
Test Case:
Input: nums = {1, 2, 3}
Expected Output:
Subsets:
{ }
{ 1 }
{ 2 }
{ 1 2 }
{ 3 }
{ 1 3 }
{ 2 3 }
{ 1 2 3 }
Explanation: The function generates all possible subsets of the input array {1, 2, 3}.
*/