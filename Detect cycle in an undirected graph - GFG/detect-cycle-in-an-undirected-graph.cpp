//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
//   private:
//     void dfs(int V, vector<int> adj[], bool &ans, vector<int> &visited, int node){
//         visited[node] = 1;
//         for(auto it:adj[node]){
//             if(!visited[it]){
//                 dfs(V, adj, ans, visited, it);
//             }
//             else{
//                 ans = true;
//                 break;
//             }
//         }
//     }

private:
    bool detectCycle(int src, vector<int> adj[], int visited[]){
        queue<pair<int,int>> q;
        visited[src] = 1;
        q.push({src, -1});
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto adjacentNode:adj[node]){
                if(!visited[adjacentNode]){
                    visited[adjacentNode] = 1;
                    q.push({adjacentNode, node});
                }
                // 
                else if(parent != adjacentNode){
                    return true;
                }
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        int visited[V] = {0};
        for(int i=0; i<V; i++){
            if(!visited[i]){
                if(detectCycle(i, adj, visited) == true) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends