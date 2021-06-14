class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> st;
        
        string k;
        int i,n=s.size();
        
        for(i=0;i<n;i++)
        {
            if(s[i]-0==32)
            {
                st.push_back(k);
                
                k.clear();
            }
            else
            {
                k.push_back(s[i]);
            }
        }
        st.push_back(k);
        k.clear();
        
        unordered_map<char,string> mp;
        unordered_map<string,char> mp2;
        n=pattern.size();
        if(n!=st.size())
            return false;
        for(i=0;i<n;i++)
        {
            if(mp.find(pattern[i])==mp.end())
            {
                mp.insert({pattern[i],st[i]});
            }
            else
            {
                auto it=mp.find(pattern[i]);
                if(it->second!=st[i])
                    return false;
            }
            if(mp2.find(st[i])==mp2.end())
            {
                mp2.insert({st[i],pattern[i]});
            }
            else
            {
                auto it=mp2.find(st[i]);
                if(it->second!=pattern[i])
                    return false;
            }
        }
        
        return true;
    }
};