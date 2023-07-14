//length minus longest common subsequnce will give shortest supersequence as it avoids repetition
//similar  as minimum insertions and deletions
class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string str1, string str2, int n, int m)
    {
        
       
       vector<vector<int>> dp(n+1,vector<int>(m+1,0)); 
       
       for(int i=1;i<=n;i++){
           for(int j=1;j<=m;j++){
               if(str1[i-1]==str2[j-1])
               dp[i][j]=1 + dp[i-1][j-1];
               
               else
               dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
           }
       }
	    
	    return (m+n)- dp[n][m];
    }
};
