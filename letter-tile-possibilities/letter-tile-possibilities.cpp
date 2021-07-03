class Solution {
public:
    unordered_set<string> st;
   
        void dfs(string tiles, string ans, int idx, int n,vector<int>& visited)
        {
            if(idx == n)
            {
                return;
            }
            
            for(int i = 0;i<n;i++)
            {
                if(visited[i] == 0)
                {
                    ans.push_back(tiles[i]);
                    visited[i] = 1;
                    st.insert(ans);
                    dfs(tiles,ans,idx+1,n,visited);
                    ans.pop_back();
                    visited[i] = 0;
                }
            }
        }
    
    int numTilePossibilities(string tiles) {
        string ans = "";
        int idx = 0;
        int n = tiles.size();
        vector<int>visited(n,0);
        dfs(tiles,ans,idx,n,visited);
        
        return st.size();
    }
};