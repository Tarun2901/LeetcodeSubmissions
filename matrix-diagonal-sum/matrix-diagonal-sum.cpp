class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat.size();
        
        int ans = 0;
        for(int i = 0;i<row;i++)
        {
            for(int j = 0;j<col;j++)
            {
                if(i == j || i+j == row-1)
                {
                    ans+=mat[i][j];
                }
            }
        }
        return ans;
    }
};