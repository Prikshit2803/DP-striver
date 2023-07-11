//Tabulation and Memoisation
class Solution {
  public:
  
  int dpmemo(int i,int j1,int j2,vector<vector<int>>& grid, vector<vector<vector<int>>> &dp,int n,int m){
  
  if(j1<0||j1>=m||j2<0||j2>=m)
  return -1e8; //not INT_MIN as when added to -ve number it can go out of bounds
  
  if(i==n-1){
      if(j1==j2)
      return grid[i][j1];
      
      else
      return grid[i][j1] + grid[i][j2]; 
      
  }
  
  if(dp[i][j1][j2]!=-1){
      return dp[i][j1][j2];
  }
  
  int maxi=-1e8;
  for(int dj1=-1;dj1<=1;dj1++){
      for(int dj2=-1;dj2<=1;dj2++){
          int val=0;
          if(j1==j2)//this is crucial
         val= grid[i][j1] + dpmemo(i+1,j1+dj1,j2+dj2,grid,dp,n,m);
          
          else
       val= grid[i][j1] + grid[i][j2] + dpmemo(i+1,j1+dj1,j2+dj2,grid,dp,n,m);
       
       maxi=max(maxi,val);
      }
  }
   
   return dp[i][j1][j2]=maxi;  
   
  }
    int solve(int n, int m, vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        
        //return dpmemo(0,0,m-1,grid,dp,n,m);
        
        //Now,Tabulation
       for(int j1=0;j1<m;j1++){
              for(int j2=0;j2<m;j2++){
                  if(j1==j2)
                  dp[n-1][j1][j2]=grid[n-1][j1];
                  else
                  dp[n-1][j1][j2]=grid[n-1][j1] + grid[n-1][j2];
              }
       }
       //explore every path
       for(int i=n-2;i>=0;i--){
           for(int j1=0;j1<m;j1++){
              for(int j2=0;j2<m;j2++){
                  //copy from memoisation
                  int maxi=-1e8;
  for(int dj1=-1;dj1<=1;dj1++){
      for(int dj2=-1;dj2<=1;dj2++){
          int val=0;
          if(j1==j2) {//this is crucial
          
          if(j1+dj1>=0 && j1+dj1<m && j2+dj2>=0 && j2+dj2<m)
         val= grid[i][j1] + dp[i+1][j1+dj1][j2+dj2];
         else
         val=grid[i][j1];
         
          }
          
          else{
          if(j1+dj1>=0 && j1+dj1<m && j2+dj2>=0 && j2+dj2<m)     
      val= grid[i][j1] + grid[i][j2] + dp[i+1][j1+dj1][j2+dj2];
      else
        val=grid[i][j1]+grid[i][j2];
          }
          
        //   if(j1+dj1>=0 && j1+dj1<m && j2+dj2>=0 && j2+dj2<m)
        //   val+=dp[i+1][j1+dj1][j2+dj2];
           
        //   else
        //   val+=-1e8; //this approach also works
       
       maxi=max(maxi,val);
      }
  }
  
  dp[i][j1][j2]=maxi;  
              }
           }
       }
       
       return dp[0][0][m-1];
    }
};


//Space-optimisation
class Solution {
  public:
  
  int dpmemo(int i,int j1,int j2,vector<vector<int>>& grid, vector<vector<vector<int>>> &dp,int n,int m){
  
  if(j1<0||j1>=m||j2<0||j2>=m)
  return -1e8; //not INT_MIN as when added to -ve number it can go out of bounds
  
  
  if(i==n-1){
      if(j1==j2)
      return grid[i][j1];
      
      else
      return grid[i][j1] + grid[i][j2]; 
      
  }
  
  if(dp[i][j1][j2]!=-1){
      return dp[i][j1][j2];
  }
  
  int maxi=-1e8;
  for(int dj1=-1;dj1<=1;dj1++){
      for(int dj2=-1;dj2<=1;dj2++){
          int val=0;
          if(j1==j2)//this is crucial
         val= grid[i][j1] + dpmemo(i+1,j1+dj1,j2+dj2,grid,dp,n,m);
          
          else
       val= grid[i][j1] + grid[i][j2] + dpmemo(i+1,j1+dj1,j2+dj2,grid,dp,n,m);
       
       maxi=max(maxi,val);
      }
  }
   
   return dp[i][j1][j2]=maxi;  
   
  }
    int solve(int n, int m, vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        
        //return dpmemo(0,0,m-1,grid,dp,n,m);
        
        vector<vector<int>> front(m,vector<int>(m,-1)),cur(m,vector<int>(m,-1));
        
        //Now,Tabulation and space optimise
       for(int j1=0;j1<m;j1++){
              for(int j2=0;j2<m;j2++){
                  if(j1==j2)
                  front[j1][j2]=grid[n-1][j1];
                  else
                  front[j1][j2]=grid[n-1][j1] + grid[n-1][j2];
              }
       }
       //explore every path
       for(int i=n-2;i>=0;i--){
           for(int j1=0;j1<m;j1++){
              for(int j2=0;j2<m;j2++){
                  //copy from memoisation
                  int maxi=-1e8;
  for(int dj1=-1;dj1<=1;dj1++){
      for(int dj2=-1;dj2<=1;dj2++){
          int val=0;
          if(j1==j2) {
         val=grid[i][j1];
         
          }
          
          else{
        val=grid[i][j1]+grid[i][j2];
          }
          
          if(j1+dj1>=0 && j1+dj1<m && j2+dj2>=0 && j2+dj2<m)
          val+=front[j1+dj1][j2+dj2];
           
          else
          val+=-1e8; 
       
       maxi=max(maxi,val);
      }
  }
  
  cur[j1][j2]=maxi;  
              }
           }
           
           front=cur;
       }
       
       return front[0][m-1];
    }
};
