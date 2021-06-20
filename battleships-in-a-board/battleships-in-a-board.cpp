class Solution {
public:
    
    
    void dfs(vector<vector<char>>& board, int i,int j,int row,int col,vector<vector<int>>& visited)
    {
        if(i<0 || j<0 || i == row || j == col || board[i][j] == '.' || visited[i][j] == 1)
        {
            return;
        }
        visited[i][j] = 1;
        dfs(board,i-1,j,row,col,visited);
        dfs(board,i+1,j,row,col,visited);
        dfs(board,i,j-1,row,col,visited);
        dfs(board,i,j+1,row,col,visited);

    }
        
        
        
    int countBattleships(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        
        vector<vector<int>> visited(row,vector<int>(col,0));
        int count = 0;
        for(int i = 0;i<row;i++)
        {
            for(int j = 0;j<col;j++)
            {
                char ch = board[i][j];
                if(ch == 'X' && visited[i][j] == 0)
                {
                    count++;
                    dfs(board,i,j,row,col,visited);
                }
            }
        }
        return count;
    }
};