//{ Driver Code Starts
//Initial Template for C

#include <stdio.h>


// } Driver Code Ends
//User function Template for C


//Function to rotate matrix anticlockwise by 90 degrees.
void rotateby90(int n, int matrix[][n]) 
{
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<i;j++)
        {
            int k = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = k;
        }
    }
    int s = 0;
    int e = n-1;
    
    while(s<e)
    {
        for(int i = 0;i<n;i++)
        {
            int k = matrix[s][i];
            matrix[s][i] = matrix[e][i];
            matrix[e][i] = k;
        }
        s = s+1;
        e = e-1;
    }
} 

//{ Driver Code Starts.

int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int n;
		scanf("%d", &n);
		int matrix[n][n];
	 
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				scanf("%d", &matrix[i][j]);
			}
		}
		
		rotateby90(n, matrix);
		for(int i = 0; i < n; i++)
		    for(int j=0; j<n; j++)
			    printf("%d ", matrix[i][j]);
		printf("\n");
	}
	return 0;
}
// } Driver Code Ends