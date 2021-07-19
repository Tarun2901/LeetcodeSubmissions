class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> tmap;
        map<char,int> smap;
        
        for(char c:t)
        {
            tmap[c]++;
        }
        int matchedCount = 0;
        smap[s[0]]++;
        string ans = "";
        int minl = INT_MAX;
        if(smap[s[0]]<=tmap[s[0]])
        {
            matchedCount++;
            if(matchedCount == t.size())
            {
                minl = 1;
                ans = s.substr(0,1);
            }
        }
        int i = 0;
        int j = 0;

        while(j<s.size()-1)
        {
            j++;
            smap[s[j]]++;
            if(smap[s[j]]<=tmap[s[j]])
            {
                matchedCount++;
            }
            
            if(matchedCount == t.size())
            {
                while(matchedCount == t.size())
                {
                if(j-i+1<minl)
                {
                    minl = j-i+1;
                    ans = s.substr(i,j-i+1);
                }
                smap[s[i]]--;
                if(smap[s[i]]<tmap[s[i]])
                {
                    matchedCount--;
                }
                i++;
                }
            }
        }
        return ans;
    }
};