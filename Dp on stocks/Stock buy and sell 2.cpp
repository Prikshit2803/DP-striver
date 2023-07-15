//Greedy approach :  sell asap when larger number

class Solution {
  public:
    int stockBuyAndSell(int n, vector<int> &arr) {
      
      int profit=0;


   for(int i=1;i<arr.size();i++){
   if(arr[i]>arr[i-1])
   profit+=arr[i]-arr[i-1];
   
  
    
   }

    return profit;
    }
};

//Tabulation and memoisation
class Solution {
  public:
  
  long long mod=1e9 +7;
   int dpmemo(int i,int buy,vector<int> &arr, vector<vector<int>> &dp,int n){
       if(i==n)
       return 0;
       
       if(dp[i][buy]!=-1)
       return dp[i][buy];
       
       long profit=0;
       
       if(buy){
           //buy
          profit=max((-arr[i] + dpmemo(i+1,0,arr,dp,n)),(0 + dpmemo(i+1,1,arr,dp,n)))%mod;
       }
       
       else{
           //sell
           
          profit=max((arr[i] + dpmemo(i+1,1,arr,dp,n)),(0 + dpmemo(i+1,0,arr,dp,n)))%mod;
           
       }
       
       return dp[i][buy]=profit;
   }
    int stockBuyAndSell(int n, vector<int> &arr) {
      //1- buy
      //0-sell
      
     // vector<vector<int>> dp(n,vector<int>(2,-1)); //2 coz 1 and 0 of buy and sell
    
    //return dpmemo(0,1,arr,dp,n);
    
    //tabulation
    
    //base-case
    vector<vector<int>> dp(n+1,vector<int>(2,0));
    
    dp[n][0]=0;
    dp[n][1]=0;
    
    for(int i=n-1;i>=0;i--){
        for(int buy=0;buy<=1;buy++){
            
            long profit=0;
       
       if(buy){
           //buy
          profit=max(-arr[i] + dp[i+1][0],0 + dp[i+1][1])%mod;
       }
       
       else{
           //sell
           
          profit=max(arr[i] + dp[i+1][1],0 + dp[i+1][0])%mod;
           
       }
       
       dp[i][buy]=profit;
       
        }
    }
    
    return dp[0][1];
    }
};
