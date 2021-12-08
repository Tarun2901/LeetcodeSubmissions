class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int ans = 0;
        int ccp = capacity;
        
        for(int i = 0;i<plants.size();i++)
        {
            if(ccp>=plants[i])
            {
                ccp-=plants[i];
                ans++;
            }
            else
            {
                ccp = capacity;
                ccp-=plants[i];
                ans+= i;
                ans+=i+1;
            }
        }
        return ans;
    }
};

