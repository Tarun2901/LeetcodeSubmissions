class Solution {
public:
    
bool dfs(int node, vector<vector<int>> &graph,vector<int> &vis,vector<int> &dfsvis,vector<bool> &ans)
{
   vis[node] = 1;
   dfsvis[node] = 1;
   for(int it:graph[node])
   {
    if(vis[it] == 0)
    {
      if(dfs(it,graph,vis,dfsvis,ans) == true)
      { ans[node] = false;
        return true;
      }
    }
    else if(dfsvis[it]==1)
    {   ans[node] = false;
        return true;
    }
   }

   dfsvis[node] = 0;
   return false;
}

    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>visited(n,0);
        vector<int>dfsvis(n,0);
        vector<bool>ans(n,true);
        for(int i = 0;i<graph.size();i++)
        {
            if(visited[i] == 0)
            {
               dfs(i,graph,visited,dfsvis,ans); 
            }
        }
        vector<int> res;
        for(int i = 0;i<n;i++)
        {
            if(ans[i] == true)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};