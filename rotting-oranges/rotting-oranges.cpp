class Solution {
public:
        int count = 0;
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;
        int row = grid.size();
        int col = grid[0].size();
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({{i,j},0});
                }
            }
        }
        
        while(!q.empty())
        {
            int x = q.front().first.first;
            int y = q.front().first.second;
            count = q.front().second;
            q.pop();
            if(x+1<row)
            {
                if(grid[x+1][y]==1)
                {   grid[x+1][y]=2;
                    q.push({{x+1,y},count+1});
                }
            }
             if(x-1>=0)
            {
                if(grid[x-1][y]==1)
                {   grid[x-1][y]=2;
                    q.push({{x-1,y},count+1});
                }
            }
             if(y+1<col)
            {
                if(grid[x][y+1]==1)
                {   grid[x][y+1] = 2;
                    q.push({{x,y+1},count+1});
                }
            }
             if(y-1>=0)
            {
                if(grid[x][y-1]==1)
                {   grid[x][y-1] = 2;
                    q.push({{x,y-1},count+1});
                }
            }
        }
        for(int i = 0;i<row;i++)
        {
            for(int j = 0;j<col;j++)
            {
                if(grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        return count;
    }
};