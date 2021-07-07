class Solution {
public:
      int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<pair<int,int>, int>> q;
        vector<vector<pair<int,int>>> graph(n);
        for(int i=0;i<flights.size();i++){
            graph[flights[i][0]].push_back(make_pair(flights[i][1], flights[i][2]));
        }
        q.push(make_pair(make_pair(src, 0), 0));
        vector<int> dist(n,INT_MAX);
        dist[src]=0;
        while(!q.empty()){
            pair<pair<int,int>, int> p=q.front();
            q.pop();
            int src=p.first.first;
            int level=p.first.second;
            int cost=p.second;
            if(level<=k){
                for(auto it: graph[src]){
                    int child=it.first;
                    int price=it.second;
                    if(level<k){
                        if(dist[child]>cost+price)
                        {
                            dist[child]=cost+price;
                            q.push(make_pair(make_pair(child, level+1), cost+price));
                        }
                    }
                    else if(child==dst){
                        if(dist[child]>cost+price)
                        {
                            dist[child]=cost+price;
                            q.push(make_pair(make_pair(child, level+1), cost+price));
                        }
                    }    
                }   
            }
        }
        if(dist[dst]==INT_MAX){
            return -1;
        }
        return dist[dst];
    }
};