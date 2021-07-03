class Solution {
public:
    
        int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans=0;
        int n=nums.size();
        int i=0;
        int prod=1;
        for(int j=0;j<n;j++){
            prod*=nums[j];
            if(prod>=k){
                while(prod>=k&&i<j){
                    prod/=nums[i];
                    i++;
                }
                if(prod<k){
                    ans+=(j-i+1);
                }
            }
            else{
                ans+=(j-i+1);
            }
        }
        return ans;
        
    }
};