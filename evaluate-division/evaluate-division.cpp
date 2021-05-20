class Solution {
public:
    unordered_map<string,unordered_map<string,double>> graph;
    unordered_set<string> vis;
    double find(const string& src, const string& dst){
        if (vis.find(src) != vis.end()) return -1.0;
        
        if (graph[src].find(dst) != graph[src].end()) return graph[src][dst];
        
        vis.insert(src);
        for (auto& p : graph[src]){
            double ret = find(p.first, dst);
            if (ret >= 0.0) return graph[src][p.first] * ret;
        }
        return -1.0;
    }
        
        
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for(int i = 0;i<equations.size();i++)
        {
            graph[equations[i][0]][equations[i][1]] = values[i];
            graph[equations[i][1]][equations[i][0]] = 1/values[i];
        }
        vector<double> ans;
        for(auto q:queries)
        {
            vis.clear();
            ans.push_back(find(q[0],q[1]));
        }
        return ans;
    }
    
};