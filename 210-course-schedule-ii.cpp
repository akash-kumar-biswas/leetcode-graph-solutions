class Solution
{
public:
    int topoSort(unordered_map<int, vector<int>> &adj, vector<int> &inDegree, vector<int> &ans)
    {
        int cnt = 0;
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
                    q.push(neigh);
            }
            cnt++;
            ans.push_back(u);
            q.pop();
        }
        return cnt;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        unordered_map<int, vector<int>> adj;
        vector<int> inDegree(numCourses, 0);
        vector<int> ans;

        for (auto vec : prerequisites)
        {
            adj[vec[1]].push_back(vec[0]);
            inDegree[vec[0]]++;
        }
        if (topoSort(adj, inDegree, ans) == numCourses)
            return ans;
        return {};
    }
};