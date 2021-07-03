class Solution {
public:
        int singleNonDuplicate(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        int j=n-1;
        if(n==1){
            return nums[0];
        }
        while(i<=j){
            int mid=i+(j-i)/2;
            if(mid==0){
                if(nums[mid]!=nums[mid+1]){
                    return nums[mid];
                }
            }
            if(mid==n-1){
                if(nums[mid]!=nums[mid-1]){
                    return nums[mid];
                }
            }
            if(nums[mid]!=nums[mid-1]&&nums[mid]!=nums[mid+1]){
                return nums[mid];
            }
            if(nums[mid]==nums[mid+1]){
                if(mid%2==0){
                    i=mid+1;
                }
                else{
                    j=mid-1;
                }
            }
            else if(nums[mid]==nums[mid-1]){
                if(mid%2==0){
                    j=mid-1;
                }
                else{
                    i=mid+1;
                }
            }
        }
        return -1;
    }
};