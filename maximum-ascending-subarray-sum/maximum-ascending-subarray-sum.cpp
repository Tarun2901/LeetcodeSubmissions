class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int mx = 0;
        int sum = nums[0];
        int len = nums.size();
        for(int i=1;i<len;++i){
            if(nums[i]>nums[i-1]) sum+=nums[i];
            else sum = nums[i];
            mx = max(mx,sum);
        }
        return max(mx,nums[0]);
    }
};