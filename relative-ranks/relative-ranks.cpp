class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> copy(score.size(),0);
        vector<string> ans;
        int n = score.size();
        for(int i = 0;i<n;i++)
        {
            copy[i] = score[i];
        }
        sort(copy.begin(),copy.end());
        map<int,int> mp;
        for(int i = 0;i<n;i++)
        {
            mp[score[i]] = 1e9;
        }
        
        for(int i = n-1;i>=0;i--)
        {
            mp[copy[i]] = n-i;
        }
        
        for(int i = 0;i<n;i++)
        {
            if(mp[score[i]] == 1)
            {
                ans.push_back("Gold Medal");
            }
            if(mp[score[i]] == 2)
            {
                ans.push_back("Silver Medal");
            }
            if(mp[score[i]] == 3)
            {
                ans.push_back("Bronze Medal");
            }
            else if(mp[score[i]]>3)
            {
                ans.push_back(to_string(mp[score[i]]));
            }
        }
        return ans;
    }
};