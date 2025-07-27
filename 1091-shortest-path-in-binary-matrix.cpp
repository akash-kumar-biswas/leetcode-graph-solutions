class Solution
{
public:
    vector<vector<int>> directions = {
        {-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

    using P = pair<int, pair<int, int>>;

    bool isValid(int x, int y, int n)
    {
        return x >= 0 && y >= 0 && x < n && y < n;
    }

    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        dist[0][0] = 0;

        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0, {0, 0}});
        grid[0][0] = 1;

        while (!pq.empty())
        {
            auto [d, coordinate] = pq.top();
            auto [x, y] = coordinate;
            pq.pop();

            if (d > dist[x][y])
                continue;

            for (auto dir : directions)
            {
                int _x = x + dir[0];
                int _y = y + dir[1];

                if (isValid(_x, _y, n) && grid[_x][_y] == 0)
                {
                    if (1 + dist[x][y] < dist[_x][_y])
                    {
                        dist[_x][_y] = 1 + dist[x][y];
                        pq.push({dist[_x][_y], {_x, _y}});
                        grid[_x][_y] == 1;
                    }
                }
            }
        }
        return (dist[n - 1][n - 1] == INT_MAX) ? -1 : dist[n - 1][n - 1] + 1;
    }
};
