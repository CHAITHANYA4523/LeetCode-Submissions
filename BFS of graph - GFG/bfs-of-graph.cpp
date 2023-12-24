//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int n, vector<int> adj[]) {
       vector<int> bfs;
       int visited[n] = {0};
       //mark 0 as visited
       visited[0] = 1;
       queue<int> q;
       // zero based indexing
       q.push(0);
       while(!q.empty()){
           int vertex = q.front();
           q.pop();
           bfs.push_back(vertex);
           // it will traverse vector of adjacent nodes 
           for(auto it : adj[vertex]){
               //if vertex is not visited mark visited and push into queue
               if(!visited[it]){
                   visited[it] = 1;
                   q.push(it);
               }
           }
       }
       return bfs;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends