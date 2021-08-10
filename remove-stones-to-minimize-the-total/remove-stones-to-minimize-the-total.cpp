class Solution {
public:

  
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> q;
        
        int sum = 0;
        for(int i = 0;i<piles.size();i++)
        {
            sum+= piles[i];
            q.push(piles[i]);
        }
        
        int ans = 0;
        for(int i = 0;i<k;i++)
        {
            int ele = q.top();
            q.pop();
            ans+= floor(ele/2);
            q.push((ele - floor(ele/2)));
        }
        
        return sum - ans;
    }
};