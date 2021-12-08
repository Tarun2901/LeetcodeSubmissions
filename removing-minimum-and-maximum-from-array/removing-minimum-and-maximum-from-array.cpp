class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mx = INT_MIN;
        int mn = INT_MAX;
        int posmx = -1;
        int posmin = -1;
        int n = nums.size();
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i]>mx)
            {
                mx = nums[i];
                posmx = i;
            }
            if (nums[i]<mn)
            {
                mn = nums[i];
                posmin = i;
            }
        }
        
        int option1 = min(posmx+1,n-posmx) + min(posmin+1,n-posmin);
        int option2 =  max(posmx+1,posmin+1);
        int option3 = max(n-posmx,n-posmin);
        return min(option1,min(option2,option3));
    }
};