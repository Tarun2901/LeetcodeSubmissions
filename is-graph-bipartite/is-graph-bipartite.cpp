class Solution {
public:
    
    bool checkBipartite(int node,int V,vector<vector<int>>&graph,vector<int>& vis)
    {
        queue<int> q;
        vis[node] = 1;
        q.push(node);
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto it:graph[node])
            {
                if(vis[it]==-1)
                {
                    vis[it] = 1-vis[node];
                    q.push(it);
                }
                else if(vis[it]==vis[node])
                {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
    vector<int> vis(graph.size(),-1);    
    for(int i = 0;i<graph.size();i++)
    {
        if(vis[i] == -1)
        {
            if(checkBipartite(i,graph.size(),graph,vis)==false)
            {
                return false;
            }
        }
    }
        return true;
    }
};