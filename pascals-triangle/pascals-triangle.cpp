class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> arr;
        vector<int> res;
    for(int i = 0;i<=n-1;i++)
    {   
        int val = 1;
        
        res.push_back(val);
        for(int j = 0;j<i;j++)
        {
            val = val * (i-j)/(j+1);
            res.push_back(val);
        }
        arr.push_back(res);
        res.clear();
    }
        return arr;
    }
};