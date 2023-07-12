//Slight change to base-case(similar to coint-change 1) and 'Take' condition(similar to coint-change 1)
class Solution{
public:
 int dpmemo(int i,int W,int val[], int wt[],vector<vector<int>> &dp){
     if(i==0){
         return ((int)W/wt[0])*val[0];
     }
     
     if(dp[i][W]!=-1)
     return dp[i][W];
     
     int notTake=0+dpmemo(i-1,W,val,wt,dp);
     int Take=0;
     if(wt[i]<=W)
     Take=val[i]+dpmemo(i,W-wt[i],val,wt,dp);
     
     return dp[i][W]=max(Take,notTake);
 }
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>> dp(N,vector<int>(W+1,-1));
       // vector<vector<int>> dp(N,vector<int>(W+1,0));
      
      return dpmemo(N-1,W,val,wt,dp);
      //base-case - this changes - Similar to coin change-1
      for(int i=wt[0]; i<=W; i++){
        dp[0][i] = ((int) i/wt[0]) * val[0];
    } 
       
      
      //explore all options
      
      for(int i=1;i<N;i++){
          for(int wgt=0;wgt<=W;wgt++){
              //copy-recursion 
              int notTake=0+dp[i-1][wgt];
        
        int Take=0;
         if(wt[i]<=wgt){
        Take=val[i] + dp[i][wgt-wt[i]]; //Just change i-1 to i
       
        }
        
         dp[i][wgt]=max(Take,notTake);
          }
      }
      
      return dp[ N-1][W];
    }
};
