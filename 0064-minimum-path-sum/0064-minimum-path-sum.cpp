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
        vector<int> prev(m, 0);
        for(int i=0; i<n; i++){
            vector<int> curr(m, 0);
            for(int j=0; j<m; j++){
                if(i == 0 && j == 0){
                    curr[j] = grid[i][j];
                    continue;
                }
                int left = 1e9, up = 1e9;
                if(i > 0){
                    up = grid[i][j] + prev[j];
                }
                if(j > 0){
                    left = grid[i][j] + curr[j-1];
                }
                curr[j] = min(up, left);
            }
            prev = curr;
        }
        return prev[m-1];
    }
};