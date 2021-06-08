class Solution {
public: 
    
       vector<string> keypad{" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
        vector<string> res;
    
    void helper(string digits,int idx,int size,string& ans)
    {
        if(idx == size)
        {
            res.push_back(ans);
            return;
        }
        //position/index of the current element in the keypad numerically
        int pos = digits[idx] - '0';
        for(char ch:keypad[pos])
        {   ans.push_back(ch);
            helper(digits,idx+1,size,ans);
            // pop back the character (Backtrack)
            ans.pop_back();
        }
        return;
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)
        {
            return res;
        }
        string ans = "";
        int n = digits.size();
        helper(digits,0,n,ans);
        return res;
    }
};