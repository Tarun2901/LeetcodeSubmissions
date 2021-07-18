class Solution {
public:
    
    int solve(int i,int j,int row,int col,vector<vector<int>>& grid,vector<vector<int>>& visited)
    {
        if(i<0 || i>=row || j<0 || j>=col || grid[i][j] == 0 || visited[i][j] == 1)
        {
            return 0;
        }
        visited[i][j] = 1;
        
        int call1 = solve(i+1,j,row,col,grid,visited);
        int call2 = solve(i,j+1,row,col,grid,visited);
        int call3 = solve(i-1,j,row,col,grid,visited);
        int call4 = solve(i,j-1,row,col,grid,visited);
        
        
        //postorder
        visited[i][j] = 0;
        return grid[i][j] + max(max(call1,call2),max(call3,call4));
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int res = INT_MIN;
        vector<vector<int>>visited(row,vector<int>(col,0));
        
        for(int i = 0;i<row;i++)
        {
            for(int j = 0;j<col;j++)
            {
                if(grid[i][j]>0)
                {
                    res = max(res,solve(i,j,row,col,grid,visited));
                }
            }
        }
        return res;
    }
};