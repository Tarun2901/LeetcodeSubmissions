class Solution {
public:
    vector<int> res;
    void solve(map<int,vector<int>> &mp, map<int,bool> &visited,int node)
    {
        visited[node] = true;
        res.push_back(node);
        for(auto it: mp[node])
        {
            if(visited[it] == false)
            {
                solve(mp,visited,it);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        int n = adjacentPairs.size() + 1;
        map<int,vector<int>> mp;
        
        for(int i = 0;i<n-1;i++)
        {
            int x1 = adjacentPairs[i][0];
            int x2 = adjacentPairs[i][1];
            mp[x1].push_back(x2);
            mp[x2].push_back(x1);
        }
        int root = 0;
        for(auto p:mp)
        {
            if(p.second.size() == 1)
            {
                root = p.first;
                break;
            }
        }
        map<int,bool> visited;
        solve(mp,visited,root);
        return res;
    }
};