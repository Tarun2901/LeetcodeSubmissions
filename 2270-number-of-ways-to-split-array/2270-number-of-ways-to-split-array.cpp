class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
            vector<long long> prefixSum(nums.size());
            int n = nums.size();
            int count = 0;
            long long sum = 0;
            for(int i = 0;i<n;i++)
            {
                sum+= nums[i];
                prefixSum[i] = sum;
            }
        
        for(int i = 0;i<n-1;i++)
        {
            if((prefixSum[i]>=sum-prefixSum[i]))
            {
                count++;
            }
        }
        return count;
    }
};