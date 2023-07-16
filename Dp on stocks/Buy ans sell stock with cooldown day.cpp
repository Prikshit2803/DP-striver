long long maximumProfit(vector<long long>&arr, int n) {
       
       
       vector<vector<long long int>>  dp(n+2,vector<long long int>(2,0)); //n+2 as i+2 can cause segmentation fault
       
       //base-case if i==n return 0
       //1-buy
       //0-sell
       for(int i=n-1;i>=0;i--){
           for(int buy=0;buy<=1;buy++){
               
               if(buy){
                   dp[i][buy]=max(-arr[i]+dp[i+1][0],0+dp[i+1][1]);
               }
               
               else{
                    dp[i][buy]=max(arr[i]+dp[i+2][1],0+dp[i+1][0]); //if sell, jump to i+2 to buy due to cool down
               }
           }
       }
       
       return dp[0][1];
    }
