class Solution {
public:
    
    
    int countKAtMost(vector<int>& arr,int k)
    {
        int count = 0;
        int i = 0;
        int j = 0;
        unordered_map<int,int> mp;

        while(j<arr.size())
        {
            mp[arr[j]]++;
            j++;
            
            while(mp.size()>k)
                {
                    if(mp[arr[i]]>1)
                    {
                        mp[arr[i]]--;
                    }
                    else if(mp[arr[i]] == 1)
                    {
                        mp.erase(arr[i]);
                    }
                    i++;
                }  
            count+= j-i+1;
        }
        
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return countKAtMost(nums,k) - countKAtMost(nums,k-1);
    }
};