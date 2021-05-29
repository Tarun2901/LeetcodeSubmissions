class Solution {
public:
    bool checkZeroOnes(string s) {
        int len1 = 0;
        int len0 = 0;
        int max1 = 0;
        int max0 = 0;
        for(int i = 0;i<s.size();i++)
        {
            char ch = s[i];
            if(ch == '0')
            {
                len1 = 0;
                max0 = max(max0,++len0);
            }
            else if(ch == '1')
            {
                len0 = 0;
                max1 = max(max1,++len1);
            }
        }
        return max1>max0?true:false;
    }
};