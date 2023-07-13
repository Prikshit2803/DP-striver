class Solution{
    public:
    
    
    int longestCommonSubstr (string s1, string s2, int n, int m)
    { 
        //use LCS tabulation and print LCS table concept
    
        //avoid recursion as it would need 3 variables
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0)); //this covers base case where i==0||j===0 return 0
        
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                
                if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
                ans=max(ans,dp[i][j]);
                }
                
                else
                dp[i][j]=0;
            }
        }
       
       return ans; 
    }
};
