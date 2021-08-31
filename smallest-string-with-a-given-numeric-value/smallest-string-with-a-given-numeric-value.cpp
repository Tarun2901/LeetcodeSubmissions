class Solution {
public: 
  
    string getSmallestString(int n, int k) {
        string ans="";
        while(n){
            if(k-(n-1)<=26){
                ans+=('a'+k-(n-1)-1);
                n--;
                int t=n;
                for(int i=1;i<=t;i++){
                    ans.push_back('a');
                    n--;
                }
            }
            else{
                ans.push_back('z');
                n--;
                k-=26;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};