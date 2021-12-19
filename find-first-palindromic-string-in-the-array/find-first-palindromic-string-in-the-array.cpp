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
    string firstPalindrome(vector<string>& words) {
        for(string s:words)
        {
            if(isValid(s))
            {
                return s;
            }
        }
        return "";
    }
};