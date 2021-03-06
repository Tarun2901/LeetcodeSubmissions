class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        map<int,int> mp;
        vector<int>ans;
        for(int val:nums)
        {
            if(mp[val] == 0)
            {
                mp[val] = 1;
            }
            else
            {
                mp[val]++;
            }
        }
        for(auto p:mp)
        {
            int val = p.first;
            if(p.second == 1 && mp[val+1] == 0 && mp[val-1] == 0)
            {
                ans.push_back(val);
            }
        }
    return ans;
    }
};