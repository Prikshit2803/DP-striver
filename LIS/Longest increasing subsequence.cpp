//DP gives TLE
//Function to find length of longest increasing subsequence.
    
    //mydpmemo gives TLE
    // int dpmemo(int i,int a[],int limit, vector<vector<int>> &dp){
    //     if(i==0){
    //      if(a[i]<a[limit])
    //      return 1;
         
    //      else
    //      return 0;
    //      }
         
    //      if(dp[i][limit+1]!=-1)
    //      return dp[i][limit+1];
         
    //      int take=0;
    //      if(limit==-1 || a[i]<a[limit])
    //      take=1+dpmemo(i-1,a,i,dp);
         
    //      int notTake=0+dpmemo(i-1,a,limit,dp);
         
    //      return dp[i][limit+1]=max(take,notTake);
    // }
    
    
    int dpmemo(int i,int a[],int prev_index, vector<vector<int>> &dp,int n){
        if(i==n){
        return 0;
         }
         
         if(dp[i][prev_index+1]!=-1)
         return dp[i][prev_index+1];
         
         int len;
         
         len=0+dpmemo(i+1,a,prev_index,dp,n);
         
         int take=0;
         if(prev_index==-1 || a[i]>a[prev_index])
         len=max(1+dpmemo(i+1,a,i,dp,n),len);
         
         
         
         return dp[i][prev_index+1]=len;
    }
    
    int longestSubsequence(int n, int a[])
    {
    //     vector<vector<int>> dp(n,vector<int>(n+1,-1));
    //   return dpmemo(0,a,-1,dp,n); 
       
       vector<vector<int>> dp(n+1,vector<int>(n+1,0));
       
       for(int i=n-1;i>=0;i--){
           for(int prev_index=i-1;prev_index>=-1;prev_index--){
               
                int len;
         
         len=0+dp[i+1][prev_index+1];
         
         //int take=0;
         if(prev_index==-1 || a[i]>a[prev_index])
         len=max(1+dp[i+1][i+1],len); //i+1 is eesential here for prev_index
         
         
         
         dp[i][prev_index+1]=len;
           }
       }
       
       return dp[0][0];
       
    }

//non-dp working soln
int opti2(int n,int a[]){
        vector<int>ans;
        ans.push_back(a[0]);
        for(int i=1;i<n;i++){
            if(a[i]>ans.back())ans.push_back(a[i]);
            else{
                int index=lower_bound(ans.begin(),ans.end(),a[i])-ans.begin();
                ans[index]=a[i];
            }
        }
        return ans.size();
             }
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // return solve(n,a,0,-1,dp);
        //return opti(n,a);
        return opti2(n,a);
        
    }
