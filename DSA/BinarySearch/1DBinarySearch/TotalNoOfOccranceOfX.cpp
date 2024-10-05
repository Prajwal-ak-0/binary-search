#include <iostream>

using namespace std;

/*
Idea: Find the total number of occurrences of a given target value in a sorted array.

Approach:
1. Use binary search to find the target.
2. Expand to the left and right to count occurrences.

Time Complexity: O(log n + k) where k is the number of occurrences of the target.
Space Complexity: O(1)
*/

int count(int arr[], int n, int x) {
    int s = 0, e = n - 1;
    int i = -1, j = -1;

    while (s <= e) {
        int m = s + (e - s) / 2;

        if (arr[m] == x) {
            i = m;
            j = m;
            while (i > 0 && arr[i - 1] == x) {
                i--;
            }
            while (j < n - 1 && arr[j + 1] == x) {
                j++;
            }
            break;
        } else if (arr[m] > x) {
            e = m - 1;
        } else {
            s = m + 1;
        }
    }

    if (i == -1 && j == -1) return 0;
    return j - i + 1;
}

int main() {
    int arr[] = {1, 2, 2, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 2;

    int result = count(arr, n, x);

    // Test case explanation:
    // Array: [1, 2, 2, 2, 3, 4, 5]
    // Target: 2
    // The target 2 is found 3 times.
    // Expected output: 3

    cout << "The target " << x << " occurs " << result << " times in the array." << endl;

    return 0;
}