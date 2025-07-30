class Solution {
public:
    void dfs(vector<vector<int>>& rooms, vector<int> &vis, int start){
        vis[start] = true;

        for(auto neigh: rooms[start]){
            if(!vis[neigh])
                dfs(rooms, vis, neigh);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> vis(n, false);

        dfs(rooms, vis, 0);
        return count(vis.begin(), vis.end(), false) == 0 ;
    }
};