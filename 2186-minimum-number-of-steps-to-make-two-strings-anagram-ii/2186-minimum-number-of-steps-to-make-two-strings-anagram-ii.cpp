class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> mp1(26,0);
        for(int i = 0;i<s.size();i++)
        {   char ch = s[i];
            mp1[ch-'a']++;
        }
        for(int i = 0;i<t.size();i++)
        {   char ch = t[i];
            mp1[ch-'a']--;
        }
        
        int count = 0;
        
        for(int val:mp1)
        {
            count+=abs(val);
        }
        return count;
    }
};