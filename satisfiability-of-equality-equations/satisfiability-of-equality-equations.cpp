class Solution {
public:
    unordered_map<char,char> par;
    
    char find(char x)
    {
        if(x == par[x])
        {
            return x;
        }
        char temp = find(par[x]);
        par[x] = temp;
        return temp;
    }
    
    void unionfunc(char x, char y)
    {
        char lox = find(x);
        char loy = find(y);
        if(lox!=loy)
        {
            par[loy] = lox;
        }
    }
    bool equationsPossible(vector<string>& equations) {
      
        for(string s:equations)
        {
          
                par[s[0]] = s[0];
                par[s[3]] = s[3];

        }
        for(string s:equations)
        {
            if(s[1] == '=')
            {
                unionfunc(s[0],s[3]);
            }
        }
       for(string s:equations)
       {
           if(s[1] == '!')
           {
               if(find(s[3]) == find(s[0]))
               {
                   return false;
               }
           }
       }
      return true;
    }
};