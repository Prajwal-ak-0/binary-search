#include <iostream>
#include <vector>
using namespace std;

// Approach 1: Using Dutch National Flag Algorithm to sort colors
// Idea: Use three pointers to sort the array in a single pass.
// Time Complexity: O(n), where n is the number of elements in the array.
// Space Complexity: O(1), as no extra space is used.
void sortColorsDutchFlag(vector<int>& nums) {
    int st = 0, md = 0, ed = nums.size() - 1;

    while (md <= ed) {
        if (nums[md] == 0) {
            swap(nums[md], nums[st]);
            md++;
            st++;
        } else if (nums[md] == 1) {
            md++;
        } else if (nums[md] == 2) {
            swap(nums[ed], nums[md]);
            ed--;
        }
    }
}

// Approach 2: Using counting sort to sort colors
// Idea: Count the occurrences of each color and then overwrite the array with the correct number of each color.
// Time Complexity: O(n), where n is the number of elements in the array.
// Space Complexity: O(1), as no extra space is used.
void sortColorsCounting(vector<int>& nums) {
    int count0 = 0, count1 = 0, count2 = 0;

    for (int num : nums) {
        if (num == 0) count0++;
        else if (num == 1) count1++;
        else if (num == 2) count2++;
    }

    int index = 0;
    for (int i = 0; i < count0; ++i) {
        nums[index++] = 0;
    }
    for (int i = 0; i < count1; ++i) {
        nums[index++] = 1;
    }
    for (int i = 0; i < count2; ++i) {
        nums[index++] = 2;
    }
}

int main() {
    // Example test cases
    vector<int> nums1 = {2, 0, 2, 1, 1, 0};
    vector<int> nums2 = {2, 0, 1};
    vector<int> nums3 = {0};
    vector<int> nums4 = {1};

    // Using Dutch National Flag Algorithm approach
    cout << "Using Dutch National Flag Algorithm Approach:" << endl;
    sortColorsDutchFlag(nums1);
    for (int num : nums1) cout << num << " ";
    cout << endl;

    sortColorsDutchFlag(nums2);
    for (int num : nums2) cout << num << " ";
    cout << endl;

    sortColorsDutchFlag(nums3);
    for (int num : nums3) cout << num << " ";
    cout << endl;

    sortColorsDutchFlag(nums4);
    for (int num : nums4) cout << num << " ";
    cout << endl;

    // Resetting test cases for counting sort approach
    nums1 = {2, 0, 2, 1, 1, 0};
    nums2 = {2, 0, 1};
    nums3 = {0};
    nums4 = {1};

    // Using counting sort approach
    cout << "Using Counting Sort Approach:" << endl;
    sortColorsCounting(nums1);
    for (int num : nums1) cout << num << " ";
    cout << endl;

    sortColorsCounting(nums2);
    for (int num : nums2) cout << num << " ";
    cout << endl;

    sortColorsCounting(nums3);
    for (int num : nums3) cout << num << " ";
    cout << endl;

    sortColorsCounting(nums4);
    for (int num : nums4) cout << num << " ";
    cout << endl;

    return 0;
}

/*
Test Cases:
1. Input: nums = {2, 0, 2, 1, 1, 0}
   Expected Output: {0, 0, 1, 1, 2, 2}
   Explanation: The array is sorted in ascending order.

2. Input: nums = {2, 0, 1}
   Expected Output: {0, 1, 2}
   Explanation: The array is sorted in ascending order.

3. Input: nums = {0}
   Expected Output: {0}
   Explanation: The array is already sorted.

4. Input: nums = {1}
   Expected Output: {1}
   Explanation: The array is already sorted.
*/