#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

/*
Idea: Find the k-th missing positive number in a sorted array.

Approach 1:
1. Use a hash map to store the elements of the array.
2. Iterate through the positive integers and count the missing ones.
3. Return the k-th missing positive number.

Time Complexity: O(n + k) - We iterate through the array and then through the positive integers until we find the k-th missing number.
Space Complexity: O(n) - We use a hash map to store the elements of the array.
*/

int findKthPositiveHashMap(vector<int>& arr, int k) {
    unordered_map<int, int> mp;

    for (int i = 0; i < arr.size(); i++) {
        mp[arr[i]] = 1;
    }

    int count = 0;

    for (int i = 1; i < INT_MAX; i++) {
        if (mp.find(i) == mp.end()) {
            count++;
            if (count == k)
                return i;
        }
    }

    return -1;
}

/*
Idea: Find the k-th missing positive number in a sorted array.

Approach 2:
1. Use binary search to find the position where the k-th missing number would be.
2. Adjust the search range based on the number of missing elements up to the middle point.
3. Return the k-th missing positive number.

Time Complexity: O(log n) - Binary search reduces the search space by half each time.
Space Complexity: O(1) - Only a few extra variables are used.
*/

int findKthPositiveBinarySearch(vector<int>& arr, int k) {
    int s = 0, e = arr.size() - 1;

    while (s <= e) {
        int m = s + (e - s) / 2;

        if (arr[m] - m - 1 < k) s = m + 1;
        else e = m - 1;
    }

    return s + k;
}

int main() {
    vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;

    int result1 = findKthPositiveHashMap(arr, k);
    int result2 = findKthPositiveBinarySearch(arr, k);

    // Test case explanation:
    // Vector: [2, 3, 4, 7, 11]
    // k = 5
    // The missing positive numbers are [1, 5, 6, 8, 9, 10, 12, ...]
    // The 5th missing positive number is 9.
    // Expected output: 9

    cout << "Using hash map approach, the " << k << "th missing positive number is " << result1 << endl;
    cout << "Using binary search approach, the " << k << "th missing positive number is " << result2 << endl;

    return 0;
}