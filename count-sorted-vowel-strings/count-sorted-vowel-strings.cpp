class Solution {
public:
    int count = 0;
    void solve(int idx,int n,string& str,int prev)
    {
        if(idx == n)
        {
            count++;
            return;
        }
        
        for(int i = prev;i<str.size();i++)
        {
            solve(idx+1,n,str,i);
        }
        return;
    }
    int countVowelStrings(int n) {
        string str = "aeiou";
        
        solve(0,n,str,0);
        
        return count;
    }
};