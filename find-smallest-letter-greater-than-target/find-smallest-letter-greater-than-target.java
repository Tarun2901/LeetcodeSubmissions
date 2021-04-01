class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
          int i=0,min=0;
      while(i<letters.length){
        if(letters[i]>target){
          break;
        }else{
          i++;
        }
      }
      if(i==letters.length)
        return letters[0];
      return letters[i];

    }
}