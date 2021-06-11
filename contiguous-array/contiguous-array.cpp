class Solution {
public:
    int findMaxLength(vector<int>& arr) {
        int n = arr.size();
        int count0 = 0;
        int count1 = 0;
        unordered_map<int,int> mp;
        mp[0] = -1;
        int omax = 0;
        vector<int>diff(n,0);
        for(int i = 0;i<arr.size();i++)
        {
            if(arr[i] == 0)
            {
                count0++;
            }
            if(arr[i] == 1)
            {
                count1++;
            }
            diff[i] = count0-count1;
        }
        for(int i = 0;i<diff.size();i++)
        {
            if(mp.find(diff[i]) == mp.end())
            {
                mp[diff[i]] = i;
            }
            else
            {
                int j = mp[diff[i]];
                int len = i-j;
                omax = max(omax,len);
            }
        }
        return omax==INT_MIN?0:omax;
    }
};