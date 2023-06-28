class Solution {
  public:
  
  long long int temp=1000000007;
  long long int dpmemo(int n,vector<long long int> &dp){
      
      
       if(n<=1)
       return n;
       
       if(dp[n]!=-1)
       return dp[n];
       
       
       dp[n]= (dpmemo(n-1,dp))%temp + (dpmemo(n-2,dp))%temp;
       
       return dp[n]%temp;
       
  }
    long long int topDown(int n) {
       vector<long long int> dp(n+1,-1);
       
      return (dpmemo(n,dp))%temp;
       
      // return dp[n];
       
    }
    long long int bottomUp(int n) {
        // this is without space optmisation
    //   vector<long long int> dp(n+1,0);
    //   dp[0]=0;
    //   dp[1]=1;
      
    //   for(int i=2;i<=n;i++){
    //       dp[i]=((dp[i-1])%temp + (dp[i-2])%temp)%temp;
          
    //   }
      
    //   return dp[n]%temp;
    
    //space optimisation
    if(n<=1)
    return 1;
    
     long long int prev2=0;
     long long int prev1=1;
     long long int cur;
      
      for(int i=2;i<=n;i++){
          cur=((prev1%temp) + (prev2)%temp)%temp;
          prev2=prev1;
          prev1=cur;
          
          
      }
      
      //cout<<cur;
      return (prev1)%temp;
    }
};
