// the string length minus The longest common subsequence of string with reverse of itself(longest patlindromic subsequence)
//it forms the answer
class Solution{
  public:
    int countMin(string str){
  
  
   
       string rev = string(str.rbegin(), str.rend()); //reverses string
       
       int n=str.length();
       int m=rev.length();
       
       vector<vector<int>> dp(n+1,vector<int>(m+1,0)); 
       
       for(int i=1;i<=n;i++){
           for(int j=1;j<=n;j++){
               if(str[i-1]==rev[j-1])
               dp[i][j]=1 + dp[i-1][j-1];
               
               else
               dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
           }
       }
       
       return n-dp[n][m];
    }
};
