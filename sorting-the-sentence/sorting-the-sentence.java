class Solution {
    public String sortSentence(String s) {
        String[] splitted = s.split("\\s+");
        String[] sort = new String[splitted.length];
        for(String str:splitted)
        {
            int pos = str.charAt(str.length()-1) - '0';
            sort[pos-1] = str.substring(0,str.length()-1);
        }
        String joined = String.join(" ",sort);
        return joined;
        
    }
}