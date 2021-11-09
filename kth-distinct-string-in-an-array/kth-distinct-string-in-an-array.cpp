class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        
        vector<string>distinct;
        unordered_map<string,int> mp;
        int count = 0;
        
        for(string str: arr)
        {
            mp[str]++;
        }
        for(int i = 0;i<arr.size();i++)
        {
            if(mp[arr[i]] == 1)
            {
                count++;
            }
            if(count == k)
            {
                return arr[i];
            }
        }
     
        return "";
    }
};