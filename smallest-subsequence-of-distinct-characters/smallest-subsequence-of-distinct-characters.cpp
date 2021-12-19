class Solution {
public:
    string smallestSubsequence(string s) {
          unordered_map<char,int> lastIndex;
        unordered_map<char,bool> inserted;
        stack<char> st;
        for(int i = 0;i<s.size();i++)
        {
            char ch = s[i];
            lastIndex[ch] = i;
        }
        for(auto p:lastIndex)
        {
            cout<<p.first<<" "<<p.second<<endl;
        }
        for(int i = 0;i<s.size();i++)
        {      char ch = s[i];
               if(lastIndex[ch] == i && inserted[ch] == false)
               {
                   
                   while(st.size()>0 && st.top()>ch && lastIndex[st.top()]>lastIndex[ch])
                  {   char ch1 = st.top();
                      inserted[ch1] = false;
                      st.pop();
                        cout<<"Popped :"<<ch1<<endl;
                  }
                   cout<<"Pushing : "<<ch<<endl;
                   st.push(ch);
                   inserted[ch] = true;
               }
              else if(lastIndex[ch]!=i && inserted[ch] == false)
              {
                  while(st.size()>0 && st.top()>ch && lastIndex[st.top()]>i)
                  {   char ch1 = st.top();
                      inserted[ch1] = false;
                      st.pop();
                      cout<<"Popped :"<<ch1<<endl;
                  }
                  cout<<"Pushing : "<<ch<<endl;
                  st.push(ch);
                  inserted[ch] = true;
              }
        }
        string ans = "";
        while(st.size()>0)
        {
            ans = st.top()+ans;
            st.pop();
        }
        return ans;
    }
};