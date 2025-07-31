class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> ust_wordList(wordList.begin(), wordList.end());
        unordered_set<string> ust_visited;

        vector<char> aphabet(26);
        for(int i = 0; i < 26; i++){
            aphabet[i] = 'a' + i;
        }

        queue<string> q;
        q.push(beginWord);
        ust_visited.insert(beginWord);
        int level = 0;

        while(!q.empty()){
            int n = q.size();

            while(n--){
                string children = q.front();
                q.pop();

                if(children == endWord)
                    return level + 1;
                for(auto cha: aphabet){
                    for(int i = 0; i < children.size(); i++){
                        string temp = children;
                        temp[i] = cha;

                        if(ust_wordList.count(temp) && !ust_visited.count(temp)){
                            q.push(temp);
                            ust_visited.insert(temp);
                        }
                    }
                }
            }
            level++;
        }
        return 0;
    }
};