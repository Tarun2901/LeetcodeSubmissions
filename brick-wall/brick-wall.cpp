class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
            int omax = 0;
            map<int,int> mp;
        
            for(int i = 0;i<wall.size();i++)
            {   int sum = 0;
                for(int j = 0;j<wall[i].size()-1;j++)
                {
                    sum += wall[i][j];
                    mp[sum]++;
                }
            }
        for(auto p:mp)
        {
            omax = max(omax,p.second);
        }
        
        return wall.size()-omax;
    }
};