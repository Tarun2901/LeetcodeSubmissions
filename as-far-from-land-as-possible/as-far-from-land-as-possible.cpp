class Solution {
public:
    int mx = INT_MIN;
    int maxDistance(vector<vector<int>>& grid) {
        
        int row = grid.size();
        int col = row;
        
        
        queue<pair<int,pair<int,int>>> q;  //dist,point coordinate
        
        for(int i = 0;i<row;i++)
        {
            for(int j = 0;j<col;j++)
            {
                if(grid[i][j] == 1)
                {
                    q.push(make_pair(0,make_pair(i,j)));
                }
            }
        }
        
        while(q.size()>0)
        {
            int dist = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();
            
            if(x-1>=0 && grid[x-1][y] == 0)
            {   mx = max(mx,dist+1);
                q.push(make_pair(dist+1,(make_pair(x-1,y))));
                grid[x-1][y] = 1;
            }
            if(y+1<col && grid[x][y+1] == 0)
            {   mx = max(mx,dist+1);
                q.push(make_pair(dist+1,(make_pair(x,y+1))));
                grid[x][y+1] = 1;
            }
            if(x+1<row && grid[x+1][y] == 0)
            {   mx = max(mx,dist+1);
                q.push(make_pair(dist+1,(make_pair(x+1,y))));
                grid[x+1][y] = 1;
            }
            if(y-1>=0 && grid[x][y-1] == 0)
            {   mx = max(mx,dist+1);
                q.push(make_pair(dist+1,(make_pair(x,y-1))));
                grid[x][y-1] = 1;
            }
        }
        return mx == INT_MIN?-1:mx;
    }
};