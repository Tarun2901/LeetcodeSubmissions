class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        if(beans.size() == 1)
        {
            return 0;
        }
            
        sort(beans.begin(), beans.end());
        int n=beans.size();
        long long i=0,j=0;
        long long sum=0;
        vector<long long> dp(n+1,0);
        for(;j<n;j++){
            sum+=beans[j];
            dp[j]=sum;
        }
        long long ans=dp[n-2];
        sum=0;
        for(j=n-2;j>=1;j--){
            sum+=(beans[j+1]-beans[j])*(n-1-j);
            ans=min(ans, dp[j-1]+sum);
        }
        sum+=(beans[j+1]-beans[j])*(n-1-j);
        ans = min(ans,sum);
        return ans;
}
};
