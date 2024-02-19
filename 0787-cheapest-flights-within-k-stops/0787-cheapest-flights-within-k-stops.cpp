class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it:flights){
            //{to, price}
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> distance(n, 1e9);
        distance[src] = 0;
        queue<pair<int,pair<int,int>>> q;
        //{stops, {sourceNode, price}}
        q.push({0, {src, 0}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int price = it.second.second;
            // if stops becomes more than k we don't need to check for more destinations
            if(stops > k) continue;
            for(auto it:adj[node]){
                //from -> {to, price}
                int adjNode = it.first;
                int edgeWeight = it.second;
                if(price + edgeWeight < distance[adjNode]){
                    distance[adjNode] = price+edgeWeight;
                    q.push({stops+1, {adjNode, price+edgeWeight}});
                }
            }
        }
        if(distance[dst] == 1e9) return -1;
        return distance[dst];
    }
};