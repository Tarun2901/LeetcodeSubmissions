class Solution {
public:
    int trap(vector<int>& height) {
    int n = height.size();
    int water = 0;
        int i = 0,j = n-1, lmax = 0,rmax = 0;
     while(i<j)
     {
         lmax = max(lmax,height[i]);
         rmax = max(rmax,height[j]);
         if(lmax<=rmax)
         {
          water += lmax - height[i];
             i++;
         }
         else
         {
             water += rmax - height[j];
             j--;
         }
     }
        return water;
    }
};