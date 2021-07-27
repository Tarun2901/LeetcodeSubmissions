class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int> mp;
        int cd = 0;
        
        for(auto it: arr)
        {   if(mp[it] == 0)
            {
                cd++;
            }
            mp[it]++;
        }
        
        priority_queue<int> pq;
        
        for(auto p: mp)
        {
            pq.push(p.second);
        }
        
        int n = arr.size();
        int target = n/2;
        int count = 0;
        while(n>target)
        {
            n-=pq.top();
            pq.pop();
            count++;
        }
        return count;
    }
};