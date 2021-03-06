class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    }
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans = "";
        unordered_map<string,string> mp;
        for(int i = 0;i<knowledge.size();i++)
        {
            string key = knowledge[i][0];
            string value = knowledge[i][1];
            mp[key] = value;
        }
        
        int i = 0;
        while(i<s.size())
        {
                if(s[i]!= '(')
                {
                    ans+= s[i];
                    i++;
                }
            else if(s[i] == '(')
            {
                string temp = "";
                while(s[i]!=')')
                {
                    i++;
                    temp+= s[i];
                }
                temp.pop_back();
                if(mp.find(temp)!=mp.end())
                {
                    
                    ans+= mp[temp];
                }
                else
                {   
                    ans+='?';
                }
                i++;
            }
            
        }
        return ans;
    }
};