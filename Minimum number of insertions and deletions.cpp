class Solution{
		
//find number of deletions in total apart from longest common subsequence
	public:
	int minOperations(string str1, string str2) 
	{ 
	   
       
       int n=str1.length();
       int m=str2.length();
       
       vector<vector<int>> dp(n+1,vector<int>(m+1,0)); 
       
       for(int i=1;i<=n;i++){
           for(int j=1;j<=m;j++){
               if(str1[i-1]==str2[j-1])
               dp[i][j]=1 + dp[i-1][j-1];
               
               else
               dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
           }
       }
	    
	    return (n+m)- 2*dp[n][m];
	} 
};
