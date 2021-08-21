class Solution {
public:
    int countSubstrings(string s, string t) {
        int n=s.size();
        int m=t.size();
        int ans=0;
        for(int i=1;i<=n;i++){
            int j=0;
            for(j=0;j+i<=n;j++){
                string sub=s.substr(j,i);
                if(i<=m){
                    for(int k=0;k+i<=m;k++){
                        int count=0;
                        for(int a=k;a<k+i;a++){
                            if(t[a]!=sub[a-k]){
                                count++;
                            }
                        }
                        if(count==1){
                            ans++;
                        }
                    }   
                }
            }
        }
        return ans;
    }
};