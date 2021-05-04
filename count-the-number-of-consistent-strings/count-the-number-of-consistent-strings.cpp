class Solution {
public: 
    int freq[26];
    int countConsistentStrings(string allowed, vector<string>& words) {
        for(char& ch:allowed)
        {
            int idx = ch - 'a';
            freq[idx]++;
        }
        
        int count = 0;
        for(string str:words)
        {   bool lb = true;
            for(char& ch:str)
            {
                int idx = ch-'a';
                if(freq[idx]>0)
                {
                    continue;
                }
                else
                {
                   lb = false;
                }
            }
            if(lb)
            {
            count++;
            }
        }
        return count;
    }
};