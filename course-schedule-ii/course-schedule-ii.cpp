class Solution {
public: vector<int>topo;
    bool toposort(int V,vector<int> adj[])
{
	vector<int>InDegree(V,0);
	//Make InDegree array
	for(int i = 0;i<V;i++)
	{
		for(auto it:adj[i])
		{
			InDegree[it]++;
		}
	}
    //Make queue
    queue<int> q;
    //Push in queue those elements which have an InDegree of 0

    for(int i = 0;i<V;i++)
    {
    	if(InDegree[i] == 0)
    	{
    		q.push(i);
    	}
    }

    //apply BFS using queue
    int cnt = 0;
    while(!q.empty())
    {
    	int node = q.front();
        q.pop();
        cnt++;
        topo.push_back(node);
        for(auto it:adj[node])
        {  
        	 InDegree[it]--;
        	 if(InDegree[it] == 0)
        	 {
        	 	q.push(it);
        	 }
        }
    }
   if(cnt == V)
  {
    return false;;
  }
  return true;
 }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int>dummy;
        for(int i = 0;i<prerequisites.size();i++)
        {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            adj[u].push_back(v);
        }
     bool ans = toposort(numCourses,adj);
        if(ans)
        {
            return dummy;
        }
        return topo;
    }
};