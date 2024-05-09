#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0, n = nums.size(), mn = INT_MAX, sum = 0;

        while (j < n) {
            sum += nums[j];

            while (sum >= target && i <= j) {
                mn = min(mn, j - i + 1);
                sum -= nums[i++];
            }
            ++j;
        }

        return mn == INT_MAX ? 0 : mn;
    }
};

int main() {
    // Test Case:
    // Input: target = 7, nums = [2,3,1,2,4,3]
    // Output: 2
    // Explanation: The subarray [4,3] has the minimal length under the problem constraint.
    Solution solution;
    vector<int> nums = {2,3,1,2,4,3};
    int target = 7;
    int result = solution.minSubArrayLen(target, nums);

    // Print the result
    cout << "The minimal length of a subarray with a sum greater than or equal to " << target << " is " << result << "." << endl;

    return 0;
}