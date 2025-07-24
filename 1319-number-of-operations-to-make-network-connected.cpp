class Solution {
public:
    int extraEdge = 0, dis_component = 0;

    void dfs(unordered_map<int, vector<int>> &adj, vector<bool> &vis, int u, int parent){
        vis[u] = true;

        for(auto neigh: adj[u]){
            if(vis[neigh] && neigh != parent){
                extraEdge++;
            }
            if(!vis[neigh]){
                dfs(adj, vis, neigh, u);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<int>> adj;

        for(auto edge: connections){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<bool> vis(n, false);

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(adj, vis, i, -1);
                dis_component++;
            }
        }
        extraEdge/=2;
        return (extraEdge >= dis_component - 1) ? dis_component-1: -1;
    }
};