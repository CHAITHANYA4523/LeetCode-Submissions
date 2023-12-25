//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<int>& ls, vector<int>& visited){
        visited[node] = 1;
        ls.push_back(node);
        //traverse all it's neighbours
        for(auto it : adj[node]){
            if(!visited[it]) dfs(it, adj, ls, visited);
        }
    }

    vector<int> dfsOfGraph(int n, vector<int> adj[]) {
        vector<int> visited(n, 0);
        int start = 0;
        vector<int> ls;
        dfs(start, adj, ls, visited);
        return ls;
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends