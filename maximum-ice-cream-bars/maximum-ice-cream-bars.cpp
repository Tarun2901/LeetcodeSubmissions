class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int ans = 0;
        int temp = coins;
        for(int it:costs)
        {
            if(temp-it>=0)
            {
                temp = temp-it;
                ans++;
            }
        }
        return ans;
    }
};