class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        unordered_map<int,int> rst;
        
        vector<int> adj[n];
        
        for(int i = 0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        for(int i:restricted)
        {
                rst[i] = 1;
        }
        vector<int> visited(n,0);
        queue<int> q;
        int ans = 0;
        q.push(0);
        while(q.size() > 0)
        {
            int size = q.size();
            while(size--)
            {
                int val = q.front();
                visited[val] = 1;
                q.pop();
                if(rst[val] == 1)
                {
                    continue;
                }
                else
                {
                    ans++;
                    for(int i:adj[val])
                    {
                        if(visited[i]!=1)
                            q.push(i);
                    }
                }
            }
        }
        return ans;
    }
};