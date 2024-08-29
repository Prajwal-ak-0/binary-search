#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Brute Force Approach
// Idea: Calculate the product of all subarrays and keep track of the maximum product.
// Time Complexity: O(n^2), where n is the number of elements in the array.
// Space Complexity: O(1), as no extra space is used.
int maxProductBruteForce(vector<int>& nums) {
    int maxi = INT_MIN;

    for (int i = 0; i < nums.size(); i++) {
        int pro = 1;
        for (int j = i; j < nums.size(); j++) {
            pro *= nums[j];
            maxi = max(maxi, pro);
        }
    }

    return maxi;
}

// Optimized Approach with Two Passes
// Idea: Traverse the array twice, once from the start and once from the end, to handle negative numbers.
// Time Complexity: O(n), where n is the number of elements in the array.
// Space Complexity: O(1), as no extra space is used.
int maxProductTwoPasses(vector<int>& nums) {
    int maxi = INT_MIN;
    int curr = 1;

    // Traverse from the start
    for (int i = 0; i < nums.size(); i++) {
        curr *= nums[i];
        maxi = max(curr, maxi);

        if (curr == 0)
            curr = 1;
    }

    curr = 1;

    // Traverse from the end
    for (int i = nums.size() - 1; i >= 0; i--) {
        curr *= nums[i];
        maxi = max(curr, maxi);

        if (curr == 0)
            curr = 1;
    }

    return maxi;
}

// Optimized Approach with Single Pass
// Idea: Use two variables to keep track of the maximum and minimum product up to the current element.
// Time Complexity: O(n), where n is the number of elements in the array.
// Space Complexity: O(1), as no extra space is used.
int maxProductSinglePass(vector<int>& nums) {
    int MxP = nums[0], MnP = nums[0], res = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        int tempMx = max(nums[i], max(MxP * nums[i], MnP * nums[i]));
        MnP = min(nums[i], min(MxP * nums[i], MnP * nums[i]));

        MxP = tempMx;

        res = max(MxP, res);
    }

    return res;
}

int main() {
    vector<int> nums = {2, 3, -2, 4};

    cout << "Brute Force Approach: " << maxProductBruteForce(nums) << endl;
    cout << "Two Passes Approach: " << maxProductTwoPasses(nums) << endl;
    cout << "Single Pass Approach: " << maxProductSinglePass(nums) << endl;

    return 0;
}

/*
Test Case:
Input: nums = {2, 3, -2, 4}
Expected Output:
Brute Force Approach: 6
Two Passes Approach: 6
Single Pass Approach: 6
*/