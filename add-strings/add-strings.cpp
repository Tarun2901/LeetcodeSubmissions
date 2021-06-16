class Solution {
public:
    string addStrings(string num1, string num2) {
            string res = "";
            int i = num1.size()-1;
            int j = num2.size()-1;
        
        int carry = 0;
        
        while(i>=0 || j>=0 || carry != 0)
        {
            int dig1 = i>=0?num1[i] - '0':0;
            int dig2 = j>=0?num2[j] - '0':0;
            int sum = dig1+dig2+carry;
            int val = sum%10;
            carry = sum/10;
            res = to_string(val)+res;
            i--;
            j--;
        }
        return res;
    }
};