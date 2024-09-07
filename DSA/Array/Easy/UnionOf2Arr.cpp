#include <iostream>
#include <vector>
#include <set>
using namespace std;

// Approach 1: Using a set to find the union of two arrays
// Idea: Use a set to store unique elements from both arrays.
// Time Complexity: O((n + m) log(n + m)), where n and m are the number of elements in arr1 and arr2 respectively (due to set operations).
// Space Complexity: O(n + m), as extra space is used for the set.
vector<int> findUnionUsingSet(int arr1[], int arr2[], int n, int m) {
    int i = 0, j = 0;
    set<int> ans;
    
    while (i < n && j < m) {
        if (arr1[i] == arr2[j]) {
            ans.insert(arr1[i]);
            i++;
            j++;
        } else if (arr1[i] > arr2[j]) {
            ans.insert(arr2[j++]);
        } else {
            ans.insert(arr1[i++]);
        }
    }
    
    while (i < n) ans.insert(arr1[i++]);
    while (j < m) ans.insert(arr2[j++]);
    
    vector<int> res(ans.begin(), ans.end());
    
    return res;
}

// Approach 2: Using two pointers to find the union of two arrays
// Idea: Use two pointers to traverse both arrays and add unique elements to the result vector.
// Time Complexity: O(n + m), where n and m are the number of elements in arr1 and arr2 respectively.
// Space Complexity: O(n + m), as extra space is used for the result vector.
vector<int> findUnionUsingTwoPointers(int arr1[], int arr2[], int n, int m) {
    int i = 0, j = 0;
    vector<int> ans;
    
    while (i < n && j < m) {
        if (arr1[i] == arr2[j]) {
            if (ans.empty() || ans.back() != arr1[i]) {
                ans.push_back(arr1[i]);
            }
            i++;
            j++;
        } else if (arr1[i] < arr2[j]) {
            if (ans.empty() || ans.back() != arr1[i]) {
                ans.push_back(arr1[i]);
            }
            i++;
        } else {
            if (ans.empty() || ans.back() != arr2[j]) {
                ans.push_back(arr2[j]);
            }
            j++;
        }
    }
    
    while (i < n) {
        if (ans.empty() || ans.back() != arr1[i]) {
            ans.push_back(arr1[i]);
        }
        i++;
    }
    
    while (j < m) {
        if (ans.empty() || ans.back() != arr2[j]) {
            ans.push_back(arr2[j]);
        }
        j++;
    }
    
    return ans;
}

int main() {
    // Example test cases
    int arr1[] = {1, 2, 2, 3, 4};
    int arr2[] = {2, 3, 5, 6};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    // Using set approach
    vector<int> unionSet = findUnionUsingSet(arr1, arr2, n, m);
    cout << "Using Set Approach: ";
    for (int num : unionSet) {
        cout << num << " ";
    }
    cout << endl;

    // Using two pointers approach
    vector<int> unionTwoPointers = findUnionUsingTwoPointers(arr1, arr2, n, m);
    cout << "Using Two Pointers Approach: ";
    for (int num : unionTwoPointers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

/*
Test Cases:
1. Input: arr1 = {1, 2, 2, 3, 4}, arr2 = {2, 3, 5, 6}
   Expected Output: {1, 2, 3, 4, 5, 6}
   Explanation: The union of the two arrays is {1, 2, 3, 4, 5, 6}.

2. Input: arr1 = {1, 1, 1, 1}, arr2 = {1, 1, 1, 1}
   Expected Output: {1}
   Explanation: The union of the two arrays is {1}.

3. Input: arr1 = {}, arr2 = {1, 2, 3}
   Expected Output: {1, 2, 3}
   Explanation: The union of the two arrays is {1, 2, 3}.

4. Input: arr1 = {1, 2, 3}, arr2 = {}
   Expected Output: {1, 2, 3}
   Explanation: The union of the two arrays is {1, 2, 3}.
*/