//memo and tabulation
class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    
    int dpmemo(int i,int j,string s1, string s2,vector<vector<int>> &dp){
        if(i<0 || j<0){
              return 0;
            
        }
        
        if(dp[i][j]!=-1)
        return dp[i][j];
       
        if(s1[i]==s2[j])
        return dp[i][j]=(1 + dpmemo(i-1,j-1,s1,s2,dp));
        
        else
        return dp[i][j]=max(dpmemo(i-1,j,s1,s2,dp),dpmemo(i,j-1,s1,s2,dp));
        
      
    }
    int lcs(int n, int m, string s1, string s2)
    {  //vector<vector<int>> dp(n,vector<int>(m,-1)); //for memoisation
         //return dpmemo(n-1,m-1,s1,s2,dp);
       vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
   //for base-case we shift every index by 1 towards right hence no more i<0||j<o  but i==0||j==0
   
   for(int i=0;i<n;i++)
   dp[i][0]=0;
   
   for(int i=0;i<m;i++)
   dp[0][i]=0;
   
       for(int i=1;i<=n;i++){
           for(int j=1;j<=m;j++){
              //copy-recursion
              if(s1[i-1]==s2[j-1])
               dp[i][j]=1 + dp[i-1][j-1];
        
             else
               dp[i][j]=max(dp[i-1][j],dp[i][j-1]); 
           }
       }
       
       return dp[n][m];
    }
};

//Space-optimise
int lcs(int n, int m, string s1, string s2)
    {  
       vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
   //for base-case we shift every index by 1 towards right hence no more i<0||j<o  but i==0||j==0
   
   vector<int> prev(m+1,0),cur(m+1,0); //m+1 coz prev represents columns in row and so does m, n represents rows
   
   for(int i=0;i<=m;i++)
   prev[i]=0;
   

   
   
       for(int i=1;i<=n;i++){
           for(int j=1;j<=m;j++){
              //copy-recursion
              if(s1[i-1]==s2[j-1])
               cur[j]=1 + prev[j-1];
        
             else
               cur[j]=max(prev[j],cur[j-1]); 
           }
           
           prev=cur;
       }
       
       return prev[m];
    }
