//just added a for loop to my approach of frog jump
class Solution {
  public:
  
  int dpmemo(int n,int k,vector<int>& height,vector<int> &dp){
      if(n==0)
      return 0;
      
      if(n==1)
      return abs(height[1]-height[0]);
      
      
      if(dp[n]!=INT_MAX)
      return dp[n];
      
      dp[n]=INT_MAX;
      
      for(int i=1;i<=k;i++){
         if(n-i>=0)
          dp[n]=min(abs(height[n]-height[n-i])+dpmemo(n-i,k,height,dp),dp[n]);
      }
      
      
      return dp[n];
  }
    int minimizeCost(vector<int>& height, int n, int k) {
       //vector<int> dp(n+1,INT_MAX);
       
        vector<int> dp(n+1,INT_MAX);
        
        dp[0]=0;
        dp[1]=abs(height[1]-height[0]);
        
        for(int i=2;i<n;i++){
            for(int j=1;j<=k;j++){
                if((i-j)>=0)
            dp[i]=min(abs(height[i]-height[i-j]) + dp[i-j],dp[i]);
            }
            
        }
        
        return dp[n-1];  
       //return dpmemo(n-1,k,height,dp);
    }
};
