class Solution {
public:
    int numberOfSubstrings(string s) {
        int count = 0;
        map<char,int> mp;
        int i = 0;
        int k = 0;
        int j = 0;
        mp[s[0]]++;
        
        while(j<s.size())
        {   
            j++; 
            mp[s[j]]++;
                
        
            if(mp.size()==3)
            {
                while(mp.size() == 3)
                {   
                    count+= s.size() - j;
                    if(mp[s[i]]==1)
                    {
                        mp.erase(s[i]);
                        i++;
                        break;
                    }
                    else
                    {
                        mp[s[i]]--;
                    }
                    i++;
                }
            }
          
        }
        return count;
    }
};