class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        if(maxDoubles==0)
            return target-1;
        
        int moves=0;
        int x= target;
        while(maxDoubles>=1 && x>1){
            if(x%2!=0)
            {
                x-=1;
                moves+=1;
            }
            else
            {
                x=x/2;
                moves+=1;
                maxDoubles--;
            } 
        }
        while(x>1)
        {
            moves++;
            x--;
        }
        return moves;
    }
};