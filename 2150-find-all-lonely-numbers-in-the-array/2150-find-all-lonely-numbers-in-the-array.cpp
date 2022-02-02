class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int>ans;
        for(int i = 0;i<nums.size();i++)
        {   int val = nums[i];
            if(mp[val] == 0)
            {
                mp[val] = 1;
            }
            else
            {
                mp[val]++;
            }
        }
        for(int i = 0;i<nums.size();i++)
        {
            int val = nums[i];
            if(mp[val] == 1 && mp[val+1] == 0 && mp[val-1] == 0)
            {
                ans.push_back(val);
            }
        }
    return ans;
    }
};