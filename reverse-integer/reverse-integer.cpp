class Solution {
public:
    int reverse(int x) {
        long sum =0;
        while(x!=0)
        {
            int r = x%10;
            sum = (sum*10) + r;
            if(sum>INT_MAX || sum<INT_MIN)  return 0;
            x = x/10;
        }
        return sum;
    }
};