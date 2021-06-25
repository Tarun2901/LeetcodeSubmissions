class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {

        int row = mat.size();
        int col = mat[0].size();
        vector<int> ans[row+col];
        for(int i = 0;i<row;i++)
        {
            for(int j = 0;j<col;j++)
            {
                ans[i+j].push_back(mat[i][j]);        
            }
        }
        for(int i = 0;i<row+col;i++)
        {
            if(i%2==0)
            {
                reverse(ans[i].begin(),ans[i].end());
            }
        }
        vector<int> res;
        
        for(auto v:ans)
        {
            for(int i:v)
            {
                res.push_back(i);
            }
        }
        
        return res;
    }
};