class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
            int ssp = 0;
            int bsp = -prices[0];
        
        for(int i = 1;i<prices.size();i++)
        {
            int nbsp = 0;
            int nssp = 0;
            nssp = max(ssp,bsp+prices[i]-fee);
            nbsp = max(bsp,ssp-prices[i]);
            bsp = nbsp;
            ssp = nssp;
        }
        return ssp;
    }
};