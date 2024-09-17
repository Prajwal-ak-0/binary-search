#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// Approach 1: Brute Force
// Idea: Use three nested loops to check all possible triplets and find those with a sum of zero.
// Time Complexity: O(n^3), where n is the number of elements in the array.
// Space Complexity: O(n), as extra space is used for the set to store unique triplets.
vector<vector<int>> threeSumBruteForce(vector<int>& nums) {
    set<vector<int>> ans;

    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            for (int k = j + 1; k < nums.size(); k++) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> triplet = {nums[i], nums[j], nums[k]};
                    sort(triplet.begin(), triplet.end());
                    ans.insert(triplet);
                }
            }
        }
    }

    return vector<vector<int>>(ans.begin(), ans.end());
}

// Approach 2: Using Hash Set
// Idea: Use a hash set to store the elements and find the triplets by checking the presence of the third element.
// Time Complexity: O(n^2), where n is the number of elements in the array.
// Space Complexity: O(n), as extra space is used for the set to store unique triplets and the hash set.
vector<vector<int>> threeSumHashSet(int n, vector<int>& arr) {
    set<vector<int>> st;

    for (int i = 0; i < n; i++) {
        set<int> hashset;
        for (int j = i + 1; j < n; j++) {
            // Calculate the 3rd element:
            int third = -(arr[i] + arr[j]);

            // Find the element in the set:
            if (hashset.find(third) != hashset.end()) {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }

    // Store the set in the answer:
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

// Approach 3: Optimized using Sorting and Two Pointers
// Idea: Sort the array and use a three-pointer approach to find the triplets.
// Time Complexity: O(n^2), where n is the number of elements in the array.
// Space Complexity: O(1), as no extra space is used except for the result vector.
vector<vector<int>> threeSumTwoPointers(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        int j = i + 1, k = n - 1;

        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum > 0)
                k--;
            else if (sum < 0)
                j++;
            else {
                vector<int> temp = {nums[i], nums[j], nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                while (j < k && nums[k] == nums[k + 1])
                    k--;
                while (j < k && nums[j] == nums[j - 1])
                    j++;
            }
        }
    }

    return ans;
}

int main() {
    // Example test cases
    vector<int> nums1 = {-1, 0, 1, 2, -1, -4};
    vector<int> nums2 = {0, 0, 0, 0};
    vector<int> nums3 = {-2, 0, 1, 1, 2};
    vector<int> nums4 = {};

    cout << "Using Brute Force Approach:" << endl;
    vector<vector<int>> result1 = threeSumBruteForce(nums1);
    for (const auto& triplet : result1) {
        cout << "[";
        for (int num : triplet) cout << num << " ";
        cout << "] ";
    }
    cout << endl; // Expected Output: [-1 -1 2] [-1 0 1]

    cout << "Using Hash Set Approach:" << endl;
    vector<vector<int>> result2 = threeSumHashSet(nums2.size(), nums2);
    for (const auto& triplet : result2) {
        cout << "[";
        for (int num : triplet) cout << num << " ";
        cout << "] ";
    }
    cout << endl; // Expected Output: [0 0 0]

    cout << "Using Two Pointers Approach:" << endl;
    vector<vector<int>> result3 = threeSumTwoPointers(nums3);
    for (const auto& triplet : result3) {
        cout << "[";
        for (int num : triplet) cout << num << " ";
        cout << "] ";
    }
    cout << endl; // Expected Output: [-2 0 2] [-2 1 1]

    vector<vector<int>> result4 = threeSumTwoPointers(nums4);
    cout << "Test Case 4: ";
    for (const auto& triplet : result4) {
        cout << "[";
        for (int num : triplet) cout << num << " ";
        cout << "] ";
    }
    cout << endl; // Expected Output: []

    return 0;
}

/*
Test Cases:
1. Input: nums = {-1, 0, 1, 2, -1, -4}
   Expected Output: [-1 -1 2] [-1 0 1]
   Explanation: The unique triplets that sum up to zero are [-1, -1, 2] and [-1, 0, 1].

2. Input: nums = {0, 0, 0, 0}
   Expected Output: [0 0 0]
   Explanation: The unique triplet that sums up to zero is [0, 0, 0].

3. Input: nums = {-2, 0, 1, 1, 2}
   Expected Output: [-2 0 2] [-2 1 1]
   Explanation: The unique triplets that sum up to zero are [-2, 0, 2] and [-2, 1, 1].

4. Input: nums = {}
   Expected Output: []
   Explanation: There are no elements in the array, so no triplets can be formed.
*/