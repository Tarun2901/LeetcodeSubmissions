class Solution {
public:
    
    bool isValid(string s)
    {
        int i = 0;
        int j = s.size()-1;
        
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            j--;
            i++;
        }
        return true;
    }
    bool validPalindrome(string s) {
       
        int i = 0;
        int j = s.size()-1;
        
        while(i<j)
        {
            if(s[i] == s[j])
            {
                i++;
                j--;
            }
            else if(s[i]!=s[j])
            {   //Case 1: Skip(delete) jth character and check valid
                bool case1 = isValid(s.substr(i,j-i));
                //Case 2: Skip(delete) ith character and check valid
                bool case2 = isValid(s.substr(i+1,j-i));
                
                bool ans = case1||case2;
                return ans;
            }
        }
        return true;
        
    }
};