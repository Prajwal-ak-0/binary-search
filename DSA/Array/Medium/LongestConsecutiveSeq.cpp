#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

// Approach 1: Sorting
// Idea: Sort the array and then find the longest consecutive sequence by iterating through the sorted array.
// Time Complexity: O(n log n), where n is the number of elements in the array (due to sorting).
// Space Complexity: O(1), as no extra space is used.
int longestConsecutiveSorting(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }

    sort(nums.begin(), nums.end());

    int count = 1, mx = 1;

    for (int i = 0; i < nums.size() - 1; ++i) {
        if (nums[i + 1] == nums[i]) {
            continue;
        } else if (nums[i + 1] - nums[i] == 1) {
            count++;
            mx = max(count, mx);
        } else {
            count = 1;
        }
    }

    return mx;
}

// Approach 2: Using Hash Set
// Idea: Use a hash set to store the elements and then find the longest consecutive sequence by checking the presence of consecutive elements.
// Time Complexity: O(n), where n is the number of elements in the array.
// Space Complexity: O(n), as extra space is used for the hash set.
int longestConsecutiveHashSet(vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }

    unordered_set<int> numSet(nums.begin(), nums.end());
    int longStreak = 1;

    for (int n : numSet) {
        if (numSet.find(n - 1) == numSet.end()) {
            int currNum = n, currStreak = 1;

            while (numSet.find(currNum + 1) != numSet.end()) {
                currNum += 1;
                currStreak += 1;
            }

            longStreak = max(currStreak, longStreak);
        }
    }

    return longStreak;
}

int main() {
    // Example test cases
    vector<int> nums1 = {100, 4, 200, 1, 3, 2};
    vector<int> nums2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    vector<int> nums3 = {9, 1, 4, 7, 3, -1, 0, 5, 8, -1, 6};
    vector<int> nums4 = {1, 2, 0, 1};

    cout << "Using Sorting Approach:" << endl;
    cout << "Test Case 1: Longest Consecutive Sequence = " << longestConsecutiveSorting(nums1) << endl; // Expected Output: 4
    cout << "Test Case 2: Longest Consecutive Sequence = " << longestConsecutiveSorting(nums2) << endl; // Expected Output: 9
    cout << "Test Case 3: Longest Consecutive Sequence = " << longestConsecutiveSorting(nums3) << endl; // Expected Output: 7
    cout << "Test Case 4: Longest Consecutive Sequence = " << longestConsecutiveSorting(nums4) << endl; // Expected Output: 3

    cout << "Using Hash Set Approach:" << endl;
    cout << "Test Case 1: Longest Consecutive Sequence = " << longestConsecutiveHashSet(nums1) << endl; // Expected Output: 4
    cout << "Test Case 2: Longest Consecutive Sequence = " << longestConsecutiveHashSet(nums2) << endl; // Expected Output: 9
    cout << "Test Case 3: Longest Consecutive Sequence = " << longestConsecutiveHashSet(nums3) << endl; // Expected Output: 7
    cout << "Test Case 4: Longest Consecutive Sequence = " << longestConsecutiveHashSet(nums4) << endl; // Expected Output: 3

    return 0;
}

/*
Test Cases:
1. Input: nums = {100, 4, 200, 1, 3, 2}
   Expected Output: Longest Consecutive Sequence = 4
   Explanation: The longest consecutive sequence is [1, 2, 3, 4].

2. Input: nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1}
   Expected Output: Longest Consecutive Sequence = 9
   Explanation: The longest consecutive sequence is [0, 1, 2, 3, 4, 5, 6, 7, 8].

3. Input: nums = {9, 1, 4, 7, 3, -1, 0, 5, 8, -1, 6}
   Expected Output: Longest Consecutive Sequence = 7
   Explanation: The longest consecutive sequence is [-1, 0, 1, 3, 4, 5, 6, 7, 8, 9].

4. Input: nums = {1, 2, 0, 1}
   Expected Output: Longest Consecutive Sequence = 3
   Explanation: The longest consecutive sequence is [0, 1, 2].
*/