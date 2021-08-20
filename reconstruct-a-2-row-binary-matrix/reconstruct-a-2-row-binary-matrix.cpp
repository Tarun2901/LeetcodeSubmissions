class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
            int col = colsum.size();
       
        
            vector<vector<int>> dp(2,vector<int>(col,0));
            
            for(int i = 0;i<col;i++)
            {
                if(upper == 0 && lower == 0 && colsum[i] > 0)
                {
                    return {};
                }
                if((upper == 0 || lower == 0) && colsum[i] == 2)
                {
                    return {};
                }
                if(colsum[i] == 2 && (upper>0) && (lower>0))
                {
                    dp[0][i] = 1;
                    dp[1][i] = 1;
                    upper--;
                    lower--;
                }
                if(upper>=lower && colsum[i] == 1)
                {
                    dp[0][i] = 1;
                    upper--;
                }
                else if(lower>upper && colsum[i] == 1)
                {
                    dp[1][i] = 1;
                    lower--;
                }
            }
        
        if(upper>0 || lower>0)
        {
            return {};
        }
        return dp;
    }
};