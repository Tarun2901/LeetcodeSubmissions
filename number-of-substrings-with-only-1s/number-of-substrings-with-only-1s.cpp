class Solution {
public:
    int numSub(string s) {
        int count = 0;
        long long int ans = 0;
        int mod = 1000000007;
        
        for(int i = 0;i<s.size();i++)
        {
            if(s[i] == '0')
            {
               
                count = 0;
            }
            else
            {
                count++;
                ans = (ans+count)%mod;
            }
        }
        
        return ans%mod;
    }
};