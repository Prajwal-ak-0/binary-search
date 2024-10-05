#include <iostream>
#include <vector>
#include <climits>

using namespace std;

/*
Idea: Find the k-th element in the union of two sorted arrays using binary search.

Approach:
1. Use binary search on the smaller array to partition both arrays.
2. Calculate the left and right parts of the partition.
3. Adjust the search range based on the comparison of partition elements.
4. If the correct partition is found, return the maximum of the left parts as the k-th element.

Time Complexity: O(log(min(m, n))) - Binary search on the smaller array.
Space Complexity: O(1) - Only a few extra variables are used.
*/

int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
    int m = arr1.size(), n = arr2.size();

    if (m > n)
        return kthElement(k, arr2, arr1);

    int s = max(0, k - n); // Adjust the search range
    int e = min(k, m);     // Adjust the search range

    while (s <= e) {
        int m_1 = s + (e - s) / 2;
        int m_2 = k - m_1; // Calculate mid2 as k - mid1

        int l1 = (m_1 == 0) ? INT_MIN : arr1[m_1 - 1];
        int l2 = (m_2 == 0) ? INT_MIN : arr2[m_2 - 1];
        int r1 = (m_1 == m) ? INT_MAX : arr1[m_1];
        int r2 = (m_2 == n) ? INT_MAX : arr2[m_2];

        if (l1 <= r2 && l2 <= r1) {
            return max(l1, l2); // Return the k-th element
        }

        else if (l1 > r2)
            e = m_1 - 1;
        else
            s = m_1 + 1;
    }

    return -1;
}

int main() {
    vector<int> arr1 = {2, 3, 6, 7, 9};
    vector<int> arr2 = {1, 4, 8, 10};
    int k = 5;

    int result = kthElement(k, arr1, arr2);

    // Test case explanation:
    // arr1 = [2, 3, 6, 7, 9]
    // arr2 = [1, 4, 8, 10]
    // The combined sorted array is [1, 2, 3, 4, 6, 7, 8, 9, 10].
    // The 5th element in the combined sorted array is 6.
    // Expected output: 6

    cout << "The " << k << "th element in the combined sorted arrays is " << result << endl;

    k = 7;
    result = kthElement(k, arr1, arr2);

    // Test case explanation:
    // arr1 = [2, 3, 6, 7, 9]
    // arr2 = [1, 4, 8, 10]
    // The combined sorted array is [1, 2, 3, 4, 6, 7, 8, 9, 10].
    // The 7th element in the combined sorted array is 8.
    // Expected output: 8

    cout << "The " << k << "th element in the combined sorted arrays is " << result << endl;

    return 0;
}