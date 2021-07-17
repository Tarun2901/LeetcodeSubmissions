class Solution {
public:
    
   
    // loot :      2 1
    // dpnoloot :  0 
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dploot(n,0);
        vector<int> dpnoloot(n,0);
        dploot[0] = nums[0];
        dpnoloot[0] = 0;
        
        for(int i = 1;i<n;i++)
        {
            dploot[i] = max(dploot[i-1]-nums[i-1] + nums[i],dpnoloot[i-1] + nums[i]);
            dpnoloot[i] = dploot[i-1];
        }
        
        return max(dploot[n-1],dpnoloot[n-1]);
    }
};