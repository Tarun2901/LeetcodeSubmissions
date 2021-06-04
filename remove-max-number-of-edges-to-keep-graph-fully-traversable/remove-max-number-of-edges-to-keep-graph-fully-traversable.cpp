class Solution {
public:
    int t1 = 0;
    int t2 = 0;
    vector<int>par1;
    vector<int>par2;
    int count = 0;
    int find1(int x)
    {
        if(x == par1[x])
        {
            return x;
        }
        return par1[x] = find1(par1[x]);
    }
    int find2(int x)
    {
        if(x == par2[x])
        {
            return x;
        }
        return par2[x] = find2(par2[x]);
    }
    void merge1(int x,int y)
    {
        par1[y] = x;
    }
    void merge2(int x,int y)
    {
        par2[y] = x;
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
          for(int i = 0;i<=n;i++)
          {
              par1.push_back(i);
              par2.push_back(i);
          }
    
        int diff = 0;
        for(int i = 0;i<edges.size();i++)
        {
            if(edges[i][0] == 3)
            {   
                int x = edges[i][1];
                int y = edges[i][2];
                if(find1(x)!=find1(y))
                {
                    merge1(find1(x),find1(y));
                    merge2(find2(x),find2(y));
                    diff++;
                }
            }
        }
        for(int i = 0;i<edges.size();i++)
        {
            if(edges[i][0] == 1)
            {
               int x = edges[i][1];
                int y = edges[i][2];
                if(find1(x)!=find1(y))
                {
                    merge1(find1(x),find1(y));
                    t1++;
                }
            }
            if(edges[i][0] == 2)
            {
                int x = edges[i][1];
                int y = edges[i][2];
                if(find2(x)!=find2(y))
                {
                    merge2(find2(x),find2(y));
                    t2++;
                }
         
            }
        }
     if(t1+diff<n-1|diff+t2<n-1)
     {
        return -1;
     }
        
        return edges.size() -t1-t2-diff;
    }
};