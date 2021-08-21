class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int n = s.size();
        int count = 0;
        
        for(int i = 0;i<n;i++)
        {
            char ch = s[i];
            
            if(ch == '(')
            {
                st.push(ch);
                count++;
            }
            else if(ch == ')' && st.size() == 0)
            {
                st.push(ch);
                count++;
            }
            else if(ch == ')' && st.size()>0 && st.top()!='(')
            {
                st.push(ch);
                count++;
            }
            else if(ch == ')' && st.size()>0 && st.top() == '(')
            {
                st.pop();
                count--;
            }
          

        }
        return count;
    }
};