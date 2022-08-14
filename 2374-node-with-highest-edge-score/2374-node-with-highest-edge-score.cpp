class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        vector<long long> outDegree(n,0);
        long long maxVal = LONG_MIN;
        int minIndx = -1;
        for(int i=0;i<edges.size();i++)
            outDegree[edges[i]] += i;
        for(int i=0;i<n;i++)
        {
            if(maxVal < outDegree[i])
            {
                maxVal = outDegree[i];
                minIndx = i;
            }
                
        }
        return minIndx;
        
    }
};