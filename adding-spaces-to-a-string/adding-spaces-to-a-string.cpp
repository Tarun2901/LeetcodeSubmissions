class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int i = 0;
        int j = 0;
        string str = "";
        while(i<s.size())
        {
            if(j<spaces.size() && i == spaces[j])
            {
                str+=" ";
                str.push_back(s[i]);
                j++;
            }
            else
            {
                str.push_back(s[i]);
            }
            i++;
        }
        return str;
    }
};