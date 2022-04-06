class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;
        vector<int> one;
        vector<int> two;
        
        unordered_map<int,bool> mp1;
        unordered_map<int,bool> mp2;
        
        for(int val:nums1)
        {
            mp1[val] = true;
        }
        for(int val:nums2)
        {
            mp2[val] = true;
        }
        
        for(int val:nums1)
        {
            if(mp2[val] == false && mp1[val] == true)
            {
                one.push_back(val);
                mp1[val] = false;
            }
        }
        for(int val:nums2)
        {
            if(mp1[val] == false && mp2[val] == true)
            {
                two.push_back(val);
                mp2[val] = false;
            }
        }
        
        ans.push_back(one);
        ans.push_back(two);
        return ans;

    }
};