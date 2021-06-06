class Solution {
public: vector<vector<int>> ans;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<int> dist(n);
        map<int,int> visited;
        map<int,vector<pair<int,int>>> distpair;
        for(int i = 0;i<n;i++)
        {
            int x = points[i][0];
            int y = points[i][1];
            
            dist[i] = x*x + y*y;
            distpair[dist[i]].push_back(make_pair(x,y));
        }
        
        priority_queue<int> pq;
        
        for(int i = 0;i<n;i++)
        {
            if(pq.size()<k)
            {
                pq.push(dist[i]);
            }
            else
            {
                if(dist[i]<pq.top())
                {
                    pq.pop();
                    pq.push(dist[i]);
                }
            }
        }
        
        while(pq.size()>0)
        {
            int val = pq.top();
            pq.pop();
            if(visited[val] == 0)
            {
            for(pair<int,int>p:distpair[val])
            {
        
            int x = p.first;
            int y = p.second;
            ans.push_back({x,y});
            }
            }
            visited[val]++;
        }
        
        return ans;
    }
};