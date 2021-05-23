class Solution {
public:
    
    void solve(vector<vector<int>>& grid,int x,int y,int color,vector<vector<bool>>& visited,int oc)
    {   //Mark the node with the required colour
        grid[x][y] = color;
        visited[x][y] = true;
        int lvlcount = 0;
        //top
        if(x-1>=0)
        {   if(grid[x-1][y] == color && visited[x-1][y] == true)
            {
                    lvlcount++;
            }
            else if(grid[x-1][y] == oc && visited[x-1][y] == false)
            {
                 lvlcount++;
                solve(grid,x-1,y,color,visited,oc);
            }
        }
        //right 
         if(y+1<grid[0].size())
        {   if(grid[x][y+1] == color && visited[x][y+1] == true)
            {
                    lvlcount++;
            }
            else if(grid[x][y+1] == oc && visited[x][y+1] == false)
            {
                lvlcount++;
                solve(grid,x,y+1,color,visited,oc);
            }
        }
        //down
          if(x+1<grid.size())
        {   if(grid[x+1][y] == color && visited[x+1][y] == true)
            {
                    lvlcount++;
            }
            else if(grid[x+1][y] == oc && visited[x+1][y] == false)
            {
                 lvlcount++;
                solve(grid,x+1,y,color,visited,oc);
            }
        }
        //left 
        if(y-1>=0)
        {   if(grid[x][y-1] == color && visited[x][y-1] == true)
            {
                    lvlcount++;
            }
            else if(grid[x][y-1] == oc && visited[x][y-1] == false)
            {
                 lvlcount++;
                solve(grid,x,y-1,color,visited,oc);
            }
        }
        
        if(lvlcount == 4)
        {
            grid[x][y] = oc;
        }
        
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
            int row = grid.size();
            int col = grid[0].size();
            vector<vector<bool>> visited(row,vector<bool>(col));
            solve(grid,r0,c0,color,visited,grid[r0][c0]);
            return grid;
    }
};