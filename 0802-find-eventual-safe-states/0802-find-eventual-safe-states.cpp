class Solution {
private:
    bool dfsCheck(int source, vector<int> &vis, vector<int> &pathVis, vector<int> &check, vector<vector<int>>& graph){
        vis[source] = 1;
        pathVis[source] = 1;
        for(auto adjacentNode:graph[source]){
            if(!vis[adjacentNode]){
                if(dfsCheck(adjacentNode, vis, pathVis, check, graph) == true) return true;
            }
            else if(pathVis[adjacentNode] && vis[adjacentNode]){
                return true;
            }
        }
        check[source] = 1;
        pathVis[source] = 0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        vector<int> pathVis(n, 0);
        vector<int> safeNodes;
        vector<int> check(n, 0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfsCheck(i, vis, pathVis, check, graph);
            }
        }
        for(int i=0; i<n; i++){
            if(check[i]) safeNodes.push_back(i);
        }
        return safeNodes;
    }
};
