class Solution {
    public int lengthOfLongestSubstring(String s) {
        if(s.length()<1)
        {
            return s.length();
        }
        int si = 0;
        int e = 0;
        int n = s.length();
        int count = 0;
        int len = -(int)1e9;
        int[] freq = new int[128];
        
        while(e<n)
        {
            if(freq[s.charAt(e)]>0)
            {
                count++;
            }
            freq[s.charAt(e)]++;
            e++;
            
            while(count>0)
            {
                if(freq[s.charAt(si)]>1)
                {
                    count--;
                }
                freq[s.charAt(si)]--;
                si++;
            }  
            len = Math.max(len,e-si);
        }
        return len;
    }
}