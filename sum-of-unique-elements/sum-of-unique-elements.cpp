class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> mp;
        int sum = 0;
        for(int i = 0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        for(auto p:mp)
        {
            if(p.second==1)
            {
                sum+=p.first;
            }
        }
        return sum;
    }
};