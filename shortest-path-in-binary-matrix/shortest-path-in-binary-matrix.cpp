class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int res = 1;
        vector<vector<int>> dir = {{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}};
        int row = grid.size();
        if(row == 0) return -1;
        int col = grid[0].size();
        if(col == 0 ) return -1;
        if(grid[0][0] != 0 | grid[row-1][col-1] != 0) return -1;
        queue<pair<int,int>> q;
        
        q.push({0,0});
        grid[0][0] = 1;
        while(q.size()>0)
        {
            auto p = q.front();
            
            int x = p.first;
            int y = p.second;
            if(x == row -1 && y == col-1)
            {return grid[x][y];
            }
            q.pop();
            
            for(auto d:dir)
            {
                int xn = x+d[0];
                int yn = y+d[1];
                
                if(xn>=0 && xn<row&& yn>=0 && yn<col&& grid[xn][yn] == 0)
                {
                    q.push({xn,yn});
                    grid[xn][yn] = grid[x][y] + 1;
                    
                }
            }
        }
        
        return -1;
    }
};