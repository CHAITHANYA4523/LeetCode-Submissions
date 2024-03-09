class Solution {
// private:
//     int minSumPath(vector<vector<int>>& grid, int row, int col, int n, vector<vector<int>> &dp){
//         if(row < 0 || col >= n || col < 0) return 1e9;
//         if(row == 0){
//             return grid[0][col];
//         }
//         if(dp[row][col] != -1){
//             return dp[row][col];
//         }
//         int leftDiagonal = grid[row][col] + minSumPath(grid, row-1, col-1, n, dp);
//         int rightDiagonal = grid[row][col] + minSumPath(grid, row-1, col+1, n, dp);
//         int up = grid[row][col] + minSumPath(grid, row-1, col, n, dp);
//         return dp[row][col] = min(up, min(rightDiagonal, leftDiagonal));
//     }
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int mini = INT_MAX;
        vector<int> next(n, -1);
        for(int j=0; j<n; j++){
            next[j] = grid[n-1][j];
        }
        for(int i=n-2; i>=0; i--){
            vector<int> curr(n, 0);
            for(int j=0; j<n; j++){
                int leftDiagonal = 1e9, rightDiagonal = 1e9, down = 1e9;
                if(j > 0){
                    leftDiagonal = grid[i][j] + next[j-1];
                }
                if(j < n-1){
                    rightDiagonal = grid[i][j] + next[j+1];
                }
                down = grid[i][j] + next[j];
                curr[j] = min(down, min(leftDiagonal, rightDiagonal));
            }
            next = curr;
        }
        int ans = INT_MAX;
        for(int j=0; j<n; j++){
            ans = min(ans, next[j]);
        } 
        return ans;
    }
};