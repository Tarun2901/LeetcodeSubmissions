class Solution {
public:
    string reverseVowels(string s) {
        
        string vowel = "";
        
        
        for(char ch: s)
        {
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch =='U')
            {
                vowel+= ch;
            }
        }
        int i = 0;
        int j = vowel.size()-1;
        while(i<j)
        {
            char ch = vowel[i];
            vowel[i] = vowel[j];
            vowel[j] = ch;
            i++;
            j--;
        }
        
        int ctr = 0;
        
        for(int i = 0;i<s.size();i++)
        {   char ch = s[i];
             if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            {
                s[i] = vowel[ctr];
                 ctr++;
            }
        }
        return s;
    }
};