class Solution {
public:
    vector<int> par;
    int find(int x)
    {
        if(x == par[x])
        {
            return x;
        }
        return par[x] = find(par[x]);
    }

    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
            int n = edges.size();
            for(int i = 0;i<=n;i++)
            {
                par.push_back(i);
            }
        
            for(int i = 0;i<edges.size();i++)
            {
                int p1 = find(edges[i][0]);
                int p2 = find(edges[i][1]);
                if(p1!=p2)
                {
                    par[p1] = p2;
                }
                else
                {
                    return {edges[i][0],edges[i][1]};
                }
            }
        return {};
    }
};