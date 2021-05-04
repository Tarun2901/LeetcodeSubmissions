class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int cnt = 0;
        for(vector<string>vt:items)
            {
                if(ruleKey == "type" && ruleValue == vt[0])
                {
                    cnt++;
                }
                 if(ruleKey == "color" && ruleValue == vt[1])
                {
                    cnt++;
                }
                 if(ruleKey == "name" && ruleValue == vt[2])
                {
                    cnt++;
                }
            }
       return cnt;
    }
};