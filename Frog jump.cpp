// all three methods in my way
class Solution {
  public:
  
  
  int dpmemo(int n,vector<int>& dp,vector<int>& height){
      if(n==0)
      return 0; // as it means 1 stair which is the oth stair  and  no energy lost as we there already
      
      if(n==1)
      return abs(height[1]-height[0]);
      
      if(dp[n]!=-1)
      return dp[n];
      
      
      return dp[n] = min((abs(height[n]-height[n-1]) + dpmemo(n-1,dp,height)),(abs(height[n]-height[n-2]) + dpmemo(n-2,dp,height)));
  }
    int minimumEnergy(vector<int>& height, int n) {
        
        
        
        // vector<int> dp(n,-1);
        
        // dp[0]=0;
        // dp[1]=abs(height[1]-height[0]);
        
        // for(int i=2;i<n;i++){
        //     dp[i]=min((abs(height[i]-height[i-1]) + dp[i-1]),(abs(height[i]-height[i-2]) + dp[i-2]));
            
        // }
        
        // return dp[n-1];  // as stairs from 0 to n-1 
        
        
        //*****space-optimisation******
        
        
        
        // int prev2=0;
        // int prev1=abs(height[1]-height[0]);
        
        // if(n==1)
        // return prev2;
        
        // if(n==2)
        // return prev1;
         
        // int cur;
        
        // for(int i=2;i<n;i++){
        //     cur=min((abs(height[i]-height[i-1]) + prev1),(abs(height[i]-height[i-2]) + prev2));
        //     prev2=prev1;
        //     prev1=cur;
        // }
        
        // return prev1; 
        
        
        
        //*****Memoisation****
        
        vector<int> dp(n,-1);
        
        return dpmemo(n-1,dp,height); // as stairs from 0 to n-1
        
        
    }
};
