class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        
        unordered_map<int,int> mp;
        unordered_map<int,int> bot;
        for(int i = 0;i<n;i++)
        {
            mp[tops[i]]++;
            bot[bottoms[i]]++;
        }
        
        bool lb = false;
        int mn = 0;
        int ele = 0;
        int count1 = 0;
        int count2 = 0;
        for(auto p:mp)
        {
            int val = p.first;
            int count = p.second;
            
            if(bot[val] >= n-count)
            {
                lb = true;
                mn = min(count,bot[val]);
                ele = val;
                count1 = count;
                count2 = bot[val];
            }
        }
        if(lb == false)
        {
            return -1;
        }
        int swaps = 0;
        int val = ele;
        if(count1>=count2)
        {
            for(int i = 0;i<n;i++)
            {
                if(tops[i]!=val && bottoms[i] == val)
                {
                    swaps++;
                }
                if(tops[i] == val && bottoms[i] == val)
                {
                    continue;
                }
                if(tops[i]!=val && bottoms[i]!=val)
                {
                    return -1;
                }
            }
        }
        else if(count2>count1)
        {
            swaps = 0;
            for(int i = 0;i<n;i++)
            {
                if(tops[i] == val && bottoms[i] == val)
                {
                    continue;
                }
                if(bottoms[i]!=val && tops[i] == val)
                {
                    
                    swaps++;
                }
                
                if(tops[i]!=val && bottoms[i]!=val)
                {
                    return -1;
                }
            }
        }
        return swaps;
    }
};