class Solution {
public:
     vector<vector<int>> res;
  
    void helper(vector<int>& coins,int target,vector<int>& ans,int asf,int li)
    {  
        if(asf == target)
        {
            res.push_back(ans);
            return;
        }
        else if(asf>target)
        {
            return;
        }
        for(int i = li+1;i<coins.size();i++)
        {   if(coins[i]>target)
        {
            break;
        }
            if(asf+coins[i]<=target)
            {   ans.push_back(coins[i]);
                helper(coins,target,ans,asf+coins[i],i);
                ans.pop_back();
            }
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& coins, int target) {
        vector<int> ans;
        sort(coins.begin(),coins.end());
        helper(coins,target,ans,0,-1);
        sort(res.begin(),res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};