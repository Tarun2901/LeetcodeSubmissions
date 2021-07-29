class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        vector<int> solve[mat.size() + mat[0].size()-1];
        int row = mat.size() - 1;
        int col = mat[0].size() -1;
        
        
        for(int i = 0;i<=row;i++)
        {
            for(int j = 0;j<=col;j++)
            {
                solve[j-i+row].push_back(mat[i][j]);
            }
        }
        
        for(int i = 0;i<=row+col;i++)
        {
            sort(solve[i].begin(),solve[i].end());
        }
        for(int i:solve[1])
        {
            cout<<i<<" ";
        }
       
        for(int i = row;i>=0;i--)
        {
            for(int j = col;j>=0;j--)
            {
                mat[i][j] = solve[j-i+row].back();
                solve[j-i+row].pop_back();
            }
        }
        return mat;
    }
};