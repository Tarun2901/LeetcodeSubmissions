class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>rows(n,-1);
        vector<int>cols(n,-1);
        
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                rows[i] = max(rows[i],grid[i][j]);
            }
        }
        
        for(int j = 0;j<n;j++)
        {
            for(int i=0;i<n;i++)
            {
                cols[j] = max(cols[j],grid[i][j]);
            }
        }
        
        int sum = 0;
        
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                sum+=min(rows[i],cols[j])-grid[i][j];
            }
        }
        
       return sum;
    }
};