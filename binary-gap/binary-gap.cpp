class Solution {
public:
    int binaryGap(int n) {
        vector<int> binary;
        while(n>0)
        {
            binary.push_back(n%2);
            n = n/2;
        }
        int maxDist = 0;
        int prev = -1;
        for(int i = 0;i<binary.size();i++)
        {
            if(prev == -1 && binary[i] == 1)
            {
                prev = i;
            }
            else if(prev!=-1 && binary[i] == 1)
            {
                maxDist = max(maxDist,i-prev);
                prev = i;
            }
        }
        return maxDist;
    }
};