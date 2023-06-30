// same as number of unique paths in a grid except one base condition is added
class Solution {
  public:
  //soln almost same as grid unique paths
    int totalWays(int n, int m, vector<vector<int>>& grid) {
        vector<int> dp(m,0);  //it maintains previous row
        
        int t=1000000007;
        
        if(n==1 && m==1)
        if(grid[n-1][m-1]==1)
        return 0;
        
        
     for(int i=0;i<n;i++){
         
         vector<int> temp(m,0);
         for(int j=0;j<m;j++){
            
            if(i==0 && j==0){
                temp[j]=1;
            }
            
            else if(i>=0 && j>=0 && grid[i][j]==1){ //just this condition e add
                temp[j]=0;
            }
            else{
                
                if(i==0 ){
                    temp[j]=temp[j-1]%t + 0; // only left we can go
                }
                
                else if(j==0 ){
                    temp[j]=dp[j]%t + 0; // as only up we can go
                }
                
               else{
                   temp[j]=(temp[j-1]%t + dp[j]%t)%t;
               } 
               
              
            }
            
            
            
         }
         dp=temp;
     }
    
    return dp[m-1]%t;
    }
};
