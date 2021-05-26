class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> mp;
        for(vector<int> edge:edges)
        {
            mp[edge[0]]++;
            mp[edge[1]]++;
        }
        for(auto p:mp)
        {
            if(p.second>1)
            {
                return p.first;
            }
        }
        return 0;
    }
};