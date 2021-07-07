class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> mp(26,0);
        
        for(int i = 0;i<s1.size();i++)
        {
            mp[s1[i]-'a']++;
        }
        
        int k = 0;
        int j = 0;
        for(int i = 0;i<s1.size();i++)
        {  
            j++;
        }
        string str = s2.substr(k,s1.size());
        int count = 0;
        vector<int> x(26,0);
        for(char ch:str)
        {   cout<<ch;
            x[ch-'a']++;
        }
        if(mp == x)
        {
            return true;
        }
            int i = 0;
            j = s1.size();
         while (j <= s2.size()) {
            if (mp == x) {
                return true;
            }
            if (j == s2.size()) {
                break;
            }
            x[s2[j]-'a']++;
            x[s2[i]-'a']--;
            i++;
            j++;
        }
        return false;
    }
};