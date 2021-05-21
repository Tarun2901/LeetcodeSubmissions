class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
       
        vector<int>graph[n+1];
        
        for(int i = 0;i<dislikes.size();i++)
        {
            graph[dislikes[i][0]].push_back(dislikes[i][1]);
            graph[dislikes[i][1]].push_back(dislikes[i][0]);
        }
 		vector<int>color(n+1, -1);

 			for (int i = 1; i <=n; i++) {
 				if (color[i] != -1) continue;

 				color[i] = 1;
 				queue<int>q;
 				q.push(i);

 				while (!q.empty()) {
 					int t = q.front();
 					q.pop();

 					for (int j = 0; j <graph[t].size(); j++) {
 						if (color[graph[t][j]] == -1) {
 							color[graph[t][j]] = 1-color[t];
 							q.push(graph[t][j]);
 						} else if (color[graph[t][j]] == color[t]) {
 							return false;
 						}
 					}
 				}
 			}

 			return true;
 		}
};