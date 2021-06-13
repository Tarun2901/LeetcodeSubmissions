class Solution {
public:
    
    
    vector<vector<int>> res;
    
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    
        map<int,vector<int>> mp;
        
        
        for(int i = 0;i<groupSizes.size();i++)
        {
            mp[groupSizes[i]].push_back(i);
        }
        
        for(auto p:mp)
        {
            int k = p.second.size(); //this will be 6 for 3
            int counter = 0;
            int nuofgroups = k/p.first;
            for(int i = 0;i<nuofgroups;i++)
            {  vector<int> ans;
               for(int i = 0;i<p.first;i++)
               {
                   ans.push_back(p.second[counter++]);
               }
                res.push_back(ans);
            }
        }
        return res;
    }
};