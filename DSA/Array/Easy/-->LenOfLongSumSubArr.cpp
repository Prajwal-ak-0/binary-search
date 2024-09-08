#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Function to find the length of the longest subarray with sum K
// Idea: Use a hash map to store the cumulative sum and its index. If the cumulative sum minus K is found in the hash map, update the maximum length.
// Time Complexity: O(N), where N is the number of elements in the array.
// Space Complexity: O(N), as extra space is used for the hash map.
int lenOfLongSubarr(int A[], int N, int K) {
    unordered_map<int, int> sumMap;
    int sum = 0;
    int maxLen = 0;

    for (int i = 0; i < N; ++i) {
        sum += A[i];

        if (sum == K) {
            maxLen = i + 1;
        }

        if (sumMap.find(sum - K) != sumMap.end()) {
            maxLen = max(maxLen, i - sumMap[sum - K]);
        }

        if (sumMap.find(sum) == sumMap.end()) {
            sumMap[sum] = i;
        }
    }

    return maxLen;
}

int main() {
    // Example test cases
    int A1[] = {10, 5, 2, 7, 1, 9};
    int N1 = sizeof(A1) / sizeof(A1[0]);
    int K1 = 15;

    int A2[] = {-1, 2, 3, 0, 3, 2, -1};
    int N2 = sizeof(A2) / sizeof(A2[0]);
    int K2 = 5;

    int A3[] = {1, 2, 3, 4, 5};
    int N3 = sizeof(A3) / sizeof(A3[0]);
    int K3 = 9;

    cout << "Test Case 1: " << lenOfLongSubarr(A1, N1, K1) << endl; // Expected Output: 4
    cout << "Test Case 2: " << lenOfLongSubarr(A2, N2, K2) << endl; // Expected Output: 5
    cout << "Test Case 3: " << lenOfLongSubarr(A3, N3, K3) << endl; // Expected Output: 3

    return 0;
}

/*
Test Cases:
1. Input: A = {10, 5, 2, 7, 1, 9}, K = 15
   Expected Output: 4
   Explanation: The longest subarray with sum 15 is {5, 2, 7, 1}.

2. Input: A = {-1, 2, 3, 0, 3, 2, -1}, K = 5
   Expected Output: 5
   Explanation: The longest subarray with sum 5 is {2, 3, 0, 3, 2}.

3. Input: A = {1, 2, 3, 4, 5}, K = 9
   Expected Output: 3
   Explanation: The longest subarray with sum 9 is {2, 3, 4}.
*/