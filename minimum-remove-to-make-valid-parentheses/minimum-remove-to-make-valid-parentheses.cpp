class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n= s.size();
        
        stack<pair<char,int>> st;
        unordered_map<int,int> blocked;
        for(int i = 0;i<n;i++)
        {
            char ch = s[i];
            
            if(ch == '(')
            {
                st.push(make_pair(ch,i));
            }
            else if(ch == ')' && st.size() == 0)
            {
                st.push(make_pair(ch,i));
            }
            else if(ch == ')' && st.top().first == '(')
            {
                st.pop();
            }
            else if(ch == ')' && st.top().first != '(')
            {
                st.push(make_pair(ch,i));
            }
        }
        
        while(st.size()>0)
        {
            int pos = st.top().second;
            blocked[pos] = 1;
            st.pop();
        }
        string ans = "";
        for(int i = 0;i<n;i++)
        {
            if(blocked[i] > 0)
            {
                continue;
            }
            else
            {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};