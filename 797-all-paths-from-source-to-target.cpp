class Solution {
public:
    vector<vector<int>> ans;

    void dfs(vector<vector<int>>& graph, vector<int> &onePath, int src, int target){
        onePath.push_back(src);
        if(src == target){
            ans.push_back(onePath);
            return;
        }

        for(auto neigh: graph[src]){
            dfs(graph, onePath, neigh, target);
            onePath.pop_back();
        }
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> onePath;
        dfs(graph, onePath, 0, graph.size() - 1);
        return ans;
    }
};