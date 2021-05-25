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
    void unionfunc(int x,int y)
    {
        int lox = find(x);
        int loy = find(y);
        par[loy] = lox;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
            int parts = n;
            int redundant = 0;
            for(int i = 0;i<n;i++)
            {
                par.push_back(i);
            }
            for(vector<int>p:connections)
            {
                int l1 = find(p[0]);
                int l2 = find(p[1]);
                if(l1!=l2)
                {
                    par[l2] = l1;
                    parts--;
                }
                else
                {
                    redundant++;
                }
            }
        return parts-1<=redundant?parts-1:-1;
    }
};