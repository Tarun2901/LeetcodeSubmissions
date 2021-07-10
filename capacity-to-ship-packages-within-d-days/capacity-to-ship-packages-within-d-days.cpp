class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        //We have to ship packages within d days and we have to minimize the weight capacity for this
        
        int sum = 0;
        int mx = INT_MIN;
        for(int i = 0;i<weights.size();i++)
        {
            sum+=weights[i];
            mx = max(mx,weights[i]);
        }
        int lo = mx;
        int hi = sum;
        int res = INT_MAX;
        while(lo<=hi)
        {
            int mid = lo+(hi-lo)/2;
            int reqddays = 1;
            int curr = 0;
            
            for(int i = 0;i<weights.size();i++)
            {
                if(curr+weights[i]>mid)
                {
                    curr = weights[i];
                    reqddays++;
                }
                else
                {
                    curr+=weights[i];
                }
            }
            if(reqddays>days)
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