class Solution
{
public:
    bool checkBipartite(vector<vector<int>> &graph, vector<int> &color, int u, int currColor)
    {
        color[u] = currColor;
        queue<int> q;
        q.push(u);

        while (!q.empty())
        {
            u = q.front();

            for (auto neigh : graph[u])
            {
                if (color[neigh] == color[u])
                    return true;
                if (color[neigh] == -1)
                {
                    color[neigh] = 1 ^ color[u];
                    q.push(neigh);
                }
            }
            q.pop();
        }
        return false;
    }

    bool isBipartite(vector<vector<int>> &graph)
    {
        vector<int> color(graph.size(), -1);

        for (int i = 0; i < graph.size(); i++)
        {
            if (color[i] == -1 && checkBipartite(graph, color, i, 1))
                return false;
        }
        return true;
    }
};