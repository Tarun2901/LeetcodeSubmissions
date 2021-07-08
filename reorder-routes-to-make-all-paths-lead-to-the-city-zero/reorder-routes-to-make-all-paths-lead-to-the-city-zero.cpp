class Solution {
public:
    
    
    int ans = 0;
    
    bool dfs(int node,vector<vector<int>> &graph,vector<int> &visited)
    {
        visited[node] = 1;
        bool label = false;
        for(auto it:graph[node])
        {
            if(visited[it] == true)
            {
                ans++;
                return true;
            }
            else if(visited[it] == false)
            {
                label = dfs(it,graph,visited);
            }
        }
        if(label == true)
        {
            ans++;
        }
        return label;
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        for(int i = 0;i<n-1;i++)
        {
            int u = connections[i][0];
            int v = connections[i][1];
            
            graph[u].push_back(v);
        }
        
        vector<int>visited(n,0);
        
        for(int i = 0;i<n;i++)
        {
            if(visited[i] == 0)
            {
                bool ans = dfs(i,graph,visited);
            }
        }
        
        return (n-1) - ans;
    }
};