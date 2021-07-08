class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int row=box.size();
        int col=box[0].size();
        for(int i=0;i<row;i++){
            int idx=col-1;
            for(int j=col-1;j>=0;j--){
                if(box[i][j]=='.'){
                    continue;
                }
                else if(box[i][j]=='*'){
                    idx=j-1;
                }
                else{
                    box[i][idx]='#';
                    if(idx!=j)
                        box[i][j]='.';
                    idx--;
                }
            }
        }
        vector<vector<char>> boxr(col, vector<char>(row,'.'));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                boxr[j][i]=box[row-i-1][j];
            }
        }
        return boxr;
    }
};