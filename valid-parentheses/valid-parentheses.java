class Solution {
    public boolean isValid(String str) {
              Stack<Character> st = new Stack<>();
         for(int i = 0;i<str.length();i++)
         {
             char ch = str.charAt(i);
             if(ch == '(' || ch == '{' || ch == '[')
             {
                 st.push(ch);
             }
             else
             {
                 if(ch == '}')
                 {
                     if(st.isEmpty())
                     {
                          return false;
                     }
                     if(st.peek() == '{')
                     {
                         st.pop();
                     }
                     else
                     {
                         return false;
                     }
                 }
                 else if(ch == ']')
                 {
                     if(st.isEmpty())
                     {
                           return false;
                     }
                     if(st.peek() == '[')
                     {
                         st.pop();
                     }
                     else
                     {
                         return false;
                     }
                 }
                 else if(ch == ')')
                 {
                     if(st.isEmpty())
                     {
                           return false;
                     }
                     if(st.peek() == '(')
                     {
                         st.pop();
                     }
                     else
                     {
                            return false;
                     }
                 }
             }
         }
         if(st.isEmpty())
         {
              return true;
         }
         else
         {
              return false;
         }
    }
}