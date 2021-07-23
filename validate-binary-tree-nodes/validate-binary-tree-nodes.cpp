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
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
            par.resize(n);
            for(int i = 0;i<n;i++)
            {
                par[i] = i;
            }
            for(int i = 0;i<n;i++)
            {
                if(leftChild[i]!=-1)
                {
                    if(find_set(i)!=find_set(leftChild[i]) && par[leftChild[i]] == leftChild[i])
                    {
                        union_sets(i,leftChild[i]);
                    }
                    else
                    {
                        return false;
                    }
                }
                if(rightChild[i]!=-1)
                {
                    if(find_set(i)!=find_set(rightChild[i]) && par[rightChild[i]] == rightChild[i])
                    {
                        union_sets(i,rightChild[i]);
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        
            int count = 0;
        for(int i = 0;i<n;i++)
        {
            if(par[i] == i)
            {
                count++;
            }
        }
        return count == 1;
    }
};