class Solution {
public:
    void reverse(vector<int>& nums,int start,int end)
    {
            int i = start;
            int j = end;
            while(i<j)
            {
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k>n)
        {
            k = k%n;
        }
        
        int pos = n-k;
        reverse(nums,0,pos-1);
        reverse(nums,pos,n-1);
        reverse(nums,0,n-1);
    }
};