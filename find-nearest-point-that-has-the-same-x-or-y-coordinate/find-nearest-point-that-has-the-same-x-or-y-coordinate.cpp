class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int mindist = (int)1e9;
        
        for(int i = 0;i<points.size();i++)
        {
            int x1 = points[i][0];
            int y1 = points[i][1];
            if(x1 == x || y1 == y)
            {
            int dist = abs(x1-x)+abs(y1-y);
            mindist = min(mindist,dist);
            }
        }
        
        for(int i = 0;i<points.size();i++)
        {
            int x1 = points[i][0];
            int y1 = points[i][1];
            if(mindist == abs(x1-x)+abs(y1-y) && (x1 == x || y1 == y))
            {
                return i;
            }
        }
        
        return -1;
    }
};