class Solution {
public:
    void dijkstra(unordered_map<int, vector<pair<int, int>>> &adj, vector<int> &dist, int src)
    {
        dist[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});

        while (!pq.empty())
        {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            if (d > dist[u])
                continue;

            for (auto neigh_v_w : adj[u])
            {
                int v = neigh_v_w.first;
                int w = neigh_v_w.second;
                if (w + dist[u] < dist[v])
                {
                    dist[v] = w + dist[u];
                    pq.push({dist[v], v});
                }
            }
        }
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;

        for(auto edge: times){
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        vector<int> dist(n+1, INT_MAX);
        dist[0] = 0;

        dijkstra(adj, dist, k);

        int min_time = *max_element(dist.begin(), dist.end());
        return (min_time == INT_MAX)? -1: min_time;
    }
};