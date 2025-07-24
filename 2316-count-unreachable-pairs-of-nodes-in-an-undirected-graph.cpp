class Solution {
public:
    int find(int i, vector<int> &parent){
    if(parent[i] == i)
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

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);
        vector<int> rank(n, 0);

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }

        for(auto edge: edges){
            _union(edge[0], edge[1], parent, rank);
        }

        unordered_map<int, long long> ump;

        for(int i = 0; i < n; i++){
            ump[find(i, parent)]++;
        }

        long long ans = 0;
        
        if(ump.size() == 1)
            return 0;
        int included_nodes = 0;

        for(auto it: ump){
            ans += it.second*(n - included_nodes  - it.second);
            included_nodes += it.second;
        }
        return ans;
    }
};