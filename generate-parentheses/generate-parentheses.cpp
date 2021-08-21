class Solution {
public:
    vector<string> ans;
    
    void solve(int usedOpen,int usedClosed,string& str,int n)
    {
        if(usedOpen == n && usedClosed == n)
        {
            ans.push_back(str);
            return;
        }
        if(usedOpen<n)
        {   str+='(';
            solve(usedOpen+1,usedClosed,str,n);
            str.pop_back();
        }

        if(usedOpen>usedClosed)
        {
            str.push_back(')');
            solve(usedOpen,usedClosed+1,str,n);
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string str = "";
        int usedOpen = 0;
        int usedClosed = 0;
        
        solve(usedOpen,usedClosed,str,n);
        return ans;
    }
};