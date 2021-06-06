class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> pmodk(n);
        int sum = 0;
        for(int i = 0;i<n;i++)
        {
            sum+= nums[i];
            int mod = sum%k;

            pmodk[i] = mod;
            if(pmodk[i]<0)
            {
                pmodk[i]+=k;
            }
        }
        
        for(int i = 0;i<n;i++)
        {
            cout<<pmodk[i]<<" ";
        }
        unordered_map<int,int> mp;
        mp[0] = 1;
        int ans = 0;
        for(int i = 0;i<n;i++)
        {
              if(mp[pmodk[i]]!=0)
              {
                  ans+=mp[pmodk[i]];
              }
            mp[pmodk[i]]++;
        }
        return ans;
    }
};