class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        int mxright = 1;
        int mxleft = 1;
        
        sort(nums.begin(),nums.end());
        
        for(int i = n-1;i>=n-3;i--)
        {
            mxright = nums[i] * mxright;
        }
        
        for(int i = 0;i<2;i++)
        {
            mxleft = nums[i]*mxleft;
        }
        mxleft = mxleft*nums[n-1];
        return max(mxleft,mxright);
    }
};