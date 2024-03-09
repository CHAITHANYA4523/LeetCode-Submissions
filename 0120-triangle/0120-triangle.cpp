class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size(), m = triangle[n-1].size();
        vector<int> next(m, 0);
        for(int i=0; i<m; i++){
            next[i] = triangle[n-1][i];
        }
        for(int i=n-2; i>=0; i--){
            int m = triangle[i].size();
            vector<int> curr(m, 0);
            for(int j=m-1; j>=0; j--){
                int downRight = triangle[i][j] + next[j+1];
                int down = triangle[i][j] + next[j];
                curr[j] = min(downRight, down);
            }
            next = curr;
        }
        return next[0];
    }
};