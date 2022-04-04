class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans;
        
        vector<int> zeroes;
        vector<int> one;
        
        map<int,int> inDegree;
        map<int,int> oDegree;
        map<int,bool> los;
        map<int,bool> wi;
        for(auto v:matches)
        {
            int loss = v[1];
            int win = v[0];
            inDegree[loss]++;
            oDegree[win]++;
        }
        
        for(auto v:matches)
        {
            int loss = v[1];
            int win = v[0];
            if(inDegree[loss] == 1 && los[loss] == false)
            {
                one.push_back(loss);
                los[loss] = true;
            }
            if(inDegree[win] == 0 && oDegree[win]>0 && wi[win] == false)
            {
                zeroes.push_back(win);
                wi[win] = true;
            }
        }
        
        sort(one.begin(),one.end());
        sort(zeroes.begin(),zeroes.end());
        
        ans.push_back(zeroes);
        ans.push_back(one);
        return ans;
    }
};