#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Approach 1: Using a set to remove duplicates
// Idea: Use a set to store unique elements and then copy them back to the array.
// Time Complexity: O(n log n), where n is the number of elements in the array (due to set operations).
// Space Complexity: O(n), as extra space is used for the set.
int removeDuplicatesUsingSet(vector<int>& nums) {
    set<int> uniq;

    for (int i = 0; i < nums.size(); i++) {
        uniq.insert(nums[i]);
    }

    int j = 0;
    for (auto it = uniq.begin(); it != uniq.end(); it++) {
        nums[j++] = *it;
    }

    return j;
}

// Approach 2: Using two pointers to remove duplicates in-place
// Idea: Use two pointers to keep track of the unique elements in the array.
// Time Complexity: O(n), where n is the number of elements in the array.
// Space Complexity: O(1), as no extra space is used.
int removeDuplicatesUsingTwoPointers(vector<int>& nums) {
    if (nums.size() == 0) return 0;

    int st = 0;
    for (int ed = 1; ed < nums.size(); ed++) {
        if (nums[ed] != nums[st]) {
            st++;
            nums[st] = nums[ed];
        }
    }

    return st + 1;
}

int main() {
    // Example test cases
    vector<int> nums1 = {1, 1, 2};
    vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    // Using set approach
    int newLength1 = removeDuplicatesUsingSet(nums1);
    int newLength2 = removeDuplicatesUsingSet(nums2);

    cout << "Using Set Approach:" << endl;
    cout << "Test Case 1: New Length = " << newLength1 << ", Array = ";
    for (int i = 0; i < newLength1; i++) {
        cout << nums1[i] << " ";
    }
    cout << endl;

    cout << "Test Case 2: New Length = " << newLength2 << ", Array = ";
    for (int i = 0; i < newLength2; i++) {
        cout << nums2[i] << " ";
    }
    cout << endl;

    // Resetting the arrays for the next approach
    nums1 = {1, 1, 2};
    nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

    // Using two pointers approach
    newLength1 = removeDuplicatesUsingTwoPointers(nums1);
    newLength2 = removeDuplicatesUsingTwoPointers(nums2);

    cout << "Using Two Pointers Approach:" << endl;
    cout << "Test Case 1: New Length = " << newLength1 << ", Array = ";
    for (int i = 0; i < newLength1; i++) {
        cout << nums1[i] << " ";
    }
    cout << endl;

    cout << "Test Case 2: New Length = " << newLength2 << ", Array = ";
    for (int i = 0; i < newLength2; i++) {
        cout << nums2[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
Test Cases:
1. Input: nums = {1, 1, 2}
   Expected Output: New Length = 2, Array = {1, 2}
   Explanation: The array after removing duplicates is {1, 2}.

2. Input: nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4}
   Expected Output: New Length = 5, Array = {0, 1, 2, 3, 4}
   Explanation: The array after removing duplicates is {0, 1, 2, 3, 4}.
*/