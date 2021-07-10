class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int res = -1;
        int lo = 1;
        int hi = 1e9;
        while(lo<=hi)
        {
            int mid = lo+(hi-lo)/2;
            int count = 0;
            int streak = 0;
            int bq = 0;
            for(int i=0;i<bloomDay.size();i++)
            {
                if(bloomDay[i]<=mid)
                {
                    count++;
                    if(count == k)
                    {
                        bq++;
                        count = 0;
                    }
                }
                else
                {
                    count = 0;
                }
                
            }
          
            if(bq >= m)
            {   if(res == -1)
                {
                    res = mid;
                }
                else
                {
                res = min(res,mid);
                }
                hi = mid-1;
            }
            else
            {
                lo = mid+1;
            }
        }
        return res;
    }
};