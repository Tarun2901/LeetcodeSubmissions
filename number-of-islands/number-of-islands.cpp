class Solution {
public:
    
    void dfs(vector<vector<char>>&grid,int x,int y,int row, int col,vector<vector<int>>& visited)
    {   
        //Base case
        if(x<0||x>=row||y<0||y>=col||grid[x][y]=='0'||visited[x][y]==1)
        {
            return;
        }
        //4 calls
        visited[x][y] = 1;
        dfs(grid,x,y-1,row,col,visited);
        dfs(grid,x,y+1,row,col,visited);
        dfs(grid,x+1,y,row,col,visited);
        dfs(grid,x-1,y,row,col,visited);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0)
        {
            return 0;
        }
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>>visited(row,vector<int>(col,0));
        int count = 0;
        for(int i = 0;i<row;i++)
        {
            for(int j = 0;j<col;j++)
            {
                if(visited[i][j] == 0 && grid[i][j] == '1')
                {
                  dfs(grid,i,j,row,col,visited);
                  count++;
                }
            }
        }
        return count;
    }
};