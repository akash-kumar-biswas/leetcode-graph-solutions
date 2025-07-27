class Solution
{
public:
    vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

    bool isValid(int x, int y, int n)
    {
        return x >= 0 && y >= 0 && x < n && y < n;
    }

    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();

        if (grid[0][0] == 1)
            return -1;

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;

        int steps = 0;

        while (!q.empty())
        {

            int sz = q.size();

            while (sz--)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                if (x == n - 1 && y == n - 1)
                    return steps + 1;

                for (auto vec : directions)
                {
                    int _x = x + vec[0];
                    int _y = y + vec[1];

                    if (isValid(_x, _y, n) && grid[_x][_y] == 0)
                    {
                        q.push({_x, _y});
                        grid[_x][_y] = 1;
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};