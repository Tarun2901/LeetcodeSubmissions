class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        vector<int> prefixMax(nums.size());
        vector<int>suffixMax(nums.size());
        
        prefixMax[0] = nums[0];
        
        for(int i = 1;i<nums.size();i++)
        {
            if(i%k == 0)
            {
                prefixMax[i] = nums[i];
            }
            else
            {    
                prefixMax[i] = max(prefixMax[i-1],nums[i]);
            }
        }
        
        
        suffixMax[nums.size()-1] = nums[nums.size()-1];
        for(int i = nums.size()-2;i>=0;i--)
        {
            if((i+1)%k == 0)
            {
                suffixMax[i] = nums[i];
            }
            else
            {
                suffixMax[i] = max(suffixMax[i+1],nums[i]);
            }
        }
        
        for(int i = 0;i<=nums.size()-k;i++)
        {
            if(i%k == 0)
            {
                ans.push_back(suffixMax[i]);
            }
            else 
            {
                ans.push_back(max(suffixMax[i],prefixMax[i+k-1]));
            }
        }
        return ans;
    }
};