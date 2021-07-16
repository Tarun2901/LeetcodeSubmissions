class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int obsp = -prices[0];
        int ossp = 0;
        int ocsp = 0;
        
        for(int i = 1;i<prices.size();i++)
        {
            int nbsp = 0;
            int nssp = 0;
            int ncsp = 0;
            
            nbsp = max(obsp,ocsp-prices[i]);
            nssp = max(ossp,obsp+prices[i]);
            ncsp = max(ocsp,ossp);
            
            ossp = nssp;
            obsp = nbsp;
            ocsp = ncsp;
        }
        
        return ossp;
    }
};