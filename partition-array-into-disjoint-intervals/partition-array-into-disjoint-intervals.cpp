class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
         int n = nums.size();
        vector<int> mn(nums.size()+1,INT_MAX);
        for(int i = n-1;i>=0;i--)
        {
            mn[i] = min(mn[i+1],nums[i]);
        }
       
        int runningMax = INT_MIN;
        for(int i = 0;i<n-1;i++)
        {
            runningMax = max(runningMax,nums[i]);
            if(mn[i+1]>=runningMax)
            {
                return i+1;
            }
        }
        return 1;
    }
};