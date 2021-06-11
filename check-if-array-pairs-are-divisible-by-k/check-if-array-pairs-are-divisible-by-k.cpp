class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
         unordered_map<int,int> mp; // remainder vs their frquencies
        
        for(int i = 0;i<arr.size();i++)
        {
            int rem = arr[i]%k;
            if(rem<0)
            {
                rem+=k;
            }
            mp[rem]++;
        }
        
        bool res = true;
        
        if(k%2 == 0)
        {
            for(auto p:mp)
            {
                int x = p.first;
                if(x == 0)
                {
                    if(mp[x]%2!=0)
                    {
                        res = false;
                    }
                }
                else if(x == k/2)
                {
                    if(mp[x]%2!=0)
                    {
                        res = false;
                    }
                }
                else
                {
                    if(mp[x]!=mp[k-x])
                    {
                        res = false;
                    }
                }
            }
        }
        else
        {
             for(auto p:mp)
            {
                int x = p.first;
                if(x == 0)
                {
                    if(mp[x]%2!=0)
                    {
                        res = false;
                    }
                }
                else
                {
                    if(mp[x]!=mp[k-x])
                    {
                        res = false;
                    }
                }
            }
        }
        return res;
    }
};