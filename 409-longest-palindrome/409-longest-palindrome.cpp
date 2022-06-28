class Solution {
public:
    int longestPalindrome(string s) {
        map<int,int> mp;
        
        for(char c:s)
        {
            mp[c]++;
        }
        
        int res = 0;
        
        for(auto p:mp)
        {
            int val = p.second;
            res+= val/2*2;
            
            if(res%2 == 0 && val%2 == 1)
            {
                res++;
            }
        }
        return res;
    }
};