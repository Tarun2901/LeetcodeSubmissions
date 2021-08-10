class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int ans = INT_MIN;
        int n  = seats.size();
        
        vector<int>left(n,INT_MAX);
        vector<int>right(n,INT_MAX);
        int c = 0;
        bool seatYet = false;
        for(int i = 0;i<n;i++)
        {
            if(seats[i] == 1)
            {
                c = 0;
                seatYet = true;
            
            }
            if(seatYet == true)
            {
                c++;
                left[i] = c;
            }
          
        
        }
        seatYet = false;
        c = 0;
        
        for(int i = n-1;i>=0;i--)
        {
            if(seats[i] == 1)
            {
                c = 0;
                seatYet = true;
            
            }
            if(seatYet == true)
            {
                c++;
                right[i] = c;
            }
        }
        
        for(int i = 0;i<n;i++)
        {
            if(seats[i] == 0)
            {
                ans = max(ans,min(left[i]-1,right[i]-1));
            }
        }
        return ans;
    }
};