class Solution {
public:
    bool solve(int idx, vector<int>& arr,int n)
    {
        if(idx>=n || idx<0 || arr[idx] == -1)
        {
            return false;
        }
     

        bool ans = false;
        if ((idx>=0 && idx<=n-1) && arr[idx] == 0)
        {
            return true;
        }   
        int a = arr[idx];
        arr[idx] = -1;
        ans = ans||solve(idx+a,arr,n);
        ans = ans||solve(idx-a,arr,n);
        return ans;
    }
    bool canReach(vector<int>& arr, int start) {
         int n = arr.size();
        return solve(start,arr,n);
    }
};