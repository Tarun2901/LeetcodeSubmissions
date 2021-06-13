class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        int count1 = 0;
        int ans = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        int n = nums.size();
        for(int i = 0;i<n;i++)
        {
            if(nums[i]%2 == 0)
            {
                nums[i] = 0;
            }
            else
            {
                nums[i] = 1;
            }
        }
        
        for(int i = 0;i<n;i++)
        {
            if(nums[i] == 1)
            {
                count1++;
            }
            if(mp[count1-k]>0)
            {
                ans+=mp[count1-k];
            }
            mp[count1]++;
        }
        
        return ans;
    }
};