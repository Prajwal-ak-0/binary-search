    #include <iostream>
    #include <vector>
    #include <algorithm>

    using namespace std;

    class Solution {
    public:
        // Task: The task is to find the minimum number of coins that you need to make up a certain amount of money given an array of coin denominations.
        // Approach: We sort the coins in descending order and then greedily use as many of the largest coin as possible. If we can't make up the amount with the coins, we return -1.
        // Time Complexity: O(n log n), where n is the number of coins. This is because we are sorting the coins.
        // Space Complexity: O(1), as we are not using any extra space.

        int coinChange(vector<int>& coins, int amount) {
            if(amount == 0) return -1;

            int count = 0;
            sort(coins.begin(), coins.end(), greater<int>());

            for(auto i : coins){
                int times = amount/i;
                count+=times;
                amount-=(times*i);
            }
            

            return amount == 0 ? count : -1;
        }
    };

    int main() {
        // Test Case: The coin denominations are [1, 2, 5] and the amount is 11
        // The minimum number of coins is 3 (5 + 5 + 1 = 11)
        Solution solution;
        vector<int> coins = {1, 2, 5};
        int amount = 11;
        int minCoins = solution.coinChange(coins, amount);
        cout << minCoins << endl;  // Output: 3

        return 0;
    }