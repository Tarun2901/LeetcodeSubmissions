class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0;
        int j = 0;
        int n = nums.size();
        int ans = INT_MAX;
        int currsum = 0;

    
        while(j<n)
        {
            currsum+=nums[j];
            j++;
            while(currsum>=target)
            {
                ans = min(j-i,ans);
                currsum-=nums[i];
                i++;
            }
        }
  
        return ans==INT_MAX?0:ans;
    }
};