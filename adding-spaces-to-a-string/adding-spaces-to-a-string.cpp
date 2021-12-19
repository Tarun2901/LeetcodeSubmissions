class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int i = 0;
        int j = 0;
        string str = "";
        for(int i = 0;i<s.size();i++)
        {
            if(j<spaces.size() && i == spaces[j])
            {
                str+=" ";
                j++;
            }
            str.push_back(s[i]);
        }
        return str;
    }
};