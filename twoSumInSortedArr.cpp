#include <iostream>
#include <vector>

using namespace std;

// Idea: The problem is to find two numbers such that they add up to a specific target number. 
// The input array is sorted in ascending order.

// Approach: The approach is to perform a binary search for each number's complement in the rest of the array. 
// If the complement is found, we return the indices of the number and its complement.

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for (int i = 0; i < numbers.size(); ++i) {
            int complement = target - numbers[i];
            int low = i + 1, high = numbers.size() - 1;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (numbers[mid] == complement) {
                    return {i + 1, mid + 1};
                } else if (numbers[mid] < complement) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        return {};
    }
};

// Time Complexity: The time complexity is O(n log n), 
// where n is the size of the array. 
// This is because we are performing a binary search for each number in the array.

int main() {
    Solution solution;
    vector<int> numbers = {2, 7, 11, 15};
    int target = 9;
    vector<int> result = solution.twoSum(numbers, target);
    for(int i : result) {
        cout << i << " ";
    }

    return 0;
}