class Solution {
public:
    bool squareIsWhite(string s) {
        int i = (int)(s[0]-'a');
        int j = (int)(s[1]-'0');
        if(i%2 == 0)
        {
            if(j%2!=0)
            {
                return false;
            }
        }
        else if(i%2!=0)
        {
            if(j%2 == 0)
            {
                return false;
            }
        }
        
        return true;
    }
};