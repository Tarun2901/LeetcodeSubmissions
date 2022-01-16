class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        string curr = "";
        for(int i = 0;i<s.size();i++)
        {
            if(curr.size()<k)
            {
                curr+=s[i];
            }
            else
            {
                ans.push_back(curr);
                curr = s[i];
            }
        }
        if(curr.size()<k)
        {
            while(curr.size()<k)
            {
                curr.push_back(fill);
            }
        }
        ans.push_back(curr);
        return ans;
    }
};