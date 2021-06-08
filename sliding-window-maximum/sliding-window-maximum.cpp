class Solution {
public:
    
    
    vector<int> res;
    
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
            priority_queue<pair<int,int>> pq;
    
            int idx = 0;
        
            for(idx = 0;idx<k;idx++)
            {
                pq.push(make_pair(arr[idx],idx));
            }
            res.push_back(pq.top().first);
        
            for(int i = idx;i<arr.size();i++)
            {
                pq.push(make_pair(arr[i],i));
                while(pq.top().second<=i-k){
                    pq.pop();
                }
                res.push_back(pq.top().first);
            }
            return res;
    }
};