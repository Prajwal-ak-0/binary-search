#include <iostream>
#include <vector>
using namespace std;

// Function to find the maximum subarray sum using Kadane's algorithm
// Idea: Use Kadane's algorithm to find the maximum subarray sum.
// Time Complexity: O(n^2), where n is the number of elements in the array.
// Space Complexity: O(1), as no extra space is used.
int maxSubArrayBruteForce(vector<int>& nums) {
    int mx = nums[0];

    for (int i = 0; i < nums.size(); i++) {
        int sum = 0;
        for (int j = i; j < nums.size(); j++) {
            sum += nums[j];
            mx = max(mx, sum);
        }
    }

    return mx;
}

// Function to find the maximum subarray sum using Kadane's algorithm
// Idea: Use Kadane's algorithm to find the maximum subarray sum.
// Time Complexity: O(n), where n is the number of elements in the array.
// Space Complexity: O(1), as no extra space is used.
int maxSubArrayKadane(vector<int>& nums) {
    int mx = nums[0], sum = 0;

    for (int n : nums) {
        sum += n;
        mx = max(sum, mx);
        if (sum < 0) sum = 0;
    }

    return mx;
}

// Function to find the maximum subarray sum and print the start and end indices
// Idea: Use Kadane's algorithm to find the maximum subarray sum and track the start and end indices of the subarray.
// Time Complexity: O(n), where n is the number of elements in the array.
// Space Complexity: O(1), as no extra space is used.
int maxSubArrayWithIndices(vector<int>& nums) {
    int mx = nums[0], sum = 0, st = 0, ast = 0, aend = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (sum == 0) st = i;

        sum += nums[i];
        if (sum > mx) {
            mx = sum;
            ast = st;
            aend = i;
        }
        if (sum < 0) sum = 0;
    }

    cout << "Start Index: " << ast << ", End Index: " << aend << endl;
    return mx;
}

int main() {
    // Example test cases
    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> nums2 = {1};
    vector<int> nums3 = {5, 4, -1, 7, 8};
    vector<int> nums4 = {-1, -2, -3, -4};

    cout << "Using Brute Force Approach:" << endl;
    cout << "Test Case 1: Max Sum = " << maxSubArrayBruteForce(nums1) << endl; // Expected Output: Max Sum = 6
    cout << "Test Case 2: Max Sum = " << maxSubArrayBruteForce(nums2) << endl; // Expected Output: Max Sum = 1
    cout << "Test Case 3: Max Sum = " << maxSubArrayBruteForce(nums3) << endl; // Expected Output: Max Sum = 23
    cout << "Test Case 4: Max Sum = " << maxSubArrayBruteForce(nums4) << endl; // Expected Output: Max Sum = -1

    cout << "Using Kadane's Algorithm:" << endl;
    cout << "Test Case 1: Max Sum = " << maxSubArrayKadane(nums1) << endl; // Expected Output: Max Sum = 6
    cout << "Test Case 2: Max Sum = " << maxSubArrayKadane(nums2) << endl; // Expected Output: Max Sum = 1
    cout << "Test Case 3: Max Sum = " << maxSubArrayKadane(nums3) << endl; // Expected Output: Max Sum = 23
    cout << "Test Case 4: Max Sum = " << maxSubArrayKadane(nums4) << endl; // Expected Output: Max Sum = -1

    cout << "Using Kadane's Algorithm with Indices:" << endl;
    cout << "Test Case 1: Max Sum = " << maxSubArrayWithIndices(nums1) << endl; // Expected Output: Max Sum = 6, Start Index: 3, End Index: 6
    cout << "Test Case 2: Max Sum = " << maxSubArrayWithIndices(nums2) << endl; // Expected Output: Max Sum = 1, Start Index: 0, End Index: 0
    cout << "Test Case 3: Max Sum = " << maxSubArrayWithIndices(nums3) << endl; // Expected Output: Max Sum = 23, Start Index: 0, End Index: 4
    cout << "Test Case 4: Max Sum = " << maxSubArrayWithIndices(nums4) << endl; // Expected Output: Max Sum = -1, Start Index: 0, End Index: 0

    return 0;
}

/*
Test Cases:
1. Input: nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4}
   Expected Output: Max Sum = 6, Start Index: 3, End Index: 6
   Explanation: The maximum subarray is [4, -1, 2, 1] with sum 6.

2. Input: nums = {1}
   Expected Output: Max Sum = 1, Start Index: 0, End Index: 0
   Explanation: The maximum subarray is [1] with sum 1.

3. Input: nums = {5, 4, -1, 7, 8}
   Expected Output: Max Sum = 23, Start Index: 0, End Index: 4
   Explanation: The maximum subarray is [5, 4, -1, 7, 8] with sum 23.

4. Input: nums = {-1, -2, -3, -4}
   Expected Output: Max Sum = -1, Start Index: 0, End Index: 0
   Explanation: The maximum subarray is [-1] with sum -1.
*/