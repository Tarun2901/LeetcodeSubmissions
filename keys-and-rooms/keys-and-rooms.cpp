class Solution {
public:
    
    void solve(vector<vector<int>>& rooms, int node, vector<int>& visited)
    {
        visited[node] = 1;
        for(auto v: rooms[node])
        {
          if(visited[v] == 0)
                {
                    solve(rooms,v,visited);
                }
        }
    }    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
            int n = rooms.size();
            vector<int> visited(n,0);
            solve(rooms,0,visited);
            for(int i = 0;i<n;i++)
            {
                if(visited[i] == 0)
                {
                    return false;
                }
            }
        return true;
    }
};