class Solution {
public:
    bool isVowelSubstring(string& word)
    {
        map<char,int> mp;
        for(char ch:word)
        {
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                mp[ch]++;
            }
            else 
            {
                return false;
            }
        }
        if(mp.size() == 5)
        {
            return true;
        }
        return false;
    }
    int countVowelSubstrings(string word) {
        int count = 0;
        int n = word.size();
       
        for(int i = 0;i<n;i++)
        {   string s = "";
            s+= word[i];
            for(int j = i+1;j<n;j++)
            {
                s+=word[j];
                if(isVowelSubstring(s) == true)
                {
                    count++;
                }
            }
        }
        return count;
    }
};