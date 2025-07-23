class Solution {
public:
    bool checkBipartite(vector<vector<int>>& graph, vector<int> &color, int u, int currColor){
        color[u] = currColor;

        for(auto neigh: graph[u]){
            if(color[neigh] == currColor)
                return true;
            if(color[neigh] == -1){
                color[neigh] = 1 ^ currColor;
                if(checkBipartite(graph, color, neigh, color[neigh]))
                    return true;
            }
        }
        return false;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);

        for(int i = 0; i < graph.size(); i++){
            if(color[i] == -1 && checkBipartite(graph, color, i, 1))
                return false;
        }
        return true;
    }
};