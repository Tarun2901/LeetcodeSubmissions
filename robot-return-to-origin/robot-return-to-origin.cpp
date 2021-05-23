class Solution {
public:
    bool judgeCircle(string moves) {
        int dir[2] = {0,0};
        for(int i = 0;i<moves.size();i++)
        {
            if(moves[i] == 'U')
            {
                dir[0]++;
            }
            if(moves[i] == 'D')
            {
                dir[0]--;
            }
            if(moves[i] == 'R')
            {
                dir[1]++;
            }
            if(moves[i] == 'L')
            {
                dir[1]--;
            } 
        }

        if(dir[0] == 0 && dir[1] == 0)
        {
            return true;
        }
        return false;
    }
};