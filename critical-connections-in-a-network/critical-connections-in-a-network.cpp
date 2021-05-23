class Solution {
public:
    vector<vector<int>> res;
    
    int level = 0;

int countsrc = 0;
int actualsrc = 0;
void articulate(int src,vector<int> graph[],vector<int>& par,vector<int>& disc, vector<int>& low,vector<int>& vis,vector<bool>& ap)
{
    disc[src] = level;
    low[src] = level;
    vis[src] = 1;
    for(auto v:graph[src])
    {   if(v == par[src])
       {
          continue;
       }
        if(vis[v]==true)
        {
          low[src] = min(low[src],disc[v]);
        }
        else
        {
          if(src == actualsrc)
          {
            countsrc++;
          }
          par[v] = src;
          level++;
          articulate(v,graph,par,disc,low,vis,ap);
          if(low[v]>disc[src])
          {
                ap[src] = true;
                vector<int> temp = {src,v};
                res.push_back(temp);
          }
          low[src] = min(low[src],low[v]);
        }
    }
}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> graph[n];
        for(int i = 0;i<connections.size();i++)
        {
            int u  = connections[i][0];
            int v = connections[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
         vector<int>par(n);
  vector<int>disc(n);
  vector<int>low(n);
  vector<int>vis(n);
  vector<bool>ap(n,false);
  int src = 0;
  articulate(src,graph,par,disc,low,vis,ap);
        return res;
        
    }
};