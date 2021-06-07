class Solution {
    public int maxArea(int[] height) {
        int i = 0;
        int j = height.length - 1;
        int max = -(int)1e9;
        int area = 0;
        while(i<j)
        {
            int width = j-i;
            int ht = Math.min(height[i],height[j]);
            area = width*ht;
            max = Math.max(max,area);
            if(height[i]<height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return max;
    }
}