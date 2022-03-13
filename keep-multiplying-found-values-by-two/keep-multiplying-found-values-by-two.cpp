class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(),nums.end());
        for(int val:nums)
        {
            if(val == original)
            {
                original*=2;
            }
        }
        return original;
    }
};