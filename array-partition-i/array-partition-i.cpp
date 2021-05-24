class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mx = 0;
        
        for(int i = 0;i<nums.size()-1;i+=2)
        {
            mx+=min(nums[i],nums[i+1]);
        }
        return mx;
    }
};