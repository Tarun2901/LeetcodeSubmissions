class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i = 0;
        int j = nums.size() -1;
        int omax = INT_MIN;
        
        while(i<j)
        {
            int sum = nums[i]+nums[j];
            omax = max(omax,sum);
            i++;
            j--;
        }
        return omax;
    }
};