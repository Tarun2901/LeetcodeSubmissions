class Solution {
public:
    vector<vector<int>>ans;

    void constructAnswer(vector<int>& nums,int n,int idx,vector<int> res)
    {
        if(idx>=n)
        {
            ans.push_back(res);
            return;
        }
        constructAnswer(nums,n,idx+1,res);
        while(idx+1<n && nums[idx]==nums[idx+1])
        {
            res.push_back(nums[idx]);
            ++idx;
        }
        res.push_back(nums[idx]);        
        constructAnswer(nums,n,idx+1,res);
    }
   
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int idx = 0;
        vector<int> res;
        constructAnswer(nums,n,idx,res);
        return ans;
    }   
};