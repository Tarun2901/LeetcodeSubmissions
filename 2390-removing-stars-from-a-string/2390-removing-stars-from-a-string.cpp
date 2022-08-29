class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for(char ch:s)
        {
            if(ch == '*')
            {
                st.pop();
            }
            else
            {
                st.push(ch);
            }
        }
       int i = st.size()-1;
        string ans(st.size(), '*');
        while(!st.empty()){
            ans[i--] = st.top();
            st.pop();
        }
        return ans;
    }
};