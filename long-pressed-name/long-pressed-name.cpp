class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 1;
        int j = 1;
        if(name.size() > typed.size())
        {
            return false;
        }
        int n = name.size();
        int m = typed.size();
        if(name[0]!=typed[0])
        {
            return 0;
        }
        
        while(i<n && j<m)
        {
            if(name[i] == typed[j])
            {
                i++;
                j++;
            }
            else
            {
                if(name[i-1] == typed[j])
                {
                    j++;
                }
                else
                {
                    return false;
                }
            }
        }
        //leftover in j
        
        while(j<m)
        {
            if(name[i-1]!=typed[j])
            {
                return false;
            }
            j++;
        }
        if(i<n)
        {
            return false;
        }
        return true;
    }
};