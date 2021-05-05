class Solution {
    public int oddCells(int m, int n, int[][] indices) {
        int result[][]=new int[m][n];
        int count=0;
        for(int i=0;i<indices.length;i++){
            int a[]=indices[i]; //0,1
            int row=a[0];
            int col=a[1];
            for(int j=0;j<result[row].length;j++){
                result[row][j]++;
            }
            for(int j=0;j<result.length;j++){
                result[j][col]++;
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(result[i][j]%2==1)
                    count++;
            }
        }
        return count;
    }
}