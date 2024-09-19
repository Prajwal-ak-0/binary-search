#include <iostream>
#include <vector>
using namespace std;

// Idea: Dynamic Programming Approach
// Approach: Maintain two variables to store the maximum and minimum product up to the current index
// Time Complexity: O(n)
// Space Complexity: O(1)
int maxProduct(vector<int>& nums) {
    int MxP = nums[0], MnP = nums[0], res = nums[0];

    for(int i = 1; i < nums.size(); i++) {
        int tempMx = max(nums[i], max(MxP * nums[i], MnP * nums[i]));
        MnP = min(nums[i], min(MxP * nums[i], MnP * nums[i]));

        MxP = tempMx;

        res = max(MxP, res);
    }

    return res;
}

int main() {
    // Example test case
    vector<int> nums = {2, 3, -2, 4};
    // Explanation:
    // The subarray [2, 3] has the largest product 6.
    // The subarray [-2, 4] has the product -8, which is less than 6.
    // Hence, the maximum product subarray is [2, 3] with product 6.
    cout << "Max Product of Subarray: " << maxProduct(nums) << endl;

    return 0;
}