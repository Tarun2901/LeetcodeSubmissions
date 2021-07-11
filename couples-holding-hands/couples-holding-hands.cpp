class Solution {
public:
    vector<int> par;

    int find_set(int v) {
    if (v == par[v])
        return v;
    return par[v] = find_set(par[v]);
    }
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        par[b] = a;
    }
}
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        for(int i = 0;i<row.size();i++)
        {
            par.push_back(i);
        }
   
        
        for(int i = 0;i<row.size();i+=2)
        {
            union_sets(i+1,i);
        }
        
    int count = 0;
        
        for(int i = 0;i<row.size();i+=2)
        {
            int a = find_set(row[i]);
            int b = find_set(row[i+1]);
            if(a == b)
            {
                continue;
            }
            else
            {
                int k = i+2;
                while(k<row.size())
                {
                    if(find_set(row[k]) == a)
                    {
                        swap(row[k],row[i+1]);
                        count++;
                    }
                    k++;
                }
            }
        }
        return count;
    }
};