class Solution {
public:

    int find(int i, vector<int> &parent)
    {
        if (parent[i] == -1)
            return i;
        return parent[i] = find(parent[i], parent);
    }

    void _union(int a, int b, vector<int> &parent, vector<int> &rank)
    {
        int root_a = find(a, parent);
        int root_b = find(b, parent);
        if (root_a != root_b)
        {
            if (rank[root_a] > rank[root_b])
                parent[root_b] = root_a;
            else if (rank[root_a] < rank[root_b])
                parent[root_a] = root_b;
            else
            {
                parent[root_a] = root_b;
                rank[root_b]++;
            }
        }
    }

    int kruskal(vector<pair<int, pair<int, int>>> &edgeList, int V)
    {
        sort(edgeList.begin(), edgeList.end());

        vector<int> parent(V, -1);
        vector<int> rank(V, 0);

        vector<pair<int, pair<int, int>>> possibleMST;

        int minCost = 0;

        for (auto edge : edgeList)
        {
            int u = edge.second.first;
            int v = edge.second.second;
            int w = edge.first;

            if(find(u, parent) != find(v, parent)){
                minCost += w;
                _union(u, v, parent, rank);
            }
        }
        return minCost;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        
        vector<pair<int,pair<int,int>>> edgeList;
        for(int i = 0; i < V; i++){
            for(int j = i + 1 ; j < V; j++){
                edgeList.push_back({(abs(points[i][0]-points[j][0])
                +abs(points[i][1]-points[j][1])), {i,j}});
            }
        }
        return kruskal(edgeList, V);
    }
};