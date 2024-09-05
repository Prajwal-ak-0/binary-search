#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to find the largest element in the array
// Idea: Traverse the array and keep track of the largest element.
// Approach: Use a variable to store the largest element. Update it as we traverse the array.
// Time Complexity: O(n), where n is the number of elements in the array.
// Space Complexity: O(1), as no extra space is used.
int largest(vector<int> &arr) {
    int mx = INT_MIN;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > mx) mx = arr[i];
    }
    return mx;
}

int main() {
    // Example test cases
    vector<int> arr1 = {10, 5, 20, 8, 12};
    vector<int> arr2 = {10, 10, 10};
    vector<int> arr3 = {5};
    vector<int> arr4 = {-1, -2, -3, -4, -5};

    cout << "Test Case 1: " << largest(arr1) << endl; // Expected Output: 20
    cout << "Test Case 2: " << largest(arr2) << endl; // Expected Output: 10
    cout << "Test Case 3: " << largest(arr3) << endl; // Expected Output: 5
    cout << "Test Case 4: " << largest(arr4) << endl; // Expected Output: -1

    return 0;
}

/*
Test Cases:
1. Input: arr = {10, 5, 20, 8, 12}
   Expected Output: 20
   Explanation: The largest element is 20.

2. Input: arr = {10, 10, 10}
   Expected Output: 10
   Explanation: All elements are the same, so the largest element is 10.

3. Input: arr = {5}
   Expected Output: 5
   Explanation: There is only one element, so the largest element is 5.

4. Input: arr = {-1, -2, -3, -4, -5}
   Expected Output: -1
   Explanation: The largest element is -1.
*/