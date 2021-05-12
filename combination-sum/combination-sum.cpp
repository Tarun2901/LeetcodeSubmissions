class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int>& coins, int target,vector<int>&ans,int amtsf,int li)
    {   if(amtsf == target)
       {
        res.push_back(ans);
        return;
        }
        
        for(int i = li;i<coins.size();i++)
        {
            if(amtsf+coins[i]<=target)
            {
                ans.push_back(coins[i]);
                helper(coins,target,ans,amtsf+coins[i],i);
                ans.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& coins, int target) {
        vector<int> ans;
        helper(coins,target,ans,0,0);
        return res;
    }
};