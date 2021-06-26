class Solution {
public:
    
   
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i = 0;
        
        for(auto k:pushed)
        {
            while(st.size() && st.top() == popped[i])
            {
                st.pop();
                i++;
            }
            st.push(k);
        }
        while(st.size() && st.top() == popped[i])
        {
            st.pop();
            i++;
        }
        return st.size() == 0?true:false;
    }
};