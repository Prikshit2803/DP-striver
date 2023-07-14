// A Palindrome reads same from the front and back.

//Hence, longest palindromic subsequence is nothing but the 
//longest common subsequence in S and reverse (S).

class Solution{
  public:
    int longestPalinSubseq(string A) {
       //right-shift index such that -1 becomes 0;
       
       string rev = string(A.rbegin(), A.rend()); //reverses string
       
       int n=A.length();
       int m=rev.length();
       
       vector<vector<int>> dp(n+1,vector<int>(m+1,0)); 
       
       for(int i=1;i<=n;i++){
           for(int j=1;j<=n;j++){
               if(A[i-1]==rev[j-1])
               dp[i][j]=1 + dp[i-1][j-1];
               
               else
               dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
           }
       }
       
       return dp[n][m];
    }
};
