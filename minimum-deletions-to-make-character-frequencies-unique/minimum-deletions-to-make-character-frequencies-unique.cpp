class Solution {
public:
    int minDeletions(string s) {
        int n = s.size();
        priority_queue<pair<int,char>,vector<pair<int,char>>,greater<pair<int,char>>> pq;
        map<char,int> mp;
        map<int,int> trace;
        
        for(char ch:s)
        {
            mp[ch]++;
        }
        
        for(auto p:mp)
        {
            pq.push(make_pair(p.second,p.first));
        }
        
        int count = 0;
        while(pq.size()>0)
        {
            int a = pq.top().first;
            pq.pop();
            if(trace[a] == 0)
            {
                trace[a]++;
                continue;
            }
            if(trace[a] > 0)
            {
                int og = a;
                while(trace[a]!=0)
                {
                    a--;
                    count++;
                }
                if(a!=0)
                {
                    trace[a]++;
                }
            }
        }
        return count;
    }
};