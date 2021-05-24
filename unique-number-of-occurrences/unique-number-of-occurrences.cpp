class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int prev = -1;
        unordered_map<int,int> mp;
        for(int i = 0;i<arr.size();i++)
        {
            mp[arr[i]]++;
        }
        unordered_map<int,int> mp1;
        for(auto p:mp)
        {
           mp1[p.second]++;
        }
        for(auto p1:mp1)
        {
            if(p1.second>1)
            {
                return false;
            }
        }
        return true;
    }
};