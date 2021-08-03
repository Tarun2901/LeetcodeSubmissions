class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k>=2)
        {
            sort(s.begin(),s.end());
            return s;
        }
        
        string copy = s;
        string ans = s;
        char ch1 = s[0];
        string temp = s.substr(1,s.length()-1);
        temp = temp+ch1;
        ans = min(ans,temp);
        
        while(temp!=copy)
        {
            ch1 = temp[0];
            string str = temp.substr(1,temp.size()-1);
            str = str + ch1;
            ans = min(ans,str);
            temp = str;
        }
        
        return ans;
    }
};