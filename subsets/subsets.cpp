class Solution {
public: vector<vector<int>> ans;
    
    void constructAnswer(vector<int>& nums,int n,int idx,vector<int> res)
    {
        if(idx>=n)
        {
            ans.push_back(res);
            return;
        }
        
        constructAnswer(nums,n,idx+1,res);
        res.push_back(nums[idx]);
        constructAnswer(nums,n,idx+1,res);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        int idx = 0;
        int n = nums.size();
        vector<int> res;
        constructAnswer(nums,n,0,res);
        return ans;
    }
};