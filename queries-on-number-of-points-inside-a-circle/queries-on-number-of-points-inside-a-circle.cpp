class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& P, vector<vector<int>>& Q) {
        int q=Q.size();
        vector<int> ans;

      for(int i=0;i<q;i++){
        int ci=Q[i][0];
        int cj=Q[i][1];
        int r=Q[i][2];
        int rsq=r*r;
        int count=0;
        
        for(int i=0;i<P.size();i++){
            int x=P[i][0];
            int y=P[i][1];
            
            int d=(x-ci)*(x-ci)+(y-cj)*(y-cj);
            if(d<=rsq) count++;
        }
        
        ans.push_back(count);
    }
    
    return ans;
    }
};