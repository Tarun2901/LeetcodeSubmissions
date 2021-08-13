class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        
        map<int,int> mp;
        for(int i = 0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        
        
        for(auto p:mp)
        {
            if(p.second > floor(n/3))
            {
                res.push_back(p.first);
            }
        }
        
        return res;
    }
};