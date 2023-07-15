class Solution
{
    public:
    int mod=1e9+7;
     //when count all ways we use base case to return 1 and 0 to get count
    int dpmemo(int i,int j,string S, string T,vector<vector<int>> &dp){
        
        if(j<0)
        return 1;
        
        if(i<0)
        return 0;
        
        if(dp[i][j]!=-1)
        return dp[i][j];
        
        if(S[i]==T[j])
        return dp[i][j]=dpmemo(i-1,j-1,S,T,dp)+dpmemo(i-1,j,S,T,dp); //match it + not match it
        
        else
        return dp[i][j]=dpmemo(i-1,j,S,T,dp);
        
    }
    int subsequenceCount(string S, string T)
    {
        int n=S.length();
        int m=T.length();
        
       // vector<vector<int>> dp(n,vector<int>(m,-1)); //for memo
      
    // return dpmemo(n-1,m-1,S,T,dp); //gives tle
     
     //tabulation
     
     //base case
     //we use right shift indexing where -1 becomes 0
     
      vector<vector<int>> dp(n+1,vector<int>(m+1,0));
      
      for(int i=0 ; i<=n; i++){
          dp[i][0]=1;
      }
      
    //   for(int i=1 ; i<=m; i++){
    //       dp[0][i]=0;
    //   } since dp initialised to 0
      
      
      //explore all options
      
      for(int i=1;i<=n;i++){
          for(int j=1;j<=m;j++){
              
              //copy-recursion
              
               if(S[i-1]==T[j-1]) //since right shift index
            dp[i][j]=(dp[i-1][j-1] + dp[i-1][j])%mod; 
        
            else
           dp[i][j]=(dp[i-1][j])%mod;
          }
      }
      
      return dp[n][m];
    }
};
 
