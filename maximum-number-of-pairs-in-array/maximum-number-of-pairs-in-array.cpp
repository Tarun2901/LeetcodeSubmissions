class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int count = nums.size();
        int pairs = 0;
        unordered_map<int,int> mp;
        
        for(int i = 0;i<nums.size();i++)
        {
            if(mp[nums[i]] == 0)
            {
                mp[nums[i]]++;
            }
            else if(mp[nums[i]] == 1)
            {
                count-=2;
                pairs++;
                mp[nums[i]] = 0;
            }
        }
        
        return {pairs,count};
    }
};