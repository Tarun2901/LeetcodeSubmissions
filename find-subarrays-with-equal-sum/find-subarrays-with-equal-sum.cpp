class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int sum = 0;
        unordered_map<int,bool> mp;
        int n = nums.size();
        for(int i = 0;i<2;i++)
        {
            sum+=nums[i];
        }
        int i = 2;
        int j = 0;
        mp[sum] = true;
        
        while(i<n)
        {
            sum-=nums[j++];
            sum+=nums[i++];
            if(mp[sum] == true)
            {
                return true;
            }
            else
            {
                mp[sum]  = true;
            }
        }
        return false;
    }
};