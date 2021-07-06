class Solution {
public:
    string getHint(string secret, string guess) {
        //Frequency ka map.
        map<char,int> mp;
        int bulls = 0;
        int cows = 0;
        
        for(int i = 0;i<secret.size();i++)
        {   if(secret[i]!=guess[i])
            { mp[secret[i]]++;
            }
        }
        
        for(int i = 0;i<guess.size();i++)
        {
            if(secret[i] == guess[i])
            {
                bulls++;
            }
            else if(mp[guess[i]]>0)
            {
                cows++;
                mp[guess[i]]--;
            }
        }
        
        string ans = to_string(bulls)+ "A" + to_string(cows) + "B";
        return ans;
    }
};