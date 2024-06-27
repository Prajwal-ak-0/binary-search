    #include <vector>
    #include <iostream>
    using namespace std;

    class Solution {
    public:
        void dfs(vector<vector<char>>& board, int i, int j) {
            int m = board.size();
            int n = board[0].size();

            if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O')
                return;

            board[i][j] = '1';

            dfs(board, i + 1, j);
            dfs(board, i - 1, j);
            dfs(board, i, j + 1);
            dfs(board, i, j - 1);
        }

        void solve(vector<vector<char>>& board) {
            if (board.empty())
                return;

            int m = board.size();
            int n = board[0].size();

            if (m <= 2 || n <= 2)
                return;

            for (int i = 0; i < m; i++) {
                if (board[i][0] == 'O')
                    dfs(board, i, 0);
                if (board[i][n - 1] == 'O')
                    dfs(board, i, n - 1);
            }

            for (int j = 0; j < n; j++) {
                if (board[0][j] == 'O')
                    dfs(board, 0, j);
                if (board[m-1][j] == 'O')
                    dfs(board, m - 1, j);
            }

            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (board[i][j] == '1') {
                        board[i][j] = 'O';
                    } else if (board[i][j] == 'O') {
                        board[i][j] = 'X';
                    }
                }
            }
        }
    };

    int main() {
        vector<vector<char>> board = {
            {'X', 'X', 'X', 'X'},
            {'X', 'O', 'O', 'X'},
            {'X', 'X', 'O', 'X'},
            {'X', 'O', 'X', 'X'}
        };

        Solution().solve(board);

        for (const auto &row : board) {
            for (char cell : row) {
                cout << cell << " ";
            }
            cout << "\n";
        }

        return 0;
    }

    /*
    Idea:
    Transform all 'O's that are not surrounded by 'X's (i.e., 'O's on the border or connected to an 'O' on the border) into '1's, then flip the remaining 'O's into 'X's and the '1's back into 'O's.

    Approach:
    1. Use DFS to mark all 'O's connected to the border as '1's.
    2. Iterate through the entire board, flipping 'O's to 'X's and '1's back to 'O's.

    Time Complexity: O(m*n), where m is the number of rows and n is the number of columns in the board.
    Space Complexity: O(m*n) in the worst case due to the recursion stack when the DFS explores a large area of 'O's.

    Example Test Case:
    Input:
    X X X X
    X O O X
    X X O X
    X O X X

    Output:
    X X X X
    X X X X
    X X X X
    X O X X
    */