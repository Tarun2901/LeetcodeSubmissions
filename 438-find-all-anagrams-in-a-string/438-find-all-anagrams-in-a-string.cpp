class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int wsize = p.size();
        if(wsize > s.size())
        {
            return {};
        }
        vector<int> freqp(26,0);
        vector<int> freqs(26,0);
        vector<int> res;
        int k = 0;
        int j = 0;
        for(int i = 0;i<wsize;i++)
        {
            freqp[p[i] - 'a']++;
        }
        
        for(int i = 0;i<wsize;i++)
        {
            freqs[s[i]-'a']++;
            j++;
        }
        if(freqs == freqp)
        {
            res.push_back(k);
        }
        
        while(j<s.size())
        {
            freqs[s[k]-'a']--;
            k++;
            freqs[s[j]-'a']++;
            j++;
            
            if(freqs == freqp)
            {
                res.push_back(k);
            }
        }
        
        return res;
    }
};