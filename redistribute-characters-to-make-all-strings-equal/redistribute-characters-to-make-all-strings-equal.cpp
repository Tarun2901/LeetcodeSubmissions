class Solution {
public:
    bool makeEqual(vector<string>& words) {
        
        int n = words.size();
        
        map<char,int> mp;
        
        for(string s: words)
        {
            for(char ch:s)
            {
                mp[ch]++;
            }
        }
        
        for(auto p:mp)
        {
            if(p.second%n != 0)
            {
                return false;
            }
        }
        return true;
    }
};