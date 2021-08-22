class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size();
        
        int a = tops[0];
        int b = bottoms[0];
        
        int countaintop = 0;
        int countbintop = 0;
        int countainbot = 0;
        int countbinbot = 0;
        
        for(int i = 0;i<n;i++)
        {
            if(countaintop!=INT_MAX)
            {
                if(tops[i] == a)
                {
                    countaintop+= 0;
                }
                else if(bottoms[i] == a)
                {
                    countaintop+=1;
                }
                else
                {
                    countaintop = INT_MAX;
                }
            }
             if(countbintop!=INT_MAX)
            {
                if(tops[i] == b)
                {
                    countbintop+= 0;
                }
                else if(bottoms[i] == b)
                {
                    countbintop+=1;
                }
                else
                {
                    countbintop = INT_MAX;
                }
            }
             if(countainbot!=INT_MAX)
            {
                if(bottoms[i] == a)
                {
                    countainbot+= 0;
                }
                else if(tops[i] == a)
                {
                    countainbot+=1;
                }
                else
                {
                    countainbot = INT_MAX;
                }
            }
            if(countbinbot!=INT_MAX)
            {
                if(bottoms[i] == b)
                {
                    countbinbot+= 0;
                }
                else if(tops[i] == b)
                {
                    countbinbot+=1;
                }
                else
                {
                    countbinbot = INT_MAX;
                }
            }
        }
        
        int mn = min(min(countaintop,countbintop),min(countainbot,countbinbot));
        if(mn == INT_MAX)
        {
            return -1;
        }
        
        return mn;
        
    }
};