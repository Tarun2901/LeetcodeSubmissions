class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int it = 1;
        vector<vector<int>> matrix(n,vector<int>(n));
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
                    matrix[srow][i] = it++;
                }
                srow++;
        
           
                for(int i = srow;i<=erow;i++)
                {
                    matrix[i][ecol] = it++;
                }
                ecol--;
           
             if(erow>=srow)
               {
                for(int i = ecol;i>=scol;i--)
                {
                    matrix[erow][i] = it++;
                }
               }
             erow--;
            if(ecol>=scol)
            {
                for(int i = erow;i>=srow;i--)
                {
                   matrix[i][scol] = it++;
                }
              
            }
              scol++;
        }
        return matrix;
    }
};