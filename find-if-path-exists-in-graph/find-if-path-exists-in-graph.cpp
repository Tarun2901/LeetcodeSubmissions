class Solution {
public:
    
    bool dfs(int node,int end,vector<int> graph[],int n,vector<int>& visited)
    {
        visited[node] = 1;
        if(node == end)
        {
            return true;
        }
        bool res = false;
        for(auto a:graph[node])
        {
            if(visited[a] == 0)
            {
                res = res || dfs(a,end,graph,n,visited);
            }
        }
        
        return res;
    }
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
            vector<int> graph[n];
        
        for(int i = 0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        vector<int> visited(n,0);
        
        bool res = dfs(start,end,graph,n,visited);
        return res;
    }
};