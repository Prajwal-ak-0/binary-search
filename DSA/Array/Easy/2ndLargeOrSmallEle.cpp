#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to find the second largest element in the array
// Idea: Traverse the array and keep track of the largest and second largest elements.
// Approach: Use two variables to store the largest and second largest elements. Update them as we traverse the array.
// Time Complexity: O(n), where n is the number of elements in the array.
// Space Complexity: O(1), as no extra space is used.
int print2largest(vector<int> &arr) {
    if (arr.size() < 2) return -1; // If there are less than 2 elements, return -1

    int mx = INT_MIN, s_mx = INT_MIN;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > mx) {
            s_mx = mx;
            mx = arr[i];
        } else if (arr[i] > s_mx && arr[i] != mx) {
            s_mx = arr[i];
        }
    }

    return (s_mx == INT_MIN) ? -1 : s_mx; // If no second largest element is found, return -1
}

int main() {
    // Example test cases
    vector<int> arr1 = {10, 5, 20, 8, 12};
    vector<int> arr2 = {10, 10, 10};
    vector<int> arr3 = {5};
    vector<int> arr4 = {3, 3, 4, 4, 5, 5};

    cout << "Test Case 1: " << print2largest(arr1) << endl; // Expected Output: 12
    cout << "Test Case 2: " << print2largest(arr2) << endl; // Expected Output: -1
    cout << "Test Case 3: " << print2largest(arr3) << endl; // Expected Output: -1
    cout << "Test Case 4: " << print2largest(arr4) << endl; // Expected Output: 4

    return 0;
}

/*
Test Cases:
1. Input: arr = {10, 5, 20, 8, 12}
   Expected Output: 12
   Explanation: The largest element is 20, and the second largest element is 12.

2. Input: arr = {10, 10, 10}
   Expected Output: -1
   Explanation: All elements are the same, so there is no second largest element.

3. Input: arr = {5}
   Expected Output: -1
   Explanation: There is only one element, so there is no second largest element.

4. Input: arr = {3, 3, 4, 4, 5, 5}
   Expected Output: 4
   Explanation: The largest element is 5, and the second largest element is 4.
*/