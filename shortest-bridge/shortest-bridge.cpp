class Solution {
public:
    void dfs(vector<vector<int>>&grid, int x,int y,int row,int col)
    {
        if(x<0||y<0||x>=row||y>=col||grid[x][y]==0||grid[x][y] == 2)
        {
            return;
        }
        grid[x][y] = 2;
        dfs(grid,x+1,y,row,col);
        dfs(grid,x-1,y,row,col);
        dfs(grid,x,y-1,row,col);
        dfs(grid,x,y+1,row,col);
    }

    int shortestBridge(vector<vector<int>>& grid) {
       int row = grid.size();
       int col = grid.size();
       int lb = 0;
       vector<vector<int>>visited(row,vector<int>(col,0));
        for(int i = 0;i<row;i++)
        {
            for(int j = 0;j<col;j++)
            {
                if(grid[i][j] == 1)
                {
                    dfs(grid,i,j,row,col);
                    lb = 1;
                    break;
                }
            }
            if(lb == 1)
            {
                break;
            }
        }
        for(int i = 0;i<row;i++)
        {
            for(int j = 0;j<col;j++)
            {
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }
        queue<pair<pair<int,int>,int>> q;
        for(int i = 0;i<row;i++)
        {
            for(int j = 0;j<col;j++)
            {   
                if(grid[i][j] == 2)
                {  
                    visited[i][j]=1;
                    q.push(make_pair(make_pair(i,j),0));
                }
            }
        }
        while(!q.empty())
        {
            
           int x = q.front().first.first;
           int y = q.front().first.second;
           int dist = q.front().second;
            q.pop();
            if(y-1>=0 && grid[x][y-1] == 1)
            {
                return dist;
            }
            if(y-1>=0 && grid[x][y-1] == 0)
            {
                visited[x][y-1] = 1;
                grid[x][y-1] = 2;
                q.push(make_pair(make_pair(x,y-1),dist+1));
            }
            if(y+1<col && grid[x][y+1] == 1)
            {
                return dist;
            }
            if(y+1<col && grid[x][y+1] == 0)
            {
                visited[x][y+1] = 1;
                grid[x][y+1] = 2;
                q.push(make_pair(make_pair(x,y+1),dist+1));
            }
            if(x-1>=0 && grid[x-1][y] == 1)
            {
                return dist;
            }
            if(x-1>=0 && grid[x-1][y] == 1)
            {
                visited[x-1][y] = 1;
                grid[x-1][y] = 2;
                 q.push(make_pair(make_pair(x-1,y),dist+1));
            }
            if(x+1<col && grid[x+1][y] == 1)
            {
                return dist;
            }
            if(x+1<col && grid[x+1][y] == 0)
            {
                visited[x+1][y] = 1;
                grid[x+1][y] = 2;
                q.push(make_pair(make_pair(x+1,y),dist+1));
            }
            
            
             
        }
        return 0;
    }
};