class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        sort(strs.begin(),strs.end());
        string it = strs[0];
        string end = strs[strs.size()-1];
        for(int i = 0;i<it.size();i++)
        {
            if(it[i] == end[i])
            {
                res+=it[i];
            }
            else
            {
                break;
            }
        }
        return res;
    }
};