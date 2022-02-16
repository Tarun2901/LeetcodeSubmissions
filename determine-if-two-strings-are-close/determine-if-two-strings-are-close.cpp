class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int>arr1(26,0);
        vector<int>arr2(26,0);
        bool b1 = false;
        bool b2 = false;
        for(char ch:word1)
        {
            int idx = ch-'a';
            arr1[idx]++;
        }
        for(char ch:word2)
        {
            int idx = ch-'a';
            arr2[idx]++;
            if(arr1[idx] == 0)
            {
                return false;
            }
        }
        if(arr1 == arr2)
        {
            b1 = true;
        }
        vector<int>arr;
        vector<int>vec;
        for(int k:arr1)
        {
            arr.push_back(k);
        }
        for(int k:arr2)
        {
            vec.push_back(k);
        }
        sort(arr.begin(),arr.end());
        sort(vec.begin(),vec.end());
        
        if(arr == vec)
        {
            b2 = true;
        }
     
        return b1||b2;
    }
};