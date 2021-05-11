class Solution {
public:
    vector<vector<int>> ans;
    
    void combinations(int n,int k,int num,int last,vector<int>& temp)
    {   if(num == k)
        {
           ans.push_back(temp);
           return;
        }
        for(int i = last+1;i<=n;i++)
        {   temp.push_back(i);
            combinations(n,k,num+1,i,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        combinations(n,k,0,0,temp);
        return ans;
    }
};