class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> mp1;
        for(char ch:s)
        {
            mp1[ch]++;
        }
        for(char ch:t)
        {
            mp1[ch]--;
        }
        
        int count = 0;
        
        for(auto p:mp1)
        {
            int ct = p.second;
            count+= abs(ct);
        }
        return count;
    }
};