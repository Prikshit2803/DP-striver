//memo and tabulation
 int dpmemo(int i,int n,int price[],vector<vector<int>> &dp){
      if(i==0)
      return n*price[0];
      
      if(dp[i][n]!=-1)
      return dp[i][n];
      
      int notTake=0 + dpmemo(i-1,n,price,dp);
      
      int take=INT_MIN;
      
     int rodlen=i+1;
     
     if(rodlen<=n)
     take=price[i] + dpmemo(i,n-rodlen,price,dp); //we stay at i as we can take a length multiple time
     
     return dp[i][n]=max(take,notTake);
      
      
      
  }
    int cutRod(int price[], int n) {
        
        // vector<vector<int>> dp(n,vector<int>(n+1,-1));
        
        // return dpmemo(n-1,n,price,dp);
        
        //tabulation
         vector<vector<int>> dp(n,vector<int>(n+1,0));
         
         for(int j=0;j<=n;j++)
         dp[0][j]=j*price[0]; //base case
         
         
         for(int i=1;i<n;i++){
             for(int j=0;j<=n;j++){
                 
                 int notTake=0 + dpmemo(i-1,j,price,dp);
      
                 int take=INT_MIN;
      
               int rodlen=i+1;
     
              if(rodlen<=j)
            take=price[i] + dpmemo(i,j-rodlen,price,dp); //we stay at i as we can take a length multiple time
     
               dp[i][j]=max(take,notTake);
       
             }
         }
         
         return dp[n-1][n];
        
    }
