class Solution {
public:
    
bool checkCyclewithDFS(int node, vector<int> adj[],vector<int> &vis,vector<int> &dfsvis)
{
   vis[node] = 1;
   dfsvis[node] = 1;
   for(int it:adj[node])
   {
    if(vis[it] == 0)
    {
      if(checkCyclewithDFS(it,adj,vis,dfsvis) == true)
      {
        return true;
      }
    }
    else if(dfsvis[it]==1)
    {
      return true;
    }
   }

   dfsvis[node] = 0;
   return false;
}

bool isCycle(int V,vector<int> adj[])
{
  vector<int>vis(V,0);
  vector<int>dfsvis(V,0);
  for(int i = 0;i<V;i++)
  {
    if(vis[i] == 0)
    {
      if(checkCyclewithDFS(i,adj,vis,dfsvis))
      {
         return true;
      }
    }
  }
  return false;
}
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        for(int i = 0;i<prerequisites.size();i++)
        {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            adj[u].push_back(v);
        }
        bool res = isCycle(numCourses,adj);
        if(res)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};