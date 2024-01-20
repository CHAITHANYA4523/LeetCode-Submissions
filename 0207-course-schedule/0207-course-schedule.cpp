class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> topo;
        vector<int> inDegree(n, 0);
        vector<int> adj[n];
        queue<int> q;
        for (auto it : prerequisites) {
			adj[it[0]].push_back(it[1]);
            inDegree[it[1]]++;
		}
        for(int i=0; i<n; i++){
            if(inDegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto it:adj[node]){
                inDegree[it]--;
                if(inDegree[it] == 0) q.push(it);
            }
        }
        if(topo.size() == n) return true;
        return false;
    }
};