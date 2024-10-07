#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
Idea: Find the floor and ceiling of a given number x in a sorted array.

Approach:
1. Sort the array.
2. Use binary search to find the floor and ceiling.

Time Complexity: O(n log n) - Sorting the array.
Space Complexity: O(1)
*/

vector<int> getFloorAndCeil(int x, vector<int> &arr) {
    sort(arr.begin(), arr.end());
    
    int s = 0, e = arr.size() - 1, f = -1, c = -1, m;
    
    while(s <= e){
        m = s + (e-s)/2;
        
        if(arr[m] == x){
            return {x, x};
        }
        else if(arr[m] > x) {
            c = arr[m];
            e = m - 1;
        }else{
            f = arr[m];
            s = m + 1;
        }
    }
    
    return {f, c};
}

/*
Idea: Find the floor and ceiling of a given number x in an unsorted array.

Approach:
1. Iterate through the array.
2. Update floor and ceiling based on comparisons with x.

Time Complexity: O(n)
Space Complexity: O(1)
*/

vector<int> getFloorAndCeilLinear(int x, vector<int> &arr) {
    int f = -1, c = -1;
    
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == x) {
            return {x, x}; // If x is found, it is both the floor and the ceiling
        } else if (arr[i] < x) {
            if (f == -1 || arr[i] > f) {
                f = arr[i]; // Update floor if current element is less than x and greater than the current floor
            }
        } else if (arr[i] > x) {
            if (c == -1 || arr[i] < c) {
                c = arr[i]; // Update ceiling if current element is greater than x and less than the current ceiling
            }
        }
    }
    
    return {f, c};
}

int main() {
    vector<int> arr = {4, 6, 10, 2, 8, 12};
    int x = 5;
    
    vector<int> resultBinary = getFloorAndCeil(x, arr);
    vector<int> resultLinear = getFloorAndCeilLinear(x, arr);
    
    // Test case explanation:
    // Array: [4, 6, 10, 2, 8, 12]
    // x = 5
    // Sorted array: [2, 4, 6, 8, 10, 12]
    // Floor of 5 is 4, Ceiling of 5 is 6
    // Expected output: {4, 6}
    
    cout << "Using binary search approach:" << endl;
    cout << "Floor of " << x << " is " << resultBinary[0] << ", Ceiling of " << x << " is " << resultBinary[1] << endl;
    
    cout << "Using linear search approach:" << endl;
    cout << "Floor of " << x << " is " << resultLinear[0] << ", Ceiling of " << x << " is " << resultLinear[1] << endl;
    
    return 0;
}