    #include <iostream>
    #include <vector>

    using namespace std;

    // Idea: The problem is to search for a target value in a 2D matrix where each row is sorted in ascending order.

    // Approach: The approach is to perform a binary search on each row. 
    // If the target value is within the range of the first and last elements of the current row, 
    // we perform a binary search on that row.

    // Binary Search function
    bool bs(int s, int e, int r, int ele, vector<vector<int>>& mat){
        while(s<=e){
            int m = s + (e-s)/2;

            if(mat[r][m] == ele){
                return true;
            }
            else if(mat[r][m] > ele){
                e = m-1;
            }
            else{
                s = m+1;
            }
        }

        return false;
    }

    // Function to search for a target value in a 2D matrix
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        int c = (r>0) ? matrix[0].size()-1 : 0;

        for(int i = 0; i<r ; i++){
            if(matrix[i][0] <= target && target <= matrix[i][c]){
                // Perform binary search on the current row
                return bs(0, c, i, target, matrix);
            }
        }
        return false;
    }

    // Time Complexity: The time complexity is O(m log n), 
    // where m is the number of rows and n is the number of columns in the matrix. 
    // This is because we are performing a binary search on each row.