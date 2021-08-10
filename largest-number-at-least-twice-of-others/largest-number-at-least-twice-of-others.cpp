class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n = nums.size();
        int mx = INT_MIN+1;
        int secmx = INT_MIN;
        if(n == 1)
        {
            return 0;
        }
        
        for(int i = 0;i<n;i++)
        {
            if(nums[i] > mx)
            {
                int temp = mx;
                mx = nums[i];
                secmx = temp;
            }
            else
            {
                if(nums[i] > secmx)
                {
                    secmx = nums[i];
                }
            }
        }
        
        if(mx>=2*secmx)
        {
            for(int i = 0;i<n;i++)
            {
                if(nums[i] == mx)
                {
                    return i;
                }
            }
        }
        return -1;
    }
};