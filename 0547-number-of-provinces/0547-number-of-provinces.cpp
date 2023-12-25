class Solution {
private:
    void dfs(int currentNode, vector<int> &visited, vector<vector<int>>& isConnected){
        visited[currentNode] = 1;
        for(int i=0; i<visited.size(); i++){
            if(isConnected[currentNode][i] == 1 && !visited[i]){
                dfs(i, visited, isConnected);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), provinces = 0;
        vector<int> visited(n, 0);
        for(int i=0; i<n; i++){
            if(visited[i] == 0){
                dfs(i, visited, isConnected);
                provinces++;
            }
        }
        return provinces;
    }
};