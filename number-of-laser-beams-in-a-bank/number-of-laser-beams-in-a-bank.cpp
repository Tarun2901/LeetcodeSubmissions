class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
       int prevRow = 0;
       int count = 0;
        for(string s:bank)
        {  int rem = prevRow;
            int cr = 0;
            for(char ch:s)
            {   
               if(ch == '1')
                {
                   cr++; 
                }     
            }
            if(cr == 0)
            {
                count+= cr*rem;
            }
            else
            {
                count+=cr*rem;
                prevRow = cr;
            }
         }
        
    
        return count;
    }
};