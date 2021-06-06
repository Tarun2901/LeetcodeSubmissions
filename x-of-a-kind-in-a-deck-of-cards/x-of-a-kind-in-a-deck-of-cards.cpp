class Solution {
public:
    
    int gcd(int a,int b)
    {
        if(b == 0)
        {
            return a;
        }
        
        return gcd(b,a%b);
    }
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int,int> mp;
        
        for(int i = 0;i<deck.size();i++)
        {
            mp[deck[i]]++;
        }
        int res = 0;
        
        for(auto p:mp)
        {
            res = gcd(res,p.second);
        }
        return res>1;
    }
};