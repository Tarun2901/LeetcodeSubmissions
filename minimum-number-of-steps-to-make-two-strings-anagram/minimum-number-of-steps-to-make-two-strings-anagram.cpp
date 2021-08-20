class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> smap;
        unordered_map<char,int> tmap;
        int ans = 0;
        
        int n = s.size();
        
        for(int i = 0;i<n;i++)
        {
            smap[s[i]]++;
            tmap[t[i]]++;
        }
        for(auto p:smap)
        {
            if(p.second>tmap[p.first])
            {
                ans+= p.second - tmap[p.first];
            }
        }
        return ans;
    }
};