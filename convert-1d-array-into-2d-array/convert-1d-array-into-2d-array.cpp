class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        
        if(original.size()!=n*m)
        {
            return {};
        }
        
        vector<vector<int>> dp(m,vector<int>(n));
        for(int i = 0;i<original.size();i++)
        {
            dp[i/n][i%n] = original[i];
        }
        return dp;
    }
};