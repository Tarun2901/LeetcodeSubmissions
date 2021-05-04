class Solution {
public:
    int square(int x)
    {
        return x*x;
    }
    vector<int> sortedSquares(vector<int>& nums) {
          vector<int> ans(nums.size());
          for(int i = 0;i<nums.size();i++)
          {
              ans[i] = square(nums[i]);
          }
        sort(ans.begin(),ans.end());
        return ans;
    }
};