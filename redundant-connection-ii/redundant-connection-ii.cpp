class Solution {
public: vector<int> par;
        vector<int> ans;
    int find(int x)
    {
        if(x == par[x])
        {
            return x;
        }
        return par[x] = find(par[x]);
    }

    bool DSU(vector<vector<int>>& edges,int blacklist)
    {
        int n = edges.size();
        for(int i = 0;i<=n;i++)
        {
            par.push_back(i);
        }
        for(int i = 0;i<n;i++)
        {
            if(i == blacklist)
            {
                continue;
            }
            int lo1 = find(edges[i][0]);
            int lo2 = find(edges[i][1]);
            if(lo1!=lo2)
            {
                par[lo2] = lo1;
            }
            else
            {   ans = edges[i];
                return false;
            }
        }
        return true;
    }
   
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>inDegree(n+1,-1);
        
        for(int i = 0;i<edges.size();i++)
        {
            if(inDegree[edges[i][1]] == -1)
            {
                 inDegree[edges[i][1]] = i;
            }
            else if(inDegree[edges[i][1]]!=-1)
            {
                if(DSU(edges,i) == true)
                {
                    return {edges[i][0],edges[i][1]};
                }
                else
                {
                    return {edges[inDegree[edges[i][1]]][0],edges[inDegree[edges[i][1]]][1]};
                }
            }
        }
         //Handling the only cycle present case
        bool ans1 = DSU(edges,-1);
        return ans;
    }
};