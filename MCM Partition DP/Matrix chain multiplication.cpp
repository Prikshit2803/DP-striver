int dpmemo(int i,int j,int arr[], vector<vector<int>> &dp){
    if(i==j)
    return 0;
    
    int mini=1e9;
    if(dp[i][j]!=-1)
    return dp[i][j];
    
    for(int k=i;k<j;k++){ //k denotes partition
        
        int steps=(arr[i-1]*arr[k]*arr[j]) + dpmemo(i,k,arr,dp) + dpmemo(k+1,j,arr,dp);
        
        mini=min(mini,steps);
    }
    
    return dp[i][j]=mini;
}
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>> dp(N,vector<int>(N,-1));
        
        return dpmemo(1,N-1,arr,dp);
    }

//TABULATION
int matrixMultiplication(int N, int arr[])
    {
        
        
        //Tabulation
        
        vector<vector<int>> dp(N,vector<int>(N,0));
        
        //it covers base case of i==j return 0
         
        for(int i=N-1;i>=1;i--){
            for(int j=i+1;j<N;j++){
               int mini=1e9; //it is imp to be here
                for(int k=i;k<j;k++){ //k denotes partition
        
        int steps=(arr[i-1]*arr[k]*arr[j]) + dp[i][k] + dp[k+1][j];
        
        mini=min(mini,steps);
    }
    
    dp[i][j]=mini;
            }
        }
        
        return dp[1][N-1];
        }
