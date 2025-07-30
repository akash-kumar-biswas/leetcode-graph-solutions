class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> ust;
        unordered_set<string> ust_bank;

        for(auto str: bank){
            ust_bank.insert(str);
        }

        queue<string> q;

        q.push(startGene);
        ust.insert(startGene);

        int level = 0;
        while(!q.empty()){
            int n = q.size();   // total no. of nodes at current level
            while(n--){         // process all nodes of current level
                string possibleEnd = q.front();
                q.pop();
                if(possibleEnd == endGene)
                    return level;
                for(auto cha: "ACGT"){
                    for(int i = 0; i < 8; i++){
                        string temp = possibleEnd;
                        temp[i] = cha;
                        if(!ust.count(temp) && ust_bank.count(temp)){
                            ust.insert(temp);    // level order traversal (valid and visited)
                            q.push(temp);
                        }
                    }
                }
            }
            level++;
        }
        return -1;
    }
};