class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int res = INT_MAX;
    
        int mx = INT_MIN;
        
        for(int i = 0;i<piles.size();i++)
        {
            mx = max(piles[i],mx);
        }
        
        int lo = 1;
        int hi = mx;
        
        while(lo<=hi)
        {
            int mid = lo + (hi-lo)/2;
            int total = 0;
            for(auto p:piles)
            {
                total+= ceil((p*1.0)/mid);
            }
            if(total>h)
            {
                lo = mid+1;
            }
            else
            {
                res = min(res,mid);
                hi = mid-1;
            }
        }
        return res;
    }
};