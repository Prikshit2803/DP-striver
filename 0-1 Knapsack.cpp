//memoisation and tabulation
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    int dpmemo(int i,int W,int wt[], int val[],vector<vector<int>> &dp){
        
        // if( W==0)
        // return 0; not needed as when w=0 no more will be added
        
        if(i==0){
        if(wt[0]<=W)
        return val[0];
        
        
        return 0;
        }
        
        if(dp[i][W]!=-1){
            return dp[i][W];
        }
        
        int notTake=0+dpmemo(i-1,W,wt,val,dp);
        
        int Take=0;
         if(wt[i]<=W){
        Take=val[i] + dpmemo(i-1,W-wt[i],wt,val,dp);
       
        }
        
        return dp[i][W]=max(Take,notTake);
    }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // vector<vector<int>> dp(n,vector<int>(W+1,-1)); //for memo
      //return dpmemo(n-1,W,wt,val,dp);
      
      //tabulation
      
      vector<vector<int>> dp(n,vector<int>(W+1,0));
      
      //base-case
      for(int i=wt[0];i<=W;i++)
      dp[0][i]=val[0]; //this satisfies condition  if(i==0)  if(wt[0]<=W) return val[0]
       
      
      //explore all options
      
      for(int i=1;i<n;i++){
          for(int wgt=0;wgt<=W;wgt++){
              //copy-recursion 
              int notTake=0+dp[i-1][wgt];
        
        int Take=0;
         if(wt[i]<=wgt){
        Take=val[i] + dp[i-1][wgt-wt[i]];
       
        }
        
         dp[i][wgt]=max(Take,notTake);
          }
      }
      
      return dp[n-1][W];
    }
};

//Space-optmisation
  int knapSack(int W, int wt[], int val[], int n) 
    { 
       
      
      vector<int> prev(W+1,0),cur(W+1,0);
      
      for(int i=wt[0];i<=W;i++)
      prev[i]=val[0]; 
       
      
     
      
      for(int i=1;i<n;i++){
          for(int wgt=0;wgt<=W;wgt++){
             
              int notTake=0+prev[wgt];
        
        int Take=0;
         if(wt[i]<=wgt){
        Take=val[i] + prev[wgt-wt[i]];
       
        }
        
         cur[wgt]=max(Take,notTake);
          }
          
          prev=cur;
      }
      
      return prev[W];
    }
};
