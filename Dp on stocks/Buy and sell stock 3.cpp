//max two transactions

long long mod=1e9 +7;
   int dpmemo(int i,int buy,vector<int> &arr,  vector<vector<vector<int>>> &dp,int n,int cnt){
       
       if(cnt==0)
       return 0;
       
       if(i==n)
       return 0;
       
       if(dp[i][buy][cnt]!=-1)
       return dp[i][buy][cnt];
       
      long long profit=0;
       
       if(buy){
           //buy
          profit=max((-arr[i] + dpmemo(i+1,0,arr,dp,n,cnt))%mod,(0 + dpmemo(i+1,1,arr,dp,n,cnt))%mod);
       }
       
       else{
           //sell
           
          profit=max((arr[i] + dpmemo(i+1,1,arr,dp,n,cnt-1))%mod,(0 + dpmemo(i+1,0,arr,dp,n,cnt))%mod);
           
       }
       
       return dp[i][buy][cnt]=profit;
   }
   
int maxProfit(vector<int>&arr){
    
    int n=arr.size();
   // vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1))); //for memo
    
    //return dpmemo(0,1,arr,dp,n,2);
    
    //tabulation
    //base-case
    
     vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
     
    
    
    for(int i=n-1;i>=0;i--){
         for(int buy=0;buy<=1;buy++){
             for(int cnt=1;cnt<=2;cnt++){ //for every cnt = 0 dp=0 ..refer base case
                 long long profit=0;
       
       if(buy){
           //buy
          profit=max(-arr[i] + dp[i+1][0][cnt],0 + dp[i+1][1][cnt]);
       }
       
       else{
           //sell
           
          profit=max(arr[i] + dp[i+1][1][cnt-1],0 + dp[i+1][0][cnt]);
           
       }
       
       dp[i][buy][cnt]=profit;
             }
         }
    }
    
    return dp[0][1][2];
}
