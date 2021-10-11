class Solution {
public:
    int numOfPairs(vector<string>& arr, string target) {
        int count = 0;
        string str;
        string str1;
        for(int i = 0;i<arr.size();i++)
        {
            for(int j = i+1;j<arr.size();j++)
            {
                str = arr[i]+arr[j];
                str1 = arr[j] + arr[i];
                if(str == target)
                {
                    count++;
                }
                if(str1 == target)
                {
                    count++;
                }
            }
        }
        
        return count;
    }
};