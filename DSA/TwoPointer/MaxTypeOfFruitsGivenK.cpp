#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

/*
Idea: Find the maximum number of fruits that can be collected in two baskets.

Approach 1: Brute-force
1. Use a nested loop to iterate through all possible subarrays.
2. Use a set to keep track of the types of fruits in the current subarray.
3. If the size of the set exceeds 2, break the inner loop.
4. Otherwise, update the maximum length of the subarray.
5. Return the maximum length.

Time Complexity: O(n^2) - We traverse all possible subarrays.
Space Complexity: O(n) - We use a set to store the types of fruits in the current subarray.
*/

int totalFruitsBruteForce(vector<int>& arr) {
    int mx = 0;
    for (int i = 0; i < arr.size(); i++) {
        set<int> s;
        for (int j = i; j < arr.size(); j++) {
            s.insert(arr[j]);
            if (s.size() > 2) {
                break;
            } else {
                mx = max(mx, j - i + 1);
            }
        }
    }
    return mx;
}

/*
Idea: Find the maximum number of fruits that can be collected in two baskets.

Approach 2: Sliding Window
1. Use a sliding window approach with two pointers `i` and `j`.
2. Use an unordered map to keep track of the count of each type of fruit in the current window.
3. Traverse the array with the right pointer `j`.
4. If the size of the map exceeds 2, move the left pointer `i` to the right until the size of the map is less than or equal to 2.
5. Update the maximum length of the subarray.
6. Return the maximum length.

Time Complexity: O(n) - We traverse the array once.
Space Complexity: O(1) - The unordered map will have at most 3 entries.
*/

int totalFruitsSlidingWindow(vector<int>& arr) {
    int i = 0, j = 0, mx = 0;
    unordered_map<int, int> mp;

    while (j < arr.size()) {
        mp[arr[j]]++;
        if (mp.size() > 2) {
            while (mp.size() > 2) {
                mp[arr[i]]--;
                if (mp[arr[i]] == 0) mp.erase(arr[i]);
                i++;
            }
        }
        mx = max(mx, j - i + 1);
        j++;
    }

    return mx;
}

int main() {
    // Test case 1: arr = [1, 2, 1]
    // Explanation: The maximum number of fruits that can be collected in two baskets is 3.
    vector<int> arr1 = {1, 2, 1};
    cout << "Brute-force - Maximum number of fruits: " << totalFruitsBruteForce(arr1) << endl;
    cout << "Sliding Window - Maximum number of fruits: " << totalFruitsSlidingWindow(arr1) << endl;

    // Test case 2: arr = [0, 1, 2, 2]
    // Explanation: The maximum number of fruits that can be collected in two baskets is 3.
    vector<int> arr2 = {0, 1, 2, 2};
    cout << "Brute-force - Maximum number of fruits: " << totalFruitsBruteForce(arr2) << endl;
    cout << "Sliding Window - Maximum number of fruits: " << totalFruitsSlidingWindow(arr2) << endl;

    // Test case 3: arr = [1, 2, 3, 2, 2]
    // Explanation: The maximum number of fruits that can be collected in two baskets is 4.
    vector<int> arr3 = {1, 2, 3, 2, 2};
    cout << "Brute-force - Maximum number of fruits: " << totalFruitsBruteForce(arr3) << endl;
    cout << "Sliding Window - Maximum number of fruits: " << totalFruitsSlidingWindow(arr3) << endl;

    // Test case 4: arr = [3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4]
    // Explanation: The maximum number of fruits that can be collected in two baskets is 5.
    vector<int> arr4 = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    cout << "Brute-force - Maximum number of fruits: " << totalFruitsBruteForce(arr4) << endl;
    cout << "Sliding Window - Maximum number of fruits: " << totalFruitsSlidingWindow(arr4) << endl;

    return 0;
}