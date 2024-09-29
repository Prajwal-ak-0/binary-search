#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

/*
Idea: Find the smallest divisor such that the sum of the division results is less than or equal to the threshold.

Approach:
1. Use binary search to find the smallest divisor.
2. Calculate the sum of the division results for each mid value.
3. Adjust the search range based on the sum comparison with the threshold.

Time Complexity: O(n log m), where n is the number of elements in the array and m is the maximum element in the array.
Space Complexity: O(1)
*/

int smallestDivisor(vector<int>& nums, int threshold) {
    int left = 1;
    int right = *max_element(nums.begin(), nums.end());

    while (left < right) {
        int mid = left + (right - left) / 2;
        int sum = 0;

        for (int num : nums) {
            sum += ceil((double)num / mid);
        }

        if (sum <= threshold) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return right;
}

int main() {
    vector<int> nums = {1, 2, 5, 9};
    int threshold = 6;

    int result = smallestDivisor(nums, threshold);

    // Input: nums = [1, 2, 5, 9], threshold = 6

    // Explanation:

    //     If divisor = 1, the sum is 1 + 2 + 5 + 9 = 17 (which is greater than 6).

    //     If divisor = 4, the sum is ceil(1/4) + ceil(2/4) + ceil(5/4) + ceil(9/4) = 1 + 1 + 2 + 3 = 7 (which is greater than 6).

    //     If divisor = 5, the sum is ceil(1/5) + ceil(2/5) + ceil(5/5) + ceil(9/5) = 1 + 1 + 1 + 2 = 5 (which is less than or equal to 6).

    // Output: 5

    cout << "The smallest divisor is " << result << endl;

    return 0;
}