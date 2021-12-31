class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        int prevLen = 0;
    
        for(char ch:s)
        {
            if(ch == ' ')
            {
                if(len!=0)
                    prevLen= len;
                len = 0;
            }
            else
            {
                len++;
            }
        }
        if(len>0)
        {
            return len;
        }
        return prevLen;
    }
};