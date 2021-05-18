class Solution {
public:
    char findTheDifference(string s, string t) {
        char as;
        unordered_map<char,int> m;
        for(int i = 0;i<t.size();i++)
        {
            m[t[i]]++;
        }
        for(int i = 0;i<s.size();i++)
        {
            m[s[i]]--;
        }
        for(auto p:m)
        {
            if(p.second>0)
            {
                as = p.first;
            }
        }
        return as;
    }
};