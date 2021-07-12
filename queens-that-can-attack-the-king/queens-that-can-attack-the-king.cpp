class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> dir = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
        int count = 0;
        int jumps = 1;
        vector<vector<int>> board(8,vector<int>(8,0));
        
        for(int i = 0;i<queens.size();i++)
        {
            int x = queens[i][0];
            int y = queens[i][1];
            board[x][y] = 1;
        }
        
        board[king[0]][king[1]] = 2;
        
        for(int i = 0;i<8;i++)
        {
            for(int j = 0;j<8;j++)
            {
                if(board[i][j] == 2)
                {
                
                    for(int k = 0;k<dir.size();k++)
                    {   
                        while((i+jumps*dir[k][0]>=0) &&(i+jumps*dir[k][0]<8) && (j+jumps*dir[k][1]>=0) && (j+jumps*dir[k][1]<8))
                              {
                                  int x = i+jumps*dir[k][0];
                                  int y = j+jumps*dir[k][1];
                                  if(board[x][y] == 1)
                                  {
                                      ans.push_back({x,y});
                                      break;
                                  }
                                  jumps++;
                              }
                        jumps = 1;
                    }
                }
            }
        }
        return ans;
    }
};