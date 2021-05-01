class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minl = INT_MAX;
        int maxpro = 0;
        for(int i = 0;i<prices.size();i++)
        {
            if(prices[i]>minl)
            {
                maxpro = max(maxpro,prices[i]-minl);
            }
            else
            {
                minl = prices[i];
            }
        }
        return maxpro;
    }
};