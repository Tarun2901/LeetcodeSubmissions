class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>positive;
        vector<int>negative;
        
        for(int val:nums)
        {
            if(val>0)
            {
                positive.push_back(val);
            }
            else
            {
                negative.push_back(val);
            }
        }
        
        vector<int>ans;
        for(int i = 0;i<positive.size();i++)
        {
            ans.push_back(positive[i]);
            ans.push_back(negative[i]);
        }
        
        return ans;
    }
};