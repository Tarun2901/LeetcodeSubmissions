class Solution {
public:
    string frequencySort(string s) {
        map<char,int> mp;
        string ans = "";
        for(int i = 0;i<s.size();i++)
        {   char ch = s[i];
            mp[ch]++;
        }
        
        priority_queue<pair<int,char>> pq;
        
        for(auto p:mp)
        {
            pq.push(make_pair(p.second,p.first));
        }
        
        while(pq.size()>0)
        {
            int k = pq.top().first;
            char ch = pq.top().second;
            pq.pop();
            while(k-->0)
            {
                ans+= ch;
            }
        }
        
        return ans;
    }
};