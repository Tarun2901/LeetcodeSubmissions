class Solution {
public:

    int dfs(vector<vector<int>>& grid,int x,int y,int row,int col,int area)
    {   
        if(x<0||x>=row||y<0||y>=col||grid[x][y]==0)
        {
            return area;
        }
        //Mark vis and call the neighbours
        
        grid[x][y] = 0;
        area++;
        area = dfs(grid,x,y-1,row,col,area);
        area = dfs(grid,x,y+1,row,col,area);
        area = dfs(grid,x-1,y,row,col,area);
        area = dfs(grid,x+1,y,row,col,area);
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
       
        int row = grid.size();
        int col = grid[0].size();
        int maxarea = 0;
        vector<vector<int>>vis(row,vector<int>(col,0));
        for(int i = 0;i<row;i++)
        {
            for(int j = 0;j<col;j++)
            {
                if(grid[i][j] == 1)
                { 
                    int area = dfs(grid,i,j,row,col,0);
                    maxarea = max(area,maxarea);
                }
            }
        }
        return maxarea;
    }
};