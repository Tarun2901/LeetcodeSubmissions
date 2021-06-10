class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> q;
        int count = 0;
        int n = stations.size();
        int i = 0;
        while(startFuel<target)
        {
            while(i<n &&stations[i][0]<=startFuel)
            {
                q.push(stations[i][1]);
                i++;
            }
            
            if(q.size() == 0)
            {
                return -1;
            }
            startFuel+=q.top();
            q.pop();
            count++;
        }
        
        return count;
    }
};