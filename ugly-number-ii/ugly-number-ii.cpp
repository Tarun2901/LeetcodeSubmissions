class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>ugly(n+1,0);
        ugly[1] = 1;
        
        int two = 1;
        int three = 1;
        int five = 1;
        
        for(int i = 2;i<=n;i++)
        {
            int next2 = 2*ugly[two];
            int next3 = 3*ugly[three];
            int next5 = 5*ugly[five];
            
            int omin = min(next2,min(next3,next5));
            ugly[i] = omin;
            if(omin == next2)
            {
                two++;
            }
            if(omin == next3)
            {
                three++;
            }
            if(omin == next5)
            {
                five++;
            }
        }
        
        return ugly[n];
    }
};