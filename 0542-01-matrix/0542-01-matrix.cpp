class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<pair<int,int>, int>> q;
        int n = mat.size(), m = mat[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        vector<vector<int>> ans(n, vector<int> (m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    q.push({{i,j}, 1});
                }
            }
        }
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int count = q.front().second;
            q.pop();
            vis[row][col] = 1;
            int drow[] = {-1, 0, 1, 0};
            int dcol[] = {0, 1, 0, -1};
            for(int i=0; i<4; i++){
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m){ 
                    if(mat[nrow][ncol] != 0 && !vis[nrow][ncol]){
                        vis[nrow][ncol] = 1;
                        ans[nrow][ncol] = count;
                        q.push({{nrow,ncol}, count+1});
                    }
                }
            }
        }
        return ans;
    }
};