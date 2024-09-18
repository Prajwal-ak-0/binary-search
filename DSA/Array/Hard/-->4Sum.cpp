#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// Approach 1: Brute Force
// Idea: Use four nested loops to check all possible quadruplets and find those with a sum equal to the target.
// Time Complexity: O(n^4), where n is the number of elements in the array.
// Space Complexity: O(n), as extra space is used for the set to store unique quadruplets.
vector<vector<int>> fourSumBruteForce(vector<int>& nums, int target) {
    set<vector<int>> ans;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            for (int k = j + 1; k < nums.size(); k++) {
                for (int l = k + 1; l < nums.size(); l++) {
                    long long sum = nums[i] + nums[j] + nums[k] + nums[l];
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    sort(temp.begin(), temp.end());
                    if (sum == target) ans.insert(temp);
                }
            }
        }
    }
    return vector<vector<int>>(ans.begin(), ans.end());
}

// Approach 2: Using Hash Set
// Idea: Use a hash set to store the elements and find the quadruplets by checking the presence of the fourth element.
// Time Complexity: O(n^3), where n is the number of elements in the array.
// Space Complexity: O(n), as extra space is used for the set to store unique quadruplets and the hash set.
vector<vector<int>> fourSumHashSet(vector<int>& nums, int target) {
    set<vector<int>> ans;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            set<long long> temp;
            for (int k = j + 1; k < nums.size(); k++) {
                long long sum = static_cast<long long>(target) -
                                (static_cast<long long>(nums[i]) +
                                 static_cast<long long>(nums[j]) +
                                 static_cast<long long>(nums[k]));
                if (temp.find(sum) != temp.end()) {
                    vector<int> t = {nums[i], nums[j], nums[k],
                                     static_cast<int>(sum)};
                    sort(t.begin(), t.end());
                    ans.insert(t);
                }
                temp.insert(nums[k]);
            }
        }
    }
    return vector<vector<int>>(ans.begin(), ans.end());
}

// Approach 3: Optimized using Sorting and Two Pointers
// Idea: Sort the array and use a four-pointer approach to find the quadruplets.
// Time Complexity: O(n^3), where n is the number of elements in the array.
// Space Complexity: O(1), as no extra space is used except for the result vector.
vector<vector<int>> fourSumTwoPointers(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (int j = i + 1; j < n; j++) {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            int k = j + 1;
            int l = n - 1;

            while (k < l) {
                long long sum = static_cast<long long>(nums[i]) + static_cast<long long>(nums[j]) + static_cast<long long>(nums[k]) + static_cast<long long>(nums[l]);

                if (sum > target)
                    l--;
                else if (sum < target)
                    k++;
                else {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++;
                    l--;

                    while (k < l && nums[k] == nums[k - 1])
                        k++;
                    while (k < l && nums[l] == nums[l + 1])
                        l--;
                }
            }
        }
    }

    return ans;
}

int main() {
    // Example test cases
    vector<int> nums1 = {1, 0, -1, 0, -2, 2};
    int target1 = 0;

    vector<int> nums2 = {2, 2, 2, 2, 2};
    int target2 = 8;

    vector<int> nums3 = {-3, -1, 0, 2, 4, 5};
    int target3 = 2;

    vector<int> nums4 = {};
    int target4 = 0;

    cout << "Using Brute Force Approach:" << endl;
    vector<vector<int>> result1 = fourSumBruteForce(nums1, target1);
    for (const auto& quad : result1) {
        cout << "[";
        for (int num : quad) cout << num << " ";
        cout << "] ";
    }
    cout << endl; // Expected Output: [-2 -1 1 2] [-2 0 0 2] [-1 0 0 1]

    cout << "Using Hash Set Approach:" << endl;
    vector<vector<int>> result2 = fourSumHashSet(nums2, target2);
    for (const auto& quad : result2) {
        cout << "[";
        for (int num : quad) cout << num << " ";
        cout << "] ";
    }
    cout << endl; // Expected Output: [2 2 2 2]

    cout << "Using Two Pointers Approach:" << endl;
    vector<vector<int>> result3 = fourSumTwoPointers(nums3, target3);
    for (const auto& quad : result3) {
        cout << "[";
        for (int num : quad) cout << num << " ";
        cout << "] ";
    }
    cout << endl; // Expected Output: [-3 -1 2 4]

    vector<vector<int>> result4 = fourSumTwoPointers(nums4, target4);
    cout << "Test Case 4: ";
    for (const auto& quad : result4) {
        cout << "[";
        for (int num : quad) cout << num << " ";
        cout << "] ";
    }
    cout << endl; // Expected Output: []

    return 0;
}

/*
Test Cases:
1. Input: nums = {1, 0, -1, 0, -2, 2}, target = 0
   Expected Output: [-2 -1 1 2] [-2 0 0 2] [-1 0 0 1]
   Explanation: The unique quadruplets that sum up to the target are [-2, -1, 1, 2], [-2, 0, 0, 2], and [-1, 0, 0, 1].

2. Input: nums = {2, 2, 2, 2, 2}, target = 8
   Expected Output: [2 2 2 2]
   Explanation: The unique quadruplet that sums up to the target is [2, 2, 2, 2].

3. Input: nums = {-3, -1, 0, 2, 4, 5}, target = 2
   Expected Output: [-3 -1 2 4]
   Explanation: The unique quadruplet that sums up to the target is [-3, -1, 2, 4].

4. Input: nums = {}, target = 0
   Expected Output: []
   Explanation: There are no elements in the array, so no quadruplets can be formed.
*/