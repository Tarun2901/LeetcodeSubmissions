class Solution {
public:
    vector<int>par;
    int find(int x)
    {
        if(x == par[x])
        {
            return x;
        }
        return par[x]=find(par[x]);
    }
    void unionfunc(int x,int y)
    {
        int lox = find(x);
        int loy = find(y);
        par[loy] = lox;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(); 
      
        for(int i = 0;i<=n;i++)
        {
            par.push_back(i);
        }
        int count = n;
        
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(i!=j && isConnected[i][j] == 1 && find(i+1)!=find(j+1))
                {
                    unionfunc(i+1,j+1);
                    count--;
                }
            }
        }
        return count==0?1:count;
        
    }
};