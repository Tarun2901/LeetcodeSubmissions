class Solution {
public:
    bool checkIfPangram(string sentence) {
           map<char,int> mp;
        
        for(char ch: sentence)
        {
            mp[ch]++;
        }
        
        return mp.size() == 26;
    }
};