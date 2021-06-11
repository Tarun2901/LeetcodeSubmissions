class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int n = arr.size();
        int j = -1;

        int omax = INT_MIN;
        int count = 0;
        for(int i = 0;i<n;i++)
        {
            if(arr[i] == 0)
            {
                count++;
            }

            while(count>k)
            {   j++;
                if(arr[j] == 0)
                {
                    count--;
                }
            }

            int len = i-j;
            omax = max(len,omax);
        }

        return omax;
    }
};