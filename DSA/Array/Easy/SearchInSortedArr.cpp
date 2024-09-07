#include <iostream>
using namespace std;

// Function to perform binary search on a sorted array
// Idea: Use binary search to find the target element in the sorted array.
// Approach: Use a while loop to repeatedly divide the search interval in half.
// Time Complexity: O(log n), where n is the number of elements in the array.
// Space Complexity: O(1), as no extra space is used.
bool binarySearch(int st, int ed, int arr[], int K) {
    while (st <= ed) {
        int md = st + (ed - st) / 2;
        if (arr[md] == K) return true;
        if (arr[md] > K) ed = md - 1;
        else st = md + 1;
    }
    return false;
}

// Function to search for an element in a sorted array
// Idea: Use binary search to find the target element in the sorted array.
// Approach: Call the binarySearch function with the appropriate parameters.
// Time Complexity: O(log n), where n is the number of elements in the array.
// Space Complexity: O(1), as no extra space is used.
int searchInSorted(int arr[], int N, int K) {
    if (N == 0) return -1;
    return binarySearch(0, N - 1, arr, K) ? 1 : -1;
}

int main() {
    // Example test cases
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {10, 20, 30, 40, 50};
    int arr3[] = {5, 15, 25, 35, 45};
    int arr4[] = {};

    int N1 = sizeof(arr1) / sizeof(arr1[0]);
    int N2 = sizeof(arr2) / sizeof(arr2[0]);
    int N3 = sizeof(arr3) / sizeof(arr3[0]);
    int N4 = sizeof(arr4) / sizeof(arr4[0]);

    int K1 = 3;
    int K2 = 25;
    int K3 = 50;
    int K4 = 10;

    cout << "Test Case 1: " << searchInSorted(arr1, N1, K1) << endl; // Expected Output: 1
    cout << "Test Case 2: " << searchInSorted(arr2, N2, K2) << endl; // Expected Output: -1
    cout << "Test Case 3: " << searchInSorted(arr3, N3, K3) << endl; // Expected Output: -1
    cout << "Test Case 4: " << searchInSorted(arr4, N4, K4) << endl; // Expected Output: -1

    return 0;
}

/*
Test Cases:
1. Input: arr = {1, 2, 3, 4, 5}, K = 3
   Expected Output: 1
   Explanation: The element 3 is present in the array.

2. Input: arr = {10, 20, 30, 40, 50}, K = 25
   Expected Output: -1
   Explanation: The element 25 is not present in the array.

3. Input: arr = {5, 15, 25, 35, 45}, K = 50
   Expected Output: -1
   Explanation: The element 50 is not present in the array.

4. Input: arr = {}, K = 10
   Expected Output: -1
   Explanation: The array is empty, so the element 10 is not present.
*/