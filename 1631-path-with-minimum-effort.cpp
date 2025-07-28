class Solution {
public:
    using P = pair<int, pair<int, int>>;
    vector<vector<int>> directions = {
        {-1, 0},{1, 0}, {0, -1}, {0, 1}
    };

    bool isSafe(int x, int y, int n, int m){
        return x >= 0 && y >=0 && x < n && y < m; 
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> effort(n, vector<int>(m, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;
        effort[0][0] = 0;
        pq.push({0, {0, 0}});

        while(!pq.empty()){
            auto [e, coordinate] = pq.top();
            auto [x, y] = coordinate;

            pq.pop();

            if(e > effort[x][y])
                continue;

            for(auto dir: directions){
                int new_x = x + dir[0];
                int new_y = y + dir[1];

                if(isSafe(new_x, new_y, n, m)){
                    if(max(e, abs(heights[x][y] - heights[new_x][new_y])) < effort[new_x][new_y]){
                        effort[new_x][new_y] = max(e, abs(heights[x][y] - heights[new_x][new_y]));
                        pq.push({effort[new_x][new_y], {new_x, new_y}});
                    }
                }
            }
        }
        return effort[n-1][m-1];
    }
};