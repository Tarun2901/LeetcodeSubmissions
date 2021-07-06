class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size()<10)
        {
            return {};
        }
        string ans = "";
        map<string,int> mp;
        
        vector<string> res;
        
        for(int i = 0;i<10;i++)
        {
            ans+=s[i];
            mp[ans]++;
        }
        
        for(int i = 10;i<s.size();i++)
        {
            ans.erase(0,1);
            ans.push_back(s[i]);
            mp[ans]++;
        }
        
        for(auto s: mp)
        {
                if(s.second>1)
                {
                    res.push_back(s.first);
                }
        }
        return res;
    }
};