class Solution {
public:
    int find(int i, vector<int> &parent){
    if(parent[i] == -1)
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

    bool equationsPossible(vector<string>& equations) {
        vector<int> parent(27, -1);
        vector<int> rank(27, 0);

        for(auto str: equations){
            if(str[1] == '=')
                _union(str[0] - 'a' + 1, str[3] - 'a' + 1, parent, rank);
        }

        for(auto str: equations){
            if(str[1] == '!' && find(str[0] - 'a' + 1, parent) 
            == find(str[3] - 'a' + 1, parent))
                return false;
        }
        return true;
    }
};