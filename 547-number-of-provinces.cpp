class Solution {
public:
    void dfs(unordered_map<int, vector<int>> &adj, vector<bool> &vis, int u){
        vis[u] = true;  
        for(auto neigh: adj[u]){
            if(!vis[neigh])
                dfs(adj, vis, neigh);
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
       unordered_map<int, vector<int>> adj;
       int n = isConnected.size();
       for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j && isConnected[i][j]){
                    adj[i+1].push_back(j+1);
                }
            }
       }
       vector<bool> vis(n+1, false);
       int cnt = 0;
       for(int i = 1; i <= n ; i++){
            if(!vis[i]){
                dfs(adj, vis, i);
                cnt++;
            }
       }
       return cnt;
    }
};