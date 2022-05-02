class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        unordered_map<string,bool> mp;
        
        int count = 0;
        string str = "";
        for(char ch:s)
        {
            str+=ch;
            mp[str] = true;
        }
        for(string s:words)
        {
            if(mp[s] == true)
            {
                count++;
            }
        }
        return count;
    }
};