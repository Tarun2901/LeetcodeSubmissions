class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo = 1;
        int mx = INT_MIN;
        
        for(int i = 0;i<nums.size();i++)
        {
            mx = max(mx,nums[i]);
        }
        
        int hi = mx;
        int res = INT_MAX;
        while(lo<=hi)
        {
            int mid = lo + (hi-lo)/2;
            int sum  = 0;
            
            for(auto p:nums)
            {
                sum+= ceil(p*1.0/mid);
            }
            if(sum>threshold)
            {
                lo = mid+1;
            }
            else{
                res = min(res,mid);
                hi = mid-1;
            }
        }
        return res;
    }
};