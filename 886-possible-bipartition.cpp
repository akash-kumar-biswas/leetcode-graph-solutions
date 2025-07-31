class Solution {
public:
    bool dfs(unordered_map<int, vector<int>> &adj, vector<int> &color, int node, int col){
        color[node] = col;

        for(auto neigh: adj[node]){
            if(color[neigh] == col)
                return true;
            if(color[neigh] == -1){
                color[neigh] = 1 ^ col;
                if(dfs(adj, color, neigh, color[neigh]))
                    return true; 
            }
        }
        return false;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>> adj;

        for(auto edge: dislikes){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> color(n+1, -1);
        for(int i = 1; i <= n; i++){
            if(color[i] == -1 && dfs(adj, color, i, 0))
                return false;
        }
        return true;
    }
};