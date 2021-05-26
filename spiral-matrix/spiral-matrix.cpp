class Solution {
public:
    
    vector<int> ans;
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int srow = 0;
        int scol = 0;
        int erow = row-1;
        int ecol = col-1;
        
        while(srow<=erow && scol<=ecol)
        {
            
        
                for(int i = scol;i<=ecol;i++)
                {
                    ans.push_back(matrix[srow][i]);
                }
                srow++;
        
           
                for(int i = srow;i<=erow;i++)
                {
                    ans.push_back(matrix[i][ecol]);
                }
                ecol--;
           
             if(erow>=srow)
               {
                for(int i = ecol;i>=scol;i--)
                {
                    ans.push_back(matrix[erow][i]);
                }
               }
             erow--;
            if(ecol>=scol)
            {
                for(int i = erow;i>=srow;i--)
                {
                    ans.push_back(matrix[i][scol]);
                }
              
            }
              scol++;
        }
        return ans;
    }
};