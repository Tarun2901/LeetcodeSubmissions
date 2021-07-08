class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        string k = s;
        reverse(k.begin(),k.end());
        return k==s;
    }
};