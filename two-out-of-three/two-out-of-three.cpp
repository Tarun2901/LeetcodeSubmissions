class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        map<int,bool> mp1;
        map<int,bool> mp2;
        map<int,bool> mp3;
        for(int i = 0;i<nums1.size();i++)
        {
            mp1[nums1[i]] = true;
        }
        for(int i = 0;i<nums2.size();i++)
        {
            mp2[nums2[i]] = true;
        }
        for(int i = 0;i<nums3.size();i++)
        {
            mp3[nums3[i]] = true;
        }
        map<int,int> countOccurence;
        for(auto p:mp1)
        {
            countOccurence[p.first]++;
        }
         for(auto p:mp2)
        {
            countOccurence[p.first]++;
        }
         for(auto p:mp3)
        {
            countOccurence[p.first]++;
        }
        vector<int> ans;
        for(auto p:countOccurence)
        {
            if(p.second>1)
            {
                ans.push_back(p.first);
            }
        }
        
        return ans;
    }
};