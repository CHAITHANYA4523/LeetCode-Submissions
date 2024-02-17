class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        dist[0][0] = 1;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        int rowPath[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int colPath[] = {-1, 0, 1, 1, 1, 0, -1, -1};
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        //{distance, {row, col}}
        pq.push({1,{0,0}});
        while(!pq.empty()){
            int dis = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();
            for(int i=0; i<8; i++){
                int nrow = row + rowPath[i];
                int ncol = col + colPath[i];
                if(nrow < n && nrow >= 0 && ncol < n && ncol >= 0 && !visited[nrow][ncol]){
                    if(grid[nrow][ncol] == 0){
                        pq.push({dis+1, {nrow, ncol}});
                        if(dis+1 < dist[nrow][ncol]) dist[nrow][ncol] = dis+1;
                        visited[nrow][ncol] = 1;
                    }
                }
            }
        }
        int ans = dist[n-1][n-1];
        if(ans == 1e9) return -1;
        return ans;
    }
};