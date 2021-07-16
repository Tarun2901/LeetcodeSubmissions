class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mps = 0;
        int n = prices.size();
        vector<int> dps(n,0);
        int runningMin = prices[0];
        
        for(int i = 1;i<n;i++)
        {
            runningMin = min(runningMin,prices[i]);
            int tempProfit = prices[i] - runningMin;
            mps = max(mps,tempProfit);
            dps[i] = mps;
        }
            
        int mpb = 0;
        int runningMax = prices[n-1];
        vector<int> dpb(n,0);
        for(int i = n-2;i>=0;i--)
        {
            runningMax = max(runningMax,prices[i]);
            int tempProfit = runningMax-prices[i];
            mpb = max(mpb,tempProfit);
            dpb[i] = mpb;
        }
        int ans = INT_MIN;
        for(int i = 0;i<n;i++)
        {
            ans = max(ans,dps[i]+dpb[i]);
        }
        
        return ans;
    }
};