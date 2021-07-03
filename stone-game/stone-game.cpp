class Solution {
public:
     int dp[501][501]={0};
    
    int solve(int start, int end, vector<int>& piles){
        if(start>end){
            return 0;
        }
        if(dp[start][end]!=0){
            return dp[start][end];
        }
        dp[start][end]= max(solve(start+1,end,piles)+piles[start],solve(start,end-1,piles)+piles[end]);
        return dp[start][end];
    }
    
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        int p1= solve(0,n-1,piles);
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=piles[i];
        }
        if(p1*2>sum){
            return true;
        }
        return false; 
    }
};