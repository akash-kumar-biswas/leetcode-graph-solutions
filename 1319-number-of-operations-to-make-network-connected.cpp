class Solution {
public:
    int find(int i, vector<int> &parent){
    if(parent[i] == -1)
        return i;
    return parent[i]=find(parent[i], parent);
    }

    void _union(int a, int b, vector<int> &parent, vector<int> &rank){
        int root_a = find(a, parent);
        int root_b = find(b, parent);
        if(root_a != root_b){
            if(rank[root_a] > rank[root_b])
                parent[root_b] = root_a;
            else if(rank[root_a] < rank[root_b])
                parent[root_a] = root_b;
            else{
                parent[root_a] = root_b;
                rank[root_b]++;
            }
        }
    }


    int makeConnected(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<int>> adj;
        vector<int> parent (n, -1);
        vector<int> rank (n, 0);

        int extraEdge = 0;

        for(auto edge: connections){
            if(find(edge[0], parent) == find(edge[1], parent))
                extraEdge++;
            else
                _union(edge[0], edge[1], parent, rank);
        }
        
        int dis_component = count(parent.begin(), parent.end(), -1);
    
        return (extraEdge >= dis_component - 1) ? dis_component - 1: -1;
    }
};