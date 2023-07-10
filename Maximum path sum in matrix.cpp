//Memoisation and Tabulatiom
class Solution{
public:

int dpmemo(int i,int j,int n,vector<vector<int>> matrix,vector<vector<int>> &dp){
    
    if(j<0 ||  j>=n)
    return -1e9;
    
    if(i==0)
    return matrix[i][j];
    
    if(dp[i][j]!=-1)
    return dp[i][j];
    
    
        
       int maxi=0;
        
            int up=matrix[i][j] + dpmemo(i-1,j,n,matrix,dp);
            int dr=matrix[i][j] + dpmemo(i-1,j+1,n,matrix,dp);
            int dl=matrix[i][j] + dpmemo(i-1,j-1,n,matrix,dp);
            
            maxi=max(up,max(dr,dl));
            
            return dp[i][j]= maxi;
        
        
   // }
    
}
    int maximumPath(int n, vector<vector<int>> matrix)
    {
       vector<vector<int>> dp(n,vector<int>(n,-1));
       int maxi=-1e8;
       
       
     // Memoisation  
    //   for( int k=0;k<n;k++){
    //       int mp= dpmemo(n-1,k,n,matrix,dp);
    //       maxi=max(maxi,mp);
    //   }
    
    
    //tabulation
      for( int k=0;k<n;k++){
          dp[0][k]=matrix[0][k];
      }
       
       
       for(int i=1;i<n;i++){
           for(int j=0;j<n;j++){
            int up=matrix[i][j] + dp[i-1][j];
         int dr=matrix[i][j];
         if(j+1<n)    dr += dp[i-1][j+1];
         else dr=-1e9;
         
         int dl=matrix[i][j];
          if(j-1>=0)  dl+=dp[i-1][j-1];
          else
          dl+=-1e9;
          
          
          dp[i][j]=max(up,max(dl,dr));
           }
       }
       
      // int maxi=-1e9;
        
       for( int k=0;k<n;k++){
          maxi=max(maxi,dp[n-1][k]);
      }
      
       return maxi;
       
    }
};


//Space optimisation using two vector arrays
  int maximumPath(int n, vector<vector<int>> matrix)
    {
       vector<vector<int>> dp(n,vector<int>(n,-1));
       int maxi=-1e8;
       
       
     // Memoisation  
    //   for( int k=0;k<n;k++){
    //       int mp= dpmemo(n-1,k,n,matrix,dp);
    //       maxi=max(maxi,mp);
    //   }
    
    
    //tabulation and space optimisation
    vector<int> prev(n,-1),cur(n,-1);
      for( int k=0;k<n;k++){
          prev[k]=matrix[0][k];
      }
       
      if(n==1)
      return matrix[0][0];
       
       for(int i=1;i<n;i++){
           for(int j=0;j<n;j++){
            int up=matrix[i][j] + prev[j];
         int dr=matrix[i][j];
         if(j+1<n)    dr += prev[j+1];
         else dr=-1e9;
         
         int dl=matrix[i][j];
          if(j-1>=0)  dl+=prev[j-1];
          else
          dl+=-1e9;
          
          
          cur[j]=max(up,max(dl,dr));
           }
           prev=cur;
       }
       
      // int maxi=-1e9;
        
       for( int k=0;k<n;k++){
          maxi=max(maxi,cur[k]);
      }
      
       return maxi;
       
    }
};
