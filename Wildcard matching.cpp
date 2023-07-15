class Solution{
  public:
/*You are required to complete this method*/

    int dpmemo(int i,int j,string pattern,string str, vector<vector<int>> &dp){
        if(i<0 && j<0 || i<0 && pattern[0]=='*')
        return 1;
        
        if(j<0)
        return 0;
        
        if(i<0 )
        return 0;
        
        if(dp[i][j]!=-1)
        return dp[i][j];
        
        if(pattern[j]=='?')
        return dp[i][j]=dpmemo(i-1,j-1,pattern,str,dp);
        
        
        else  if(pattern[j]=='*')
        return dp[i][j]=((dpmemo(i-1,j-1,pattern,str,dp)||dpmemo(i-1,j,pattern,str,dp))||dpmemo(i,j-1,pattern,str,dp));
        
        
       else if(pattern[j]==str[i])
        return dp[i][j]= dpmemo(i-1,j-1,pattern,str,dp);
        
        else if(pattern[j]!=str[i])
        return dp[i][j]=0;
        
    }
    int wildCard(string pattern,string str)
    {
       
        int m=pattern.length();
        int n=str.length();
        
         //vector<vector<int>> dp(n,vector<int>(m,-1)); //for memoisation
        
       // return dpmemo(n-1,m-1,pattern,str,dp);
       
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        //right-shift index where -1 becomes 0
        //base-case
        
        dp[0][0]=1;
        
        for(int i=1;i<=m;i++){
            int flag=1;
            
            for(int k=1;k<=i;k++){
                if(pattern[k-1]!='*'){
                    flag=0;
                    break;
                }
            }
            
            dp[0][i]=flag;
        }
        
        //explore every possibility
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                
                //copy-recursion
                
                 if(pattern[j-1]=='?' || pattern[j-1]==str[i-1])
                  dp[i][j]=dp[i-1][j-1];
        
        
        else  if(pattern[j-1]=='*')
        dp[i][j]= dp[i-1][j]||dp[i][j-1] ;
        
        
        else
            dp[i][j]=0;
                
            }
        }
        
        return dp[n][m];    
        
    }
};
