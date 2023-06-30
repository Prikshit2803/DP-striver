//Recursive(DFS) soln : TLE
class Solution
{
    public:
    int cnt=0;
    
    void dfs(int i,int j,int a,int b){
        if(i<0||i>a||j<0||j>b)
        return;
        
        if(i==a && j==b){
            cnt++;
            return;
        }
        
        
        dfs(i+1,j,a,b);
        dfs(i,j+1,a,b);
    }
    int NumberOfPath(int a, int b)
    {
     dfs(0,0,a-1,b-1);
     
     return cnt;
    }
};

// Memoisation
 int  dpmemo(int i,int j,vector<vector<int>> &dp){
       
       if(i==0 && j==0)
       return 1;
       
       if(i<0||j<0)
        return 0;
       
       
        if(dp[i][j]!=-1)
        return dp[i][j];
        
       dp[i][j]= dpmemo(i-1,j,dp) + dpmemo(i,j-1,dp);
       
       return dp[i][j];
        
    }
    int NumberOfPath(int a, int b)
    {
    
     
     vector<vector<int>> dp(a,vector<int>(b,-1));
     
      return dpmemo(a-1,b-1,dp);
    
    }


//Tabulation

    int NumberOfPath(int a, int b)
    {
    
     
     vector<vector<int>> dp(a,vector<int>(b,-1));
     
     // return dpmemo(a-1,b-1,dp);
     
     
     dp[0][0]=1;
     //dp[1][0]=1;
     //dp[0][1]=1;
     
     for(int i=0;i<a;i++){
         for(int j=0;j<b;j++){
            
            if(i==0 && j==0)
            continue;
                
                if(i==0 ){
                    dp[i][j]=dp[i][j-1] + 0;
                }
                
                else if(j==0 ){
                    dp[i][j]=dp[i-1][j] + 0;
                }
                
               else{
                   dp[i][j]=dp[i-1][j] + dp[i][j-1];
               } 
            }
         }
     
    
    return dp[a-1][b-1];
    }


//space-optimisation
int NumberOfPath(int a, int b)
    {
    
     
    
    
    vector<int> dp(b,0);  //it maintains previous row
     for(int i=0;i<a;i++){
         
         vector<int> temp(b,0);
         for(int j=0;j<b;j++){
            
            if(i==0 && j==0){
                temp[j]=1;
            }
            
            else{
                
                if(i==0 ){
                    temp[j]=temp[j-1] + 0; // only left we can go
                }
                
                else if(j==0 ){
                    temp[j]=dp[j] + 0; // as only up we can go
                }
                
               else{
                   temp[j]=temp[j-1] + dp[j];
               } 
               
              
            }
            
            
            
         }
         dp=temp;
     }
    
    return dp[b-1];
    }


