class Solution {
public:

    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        
       unordered_map<int,vector<int>> bus_route;
       int maxm = INT_MIN;
       for(int i = 0;i<routes.size();i++)
       {
           for(int j:routes[i])
           {
               bus_route[j].push_back(i);
               if(j>maxm)
               {
                   maxm = j;
               }
           }
       }
       vector<int> busStop(1000001,0);
       vector<int> bus(routes.size()+1,0);
       queue<pair<int,int>> q;
       q.push({S,0});
       while(!q.empty())
       {
           int node = q.front().first;
           int cost = q.front().second;
           q.pop();
           busStop[node] = 1;
           if(node == T)
           {
               return cost;
           }
           for(auto it:bus_route[node])
           {
               if(bus[it]==0)
               {
                   for(auto j:routes[it])
                   {
                       
                       if(busStop[j] == 0)
                       {
                           q.push(make_pair(j,cost+1));
                       }
                   }
                
               }
               bus[it] = 1;
           }
          
   
    }
         return -1;
    }
};