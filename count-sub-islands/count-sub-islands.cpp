class Solution {
public:
    
  
    int dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int m, int n, int i, int j, vector<vector<int>>& visited){
        if(i<0||j<0||i==m||j==n||visited[i][j]||grid2[i][j]==0){
            return 1;
        }
        visited[i][j]=1;
        int ans =1;
        if(grid1[i][j]==0){
            ans=0;
        }
        int a=dfs(grid1,grid2,m,n,i+1,j,visited);
        int b=dfs(grid1,grid2,m,n,i,j+1,visited);
        int c=dfs(grid1,grid2,m,n,i-1,j,visited);
        int d=dfs(grid1,grid2,m,n,i,j-1,visited);
        return ans&&a&&b&&c&&d;
    }

    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m=grid1.size();
        int n=grid1[0].size();
        vector<vector<int>> visited(m, vector<int>(n,0));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid2[i][j]==1&&!visited[i][j]){
                    ans+=dfs(grid1,grid2,m,n,i,j,visited);
                }
            }
        }
        return ans;

    }
};