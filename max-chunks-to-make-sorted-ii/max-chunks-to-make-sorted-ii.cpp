class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int count = 0;
        int lmax = INT_MIN;
        vector<int> rmin(n+1,INT_MAX);
        int rmi = INT_MAX;
        for(int i = n-1;i>=0;i--)
        {   rmi = min(rmi,arr[i]);
            rmin[i] = rmi;
        }
        
        for(int i = 0;i<n;i++)
        {
            //generate lmax simultaneously
            lmax = max(lmax,arr[i]);
            //check the condition for a potential partition point 
            if(lmax<=rmin[i+1])
            {
                count++;
            }
        }
        
        return count;
    }
};