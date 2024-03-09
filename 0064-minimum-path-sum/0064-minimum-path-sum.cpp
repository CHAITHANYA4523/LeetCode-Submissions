class Solution {
// private:
//     int minSum(vector<vector<int>>& grid, int row, int col, vector<vector<int>> &dp){
//         if(row == 0 && col == 0){
//             return dp[row][col] = grid[row][col];
//         }
//         if(row < 0 || col < 0) return 1e9;
//         if(dp[row][col] != -1){
//             return dp[row][col];
//         }
//         int left = grid[row][col] + minSum(grid, row-1, col, dp);
//         int up = grid[row][col] + minSum(grid, row, col-1, dp);
//         return dp[row][col] = min(left, up);

//     }
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int> (m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i == 0 && j == 0){
                    dp[i][j] = grid[i][j];
                    continue;
                }
                int left = 1e9, up = 1e9;
                if(i > 0){
                    left = grid[i][j] + dp[i-1][j];
                }
                if(j > 0){
                    up = grid[i][j] + dp[i][j-1];
                }
                dp[i][j] = min(up, left);
            }
        }
        return dp[n-1][m-1];
    }
};