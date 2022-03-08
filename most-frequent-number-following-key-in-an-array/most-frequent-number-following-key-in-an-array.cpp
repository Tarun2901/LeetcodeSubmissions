class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        
        int maxFreq = INT_MIN;
        int maxFreqTar = -1;
        int n = nums.size();
        map<int,int> mp;
        for(int i = 0;i<n-1;i++)
        {
            int curr = nums[i];
            int next = nums[i+1];
            if(curr == key)
            {
                mp[next]+=1;
            }
        }
        
        for(auto p:mp)
        {
            int target = p.first;
            int freq = p.second;
            if(freq>maxFreq)
            {
                maxFreq = freq;
                maxFreqTar = target;
            }
        }
        
        return maxFreqTar;
    }
};