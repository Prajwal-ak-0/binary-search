#include <iostream>
#include <vector>
#include <climits>

using namespace std;

/*
Idea: Find the median of two sorted arrays using binary search.

Approach:
1. Use binary search on the smaller array to partition both arrays.
2. Calculate the left and right parts of the partition.
3. Adjust the search range based on the comparison of partition elements.
4. If the correct partition is found, calculate the median based on the total size of the combined arrays.

Time Complexity: O(log(min(m, n))) - Binary search on the smaller array.
Space Complexity: O(1) - Only a few extra variables are used.
*/

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();

    if (m > n) return findMedianSortedArrays(nums2, nums1);

    int s = 0, e = m;
    int right_size = (m + n + 1) / 2;
    int total_size = m + n;

    while (s <= e) {
        int m_1 = s + (e - s) / 2;
        int m_2 = right_size - m_1;

        int l1 = (m_1 == 0) ? INT_MIN : nums1[m_1 - 1];
        int l2 = (m_2 == 0) ? INT_MIN : nums2[m_2 - 1];
        int r1 = (m_1 == m) ? INT_MAX : nums1[m_1];
        int r2 = (m_2 == n) ? INT_MAX : nums2[m_2];

        if (l1 <= r2 && l2 <= r1) {
            if (total_size % 2 == 1)
                return max(l1, l2);
            else
                return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
        } else if (l1 > r2) {
            e = m_1 - 1;
        } else {
            s = m_1 + 1;
        }
    }

    return 0.0;
}

int main() {
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    double result = findMedianSortedArrays(nums1, nums2);

    // Test case explanation:
    // nums1 = [1, 3]
    // nums2 = [2]
    // The combined sorted array is [1, 2, 3].
    // The median is 2.
    // Expected output: 2.0

    cout << "The median of the two sorted arrays is " << result << endl;

    nums1 = {1, 2};
    nums2 = {3, 4};

    result = findMedianSortedArrays(nums1, nums2);

    // Test case explanation:
    // nums1 = [1, 2]
    // nums2 = [3, 4]
    // The combined sorted array is [1, 2, 3, 4].
    // The median is (2 + 3) / 2 = 2.5.
    // Expected output: 2.5

    cout << "The median of the two sorted arrays is " << result << endl;

    return 0;
}