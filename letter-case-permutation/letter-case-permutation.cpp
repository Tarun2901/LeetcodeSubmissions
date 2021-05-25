class Solution {
public: 
    vector<string> ans;
    void solve(string curr,string s, int i){
        // if end of the string is reached
        if(i==s.size()){
            ans.push_back(curr); 
            return;
        }
        
        if(isdigit(s[i])){ 
            curr.push_back(s[i]);
            solve(curr,s,i+1);
        }
        else{ 
            string c1=curr;
            c1.push_back(tolower(s[i]));
            solve(c1,s,i+1);
           
            string c2=curr;
            c2.push_back(toupper(s[i]));
            solve(c2,s,i+1);
        }
    }
    vector<string> letterCasePermutation(string s) {
             int idx = 0;
            string curr = "";
            solve(curr,s,0);
            return ans;
    }
};