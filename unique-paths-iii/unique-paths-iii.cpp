class Solution {
public:
    int res = 0;
    int empty = 1;
    void solve(int sr,int sc,int er,int ec,vector<vector<int>>& grid,vector<vector<int>>& visited)
    {
        if(sr<0 || sr>=grid.size() || sc<0 || sc>=grid[0].size() || visited[sr][sc] == 1 || grid[sr][sc] == -1)
        {
            return;
        }
        if(sr == er && sc == ec)
        {
            if(empty == 0){
                res++;
            }
            return;
        }
        
        visited[sr][sc] = 1;
        empty--;
        solve(sr+1,sc,er,ec,grid,visited);
        solve(sr-1,sc,er,ec,grid,visited);
        solve(sr,sc+1,er,ec,grid,visited);
        solve(sr,sc-1,er,ec,grid,visited);
        visited[sr][sc] = 0;
        empty++;
    }
    
    
    int uniquePathsIII(vector<vector<int>>& grid) {
            int row = grid.size();
            int col = grid[0].size();
            int sr = 0;
            int sc = 0;
            int er = 0;
            int ec = 0;
            vector<vector<int>>visited(row,vector<int>(col,0));
            for(int i = 0;i<row;i++)
            {
                for(int j = 0;j<col;j++)
                {
                    if(grid[i][j] == 1)
                    {
                        sr = i;
                        sc = j;
                    }
                    if(grid[i][j] == 2)
                    {
                        er = i;
                        ec = j;
                    }
                    if(grid[i][j] == 0)
                    {
                        empty++;
                    }
                }
            }
            
        solve(sr,sc,er,ec,grid,visited);
        return res;  
    }
};