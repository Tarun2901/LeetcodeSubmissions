class Solution {
    public int maxCoins(int[] nums) {
        int[] arr = new int[nums.length+2];
        arr[0] = 1;
        arr[arr.length-1] = 1;
        for(int i = 0;i<nums.length;i++)
        {
            arr[i+1] = nums[i];
        }
        return burst(arr,0,arr.length-1,new int[arr.length][arr.length]);
    }
    public int burst(int[] arr,int left,int right,int[][] dp)
    {
        if(left+1 == right)
        {
            return 0;
        }
        if(dp[left][right]!=0)
        {
            return dp[left][right];
        }
        int ans = 0;
        for(int i = left+1;i<right;i++)
        {
            int templeft = burst(arr,left,i,dp);
            int tempright = burst(arr,i,right,dp);
            ans = Math.max(ans,templeft+tempright+arr[i]*arr[right]*arr[left]);
        }
        return dp[left][right] = ans;
    }
}