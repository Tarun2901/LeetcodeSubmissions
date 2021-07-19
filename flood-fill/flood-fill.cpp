class Solution {
public:
    
    void solve(vector<vector<int>>& image, int x,int y,int row,int col,int color,int newColor)
        {
            
            if(x<0 || x>=row || y<0 || y>=col || image[x][y] !=color)
            {
                return;
            }
            
            image[x][y] = newColor;
            solve(image,x+1,y,row,col,color,newColor);
            solve(image,x-1,y,row,col,color,newColor);
            solve(image,x,y-1,row,col,color,newColor);
            solve(image,x,y+1,row,col,color,newColor);

        }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int row = image.size();
        int col = image[0].size();
        
        int color = image[sr][sc];
        if(color!=newColor)
        { solve(image,sr,sc,row,col,color,newColor);
        }
        return image;
    }
};