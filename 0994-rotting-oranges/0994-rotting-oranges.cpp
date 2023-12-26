class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>, int>> q;
        int n = grid.size(), m = grid[0].size(), countFresh = 0;
        int visited[n][m];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    visited[i][j] = 2;
                    q.push({{i,j}, 0});
                }
                else visited[i][j] = 0;
                if(grid[i][j] == 1) countFresh++;
            }
        }
        int time = 0, cnt = 0;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            time = max(time, t);
            q.pop();
            for(int i=0; i<4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m){
                    if(grid[nrow][ncol] == 1 && visited[nrow][ncol] != 2){
                        visited[nrow][ncol] = 2;
                        grid[nrow][ncol] = 2;
                        q.push({{nrow, ncol}, t+1});
                        cnt++;
                    }
                }
            }
        }
        if(cnt != countFresh) return -1;
        return time;
    }
};