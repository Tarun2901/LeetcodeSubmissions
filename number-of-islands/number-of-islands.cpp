class Solution {
public:
     void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y, int rows, int cols){
        if(x >= rows || x < 0 || y >= cols || y < 0 || grid[x][y] == '0' || visited[x][y]){
            return;
        }
        visited[x][y] = true;
        dfs(grid, visited, x + 1, y, rows, cols);
        dfs(grid, visited, x, y + 1, rows, cols);
        dfs(grid, visited, x - 1, y, rows, cols);
        dfs(grid, visited, x, y - 1, rows, cols);                
    }
    
    int numIslands(vector<vector<char>>& grid) {
           if(grid.size() == 0)
           {
               return 0;
           }
        
           int rows = grid.size();
           int col = grid[0].size();
           vector<vector<bool>> visited(rows,vector<bool>(col,false));
           int count = 0;
           for(int i = 0;i<rows;i++)
           {
               for(int j = 0;j<col;j++)
               {
                   if(!visited[i][j]&&grid[i][j]=='1')
                   {
                       count++;
                       dfs(grid,visited,i,j,rows,col);
                   }
               }
           }
           return count;
    }
};