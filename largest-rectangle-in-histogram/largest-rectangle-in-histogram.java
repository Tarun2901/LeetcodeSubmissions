class Solution {
    public int largestRectangleArea(int[] heights) {
        if(heights.length == 0)
        {
            return 0;
        }
        int l[] = new int[heights.length];
        int r[] = new int[heights.length];
        
        //Fill the nser array first
        Stack<Integer> st = new Stack<>();
        r[heights.length-1] = heights.length;
        st.push(heights.length-1);
        
        for(int i = heights.length -2; i>=0;i--)
        {
            while(st.size()>0 && heights[st.peek()] >= heights[i])
            {
                st.pop();
            }
            if(st.size() == 0)
            {
                r[i] = heights.length;
            }
            else
            {
                r[i] = st.peek(); //Need idx to calculate the width later
            }
            st.push(i);
        }
        
        //Fill nsel array
        
        st = new Stack<>();
        l[0] = -1;
        st.push(0);
        
        for(int i = 1;i<heights.length;i++)
        {
            while(st.size()>0 && heights[st.peek()] >= heights[i])
            {
                st.pop();
            }
            if(st.size() == 0)
            {
                l[i] = -1;
            }
            else
            {
                l[i] = st.peek(); //Need idx to calculate the width later
            }
            st.push(i);
        }
        for(int i = 0;i<heights.length;i++)
        { 
            System.out.println(l[i] + "," + r[i]);
            }
        //Now loop for maxArea
        int maxArea = 0;
        
        for(int i = 0;i<heights.length;i++)
        {
            int width = r[i] - l[i]-1;
            int area = heights[i] * width;
            if(area>maxArea)
            {
                maxArea = area;
            }
        }
        return maxArea;
    }
}