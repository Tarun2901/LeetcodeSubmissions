class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
            unordered_map<int,int> fetchIdx;
            for(int i = 0;i<nums.size();i++)
            {
                fetchIdx[nums[i]] = i;
            }
        
            for(int i = 0;i<operations.size();i++)
            {
                int val = operations[i][0];
                int newVal = operations[i][1];
                int idx = fetchIdx[val];
                nums[idx] = newVal;
                fetchIdx[newVal] = idx;
            }
        
           return nums;
    }
};