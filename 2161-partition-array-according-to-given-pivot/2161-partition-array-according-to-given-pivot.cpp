class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
            vector<int>smaller;
            vector<int>equal;
            vector<int>greater;  
        for(int val:nums)
        {
            if(val<pivot)
            {
                smaller.push_back(val);
            }
            else if(val == pivot)
            {
                equal.push_back(val);
            }
            else
            {
                greater.push_back(val);
            }
        }
        
        smaller.insert(smaller.end(),equal.begin(),equal.end());
        smaller.insert(smaller.end(),greater.begin(),greater.end());
        return smaller;
    }
};