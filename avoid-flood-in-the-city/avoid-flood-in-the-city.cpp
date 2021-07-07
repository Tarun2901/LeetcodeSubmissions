class Solution {
public:
    
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> ans;
        unordered_map<int,int> mp;
        unordered_map<int,int> status;
        unordered_map<int,int> lastRain;
        for(int i = 0;i<rains.size();i++)
        {
            if(rains[i]>0)
            {
              mp[rains[i]]++;
              lastRain[rains[i]] = i;
            }
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
               
        for(int i = 0;i<rains.size();i++)
        {
            if(rains[i]>0 && status[rains[i]] == 0)
            {
                ans.push_back(-1);
                mp[rains[i]]--;
                status[rains[i]] = 1;
                if(mp[rains[i]]>0)
                {
                   pq.push(make_pair(lastRain[rains[i]],rains[i]));
                }
            }
            else if(rains[i]>0 && status[rains[i]] == 1)
            {
                return {};
            }
            else if(rains[i] == 0)
            {
                int maxEle = 0;
                while(pq.size()>0 && mp[pq.top().second]==0 && status[pq.top().second] == 1)
                {
                    pq.pop();
                }
                if(pq.size()>0)
                {
                    int idx = pq.top().first;
                    int ele = pq.top().second;
                    if(status[ele] == 1)
                    {
                        maxEle = ele;
                    }
                    pq.pop();
                }
                if(maxEle == 0)
                {
                    ans.push_back(1);
                }
                else 
                {   cout<<maxEle<<" ";
                    ans.push_back(maxEle);
                    status[maxEle] = 0;
                }
            }
        }
        
        return ans;
    }
};