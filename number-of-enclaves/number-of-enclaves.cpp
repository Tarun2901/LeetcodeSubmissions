class Solution {
public:
    
    void dfs(vector<vector<int>>&grid,int x,int y,int row,int col)
    {
        if(x<0||x>=row||y<0||y>=col||grid[x][y] == 0)
        {
            return;
        }
        //Mark visited and make recursive DFS calls
        grid[x][y] = 0;
        dfs(grid,x-1,y,row,col);
        dfs(grid,x,y+1,row,col);
        dfs(grid,x+1,y,row,col);
        dfs(grid,x,y-1,row,col);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        //Intuition: The idea is to call DFS for all the 1's present on all the corners and turn all connected 1's to 0's and then we can count the number of ones left
        
        int row = grid.size();
        int col = grid[0].size();
        //Loop for the left boundary
        for(int i = 0;i<row;i++)
        {
            if(grid[i][0]==1)
            {
                dfs(grid,i,0,row,col);
            }
        }
        //Loop for the top boundary
        for(int i = 1;i<col;i++)
        {
            if(grid[0][i]==1)
            {
                dfs(grid,0,i,row,col);
            }
        }
        //Loop for the right boundary
        for(int i = 1;i<row;i++)
        {
            if(grid[i][col-1]==1)
            {
                dfs(grid,i,col-1,row,col);
            }
        }
        //Loop for the bottom boundary
        for(int i = 1;i<col;i++)
        {
            if(grid[row-1][i] == 1)
            {
                dfs(grid,row-1,i,row,col);
            }
        }
        //Count number of ones left
        int count = 0;
        for(int i = 0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j] == 1)
                {
                    count++;
                }
            }
        }
        return count;
    }
};