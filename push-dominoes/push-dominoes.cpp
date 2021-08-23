class Solution {
public:
    string pushDominoes(string dominoes) {
        string temp = 'L' + dominoes + 'R';
        int i = 0;
        int j = 1;
        string ans = "";
        ans+= temp[0];
        while(i<temp.size())
        {
            int count = 0;
            while(j<temp.size() && temp[j] !='L' && temp[j]!='R')
            {
                j++;
                count++;
            }
            if(temp[i] == 'L' && temp[j] == 'R')
            {
                ans+= temp.substr(i+1,j-i);
            }
            if(temp[i] == 'L' && temp[j] == 'L')
            {
               
                for(int i = 0;i<count;i++)
                {
                    ans+='L';
                }
                ans+=temp[j];
            }
            
            if(temp[i] == 'R' && temp[j] == 'R')
            {
                for(int i = 0;i<count;i++)
                {
                    ans+= 'R';
                }
                ans+= temp[j];
            }
            if(temp[i] == 'R' && temp[j] == 'L')
            {
                if(count%2 == 0)
                {
                    for(int i = 0;i<count/2;i++)
                    {
                        ans+='R';
                    }
                    for(int i = 0;i<count/2;i++)
                    {
                        ans+= 'L';
                    }
                    ans+= temp[j];
                }
                else
                {
                    for(int i = 0;i<count/2;i++)
                    {
                        ans+='R';
                    }
                    ans+='.';
                    for(int i = 0;i<count/2;i++)
                    {
                        ans+= 'L';
                    }
                    ans+= temp[j];
                }
            }
            int temp = j+1;
            i = j;
            j = temp;
        }
        string res = "";
        for(int i = 1;i<ans.size()-1;i++)
        {
            res.push_back(ans[i]);
        }
        return res;
    }
};