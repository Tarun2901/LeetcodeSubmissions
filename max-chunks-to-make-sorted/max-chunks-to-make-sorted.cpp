class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int runningMax = INT_MIN;
        int count = 0;
        for(int i = 0;i<arr.size();i++)
        {
            runningMax = max(arr[i],runningMax);
            if(runningMax == i)
            {
                count++;
            }
        }
        
        return count;
    }
};