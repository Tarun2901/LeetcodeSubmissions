class Solution {
    
    public String removeOccurrences(String s, String part) {
        int index = s.indexOf(part);
        int len = part.length();
    
        while(index!=-1)
        {
            int slen = s.length();
            index = s.indexOf(part);
            if(index != -1)
            {
                s = s.substring(0,index) + s.substring(index+len);
            }
            
        }
        
        return s;
    }
}