//similar to stock buy and sell 3

class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        
        vector<vector<vector<int>>> dp(N+1,vector<vector<int>>(2,vector<int>(K+1,0)));
        
        //base-case when cnt=0 return 0 and i==n return 0 but dp already initialised to 0
        
        //explore
        //1-buy
        //0-sell
        
        for(int i=N-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                for(int cnt=1;cnt<=K;cnt++) //not include 0 as dp is 0 for that anywways and it gives segmentation fault when cnt-1
                {
                    if(buy){
                        dp[i][buy][cnt]=max(-A[i]+dp[i+1][0][cnt],0 + dp[i+1][1][cnt]);
                    }
                    
                    else{
                         
                        dp[i][buy][cnt]=max(A[i]+dp[i+1][1][cnt-1],0 + dp[i+1][0][cnt]);
                    }
                }
            }
        }
        
        return dp[0][1][K];
    }
};
