class Solution {
public:
    
    //The idea to solve this question is to take the transpose of the matrix and then columnwise replace the elements of the matrix.
    /*
    1 2 3
    4 5 6
    7 8 9
    
    After transpose 
    
    1 4 7                                                       7 4 1
    2 5 8  --> Keep col1 at 0 and col2 at no of cols -1 ---->   8 5 2
    3 6 9        Swap the elements in the two columns           9 6 3
                  while col1<col2
    */
    
    
    
    void rotate(vector<vector<int>>& matrix) {
            //Transpose the given matrix
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        for(int i = 0;i<row;i++)
        {
            for(int j = i+1;j<col;j++)
            {   
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        

        int col1 = 0;
        int col2 = col-1;
        
        while(col1<col2)
        {
             for(int i = 0;i<row;i++) 
             {
                 int temp = matrix[i][col1];
                 matrix[i][col1] = matrix[i][col2];
                 matrix[i][col2] = temp;
             }
            col1++;
            col2--;
        }
    }
};