class Solution {
public:
    
    void solve(vector<vector<int>>& grid, int x,int y, int row,int col)
    {
        if(x<0||x>=row||y<0||y>=col||grid[x][y]==1)
        {
            return;
        }
        //unmark and then dfs calls for all nbrs
        grid[x][y] = 1;
        solve(grid,x+1,y,row,col);
        solve(grid,x-1,y,row,col);
        solve(grid,x,y+1,row,col);
        solve(grid,x,y-1,row,col);

    }
    int closedIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        //Call DFS and unmark for all corner zeros and then count number of connected components
        
        for(int i = 0;i<row;i++)
        {
            for(int j = 0;j<col;j++)
            {
                if(i==0||j==0||i==row-1||j==col-1)
                {
                    if(grid[i][j]==0)
                    {
                        solve(grid,i,j,row,col);
                    }
                }
            }
        }
        //Now count the number of connected components
        int count = 0;
        for(int i = 0;i<row;i++)
        {
            for(int j = 0;j<col;j++)
            {
                if(grid[i][j] == 0)
                {
                    count++;
                    solve(grid,i,j,row,col);
                }
            }
        }
        return count;
    }
};