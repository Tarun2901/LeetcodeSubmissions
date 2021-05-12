class Solution {
public:
    vector<vector<int>> res;
  
    void helper(int k,int n,vector<int>& ans,int asf,int idx,vector<bool>& visited,int li)
    {  
        if(idx == k)
       {
          if(asf == n)
          {
              res.push_back(ans);
          }
            return;
       }
        
        for(int i = li+1;i<=9;i++)
        {
            if(asf+i<=n&&visited[i]==false)
            {   ans.push_back(i);
                visited[i] = true;
                helper(k,n,ans,asf+i,idx+1,visited,i);
                visited[i] = false;
                ans.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ans;
        vector<bool>visited(10);
        helper(k,n,ans,0,0,visited,0);
        return res;
    }
};