#include <iostream>
#include <vector>

using namespace std;

/**
 * Idea:
 * This solution aims to count the number of islands in a given 2D grid. An island is defined as a group of adjacent lands (represented by '1's), connected vertically or horizontally. The surrounding water is represented by '0's.
 *
 * Approach:
 * The approach involves iterating over each cell in the grid. When a land cell ('1') is encountered, a Depth-First Search (DFS) is initiated from that cell to mark all connected land cells as visited (turning them into '0's to avoid revisiting). This process counts as finding one island. The search continues until all cells are visited, and the total number of islands found is returned.
 *
 * Time Complexity:
 * O(M*N), where M is the number of rows and N is the number of columns in the grid. This is because, in the worst case, we might need to visit every cell in the grid once.
 *
 * Space Complexity:
 * O(M*N) in the worst case, due to the recursion stack. This would happen in a grid full of land cells, where the DFS would potentially be called for every cell.
 *
 * Example:
 * Consider the following grid:
 * 11110
 * 11010
 * 11000
 * 00000
 * This grid represents an island (or a group of connected '1's) surrounded by water ('0's). The algorithm would count and return 1 as the number of islands in this grid.
 */

class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();

        // Check bounds and if the current cell is water
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') return;

        // Mark the current cell as visited
        grid[i][j] = '0';

        // Explore all four directions
        dfs(grid, i + 1, j); // Down
        dfs(grid, i - 1, j); // Up
        dfs(grid, i, j + 1); // Right
        dfs(grid, i, j - 1); // Left
    }

    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()) return 0;

        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;

        // Iterate through each cell in the grid
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                // If the cell is land, perform DFS to mark the entire island and increment the count
                if(grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }

        return ans;
    }
};

int main() {
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    Solution solution;
    cout << "Number of islands: " << solution.numIslands(grid);
    return 0;
}