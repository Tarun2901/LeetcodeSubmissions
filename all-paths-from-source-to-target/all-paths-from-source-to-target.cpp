class Solution {
public: vector<vector<int>> res;
        vector<int>ans;
    void solve(vector<vector<int>>& graph,int idx)
    {  
       ans.push_back(idx);
        if(idx == graph.size()-1)
        {
            res.push_back(ans); 
        }
        else for(int node:graph[idx])
        {      
          solve(graph,node);  
        }
        ans.pop_back();
     
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
         int n = graph.size();
         int idx = 0;
         solve(graph,idx);
         return res;
    }
};