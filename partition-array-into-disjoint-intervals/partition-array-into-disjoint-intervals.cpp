class Solution {
public:
    /*  
    
    [5,0,3,8,6]
    
    */
    int partitionDisjoint(vector<int>& nums) {
        int n=nums.size();
        int ele=nums[0];
        int left=0;
        int ma=ele;
        for(int i=1;i<n;i++){
            if(nums[i]<ele){
                left=i;
                ele=ma;
            }
            ma=max(ma, nums[i]);
        }
        return left+1;
    }
};