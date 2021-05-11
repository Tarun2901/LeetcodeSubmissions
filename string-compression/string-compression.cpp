class Solution {
public:
    int compress(vector<char>& chars) {
       if(chars.size()==0)
            return 0;
        int count=1;
        int length=1;
        char prev=chars[0];
        for(int i=1;i<chars.size();i++)
        {
            if(chars[i]==prev)
            {
                count++;
                
            }
            else
            {
                if(count>1)
                {
                    string p=to_string(count);
                    for(int j=0;j<p.length();j++)
                    {
                        length++;
                        chars[length-1]=p[j];
                    }
                }
                length++;
                chars[length-1]=chars[i];
                prev=chars[i];
                count=1;
            }
        }
        
       if(count>1)
        {
            string p=to_string(count);
            for(int j=0;j<p.length();j++)
             {
                     length++;
                     chars[length-1]=p[j];
             }
      }
      return length;
    }
};