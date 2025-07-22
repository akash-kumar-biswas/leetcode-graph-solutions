class Solution
{
public:
    void topoSort(unordered_map<int, vector<int>> &adj, vector<int> &inDegree, int &cnt)
    {
        queue<int> q;
        for (int i = 0; i < inDegree.size(); i++)
        {
            if (inDegree[i] == 0)
                q.push(i);
        }

        while (!q.empty())
        {
            int u = q.front();
            for (auto neigh : adj[u])
            {
                inDegree[neigh]--;
                if (inDegree[neigh] == 0)
                {
                    q.push(neigh);
                }
            }
            cnt++;
            q.pop();
        }
    }

    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        unordered_map<int, vector<int>> adj;
        vector<int> inDegree(numCourses, 0);
        for (auto vec : prerequisites)
        {
            adj[vec[1]].push_back(vec[0]);
            inDegree[vec[0]]++;
        }
        vector<bool> vis(numCourses, false);
        int cnt = 0;

        topoSort(adj, inDegree, cnt);

        return cnt == numCourses;
    }
};