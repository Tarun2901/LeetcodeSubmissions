class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string *arr =  new string[26] {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        map<string,int> mp;
        
        for(string s:words)
        {   string str = "";
            for(char ch:s)
            {
                int i = ch-'a';
                str+=arr[i];
            }
            mp[str]++;
        }
        return mp.size();
    }
};