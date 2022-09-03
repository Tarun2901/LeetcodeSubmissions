class Solution {
    public int strStr(String haystack, String needle) {
        StringBuilder sb = new StringBuilder(haystack);
        StringBuilder needler = new StringBuilder(needle);
        int i = 0;
        int j = needle.length();
        while(j<=haystack.length())
        {
            String temp = sb.substring(i,j);
            System.out.println(temp);
            if(temp.compareTo(needle)==0)
            {
                return i;
            }
            i++;
            j++;
        }
        return -1;
    }
}