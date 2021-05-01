int dp[2002][2002];
class Solution {
public:
    
    bool isPalindrome(string &str, int i,int j)
    {
     while(i < j)
       {
           if(str[i] != str[j])
           {
               return false;
           }
           i++;
           j--;
       }
       return true;
    }
    int solve(string str,int i,int j)
    {
        //Base Case
       if(dp[i][j]!= -1)return dp[i][j];
        else if(i==j ||isPalindrome(str,i,j))
        {
            dp[i][j] = 0;
            return 0;
        }
        int mn = INT_MAX;
        for(int k = i;k<=j-1;k++)
        {   int right = 0;
            if(isPalindrome(str,i,k))
            right = solve(str,k+1,j);
            else
            {
                dp[i][k] = 0;
                continue;
            }
            int count = 1+right;
            if(count < mn)
            {
                mn = count;
            }
        }
        return dp[i][j] = mn;
    }
    int minCut(string str) {
        memset(dp,-1,sizeof dp);
        int n = str.size();
        return solve(str,0,n-1);
    }
};