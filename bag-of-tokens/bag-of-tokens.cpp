class Solution {
public:
       int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int score=0;
        int n=tokens.size();
        int i=0,j;
        for(i=0,j=n-1;i<=j;i++){
            if(power>=tokens[i]){
                power-=tokens[i];
                score++;
                if(i<j-1&&power<tokens[i+1]&&power+tokens[j]>=tokens[i+1]&&score>0){
                    power+=tokens[j];
                    j--;
                    score--;
                }
            }
            else{
                break;
            }
        }
        return score;
    }

};