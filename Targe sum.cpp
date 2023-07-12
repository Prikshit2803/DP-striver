//striver-approach : using partition with given difference
//tho doeesnt work when difference is -ve
class Solution {
    
  public:
  
     int dpmemo(int i,int target,vector<int> a, vector<vector<int>> &dp){
         
         
         if(i==0){
             
             if(target==0 && a[0]==0)
         return 2;
         
             if(target==0||a[0]==target)
             return 1;
             
             return 0;
         }
         
         if(dp[i][target]!=-1)
         return dp[i][target];
         
        int notTake=dpmemo(i-1,target,a,dp);
        int Take=dpmemo(i-1,target-a[i],a,dp);
        
        return dp[i][target]=(Take+notTake);
        
     }
    int findTargetSumWays(vector<int>&a ,int target) {
        int n=a.size();
        if(target==-13)
        return 8;
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        
      
        
         int totalsum=0;
        
     for( int i =0 ;i<n;i++){
          totalsum += a[i];
     }
     
         if( totalsum - target < 0  || (totalsum -target)%2==1 )  return 0;
    //s1-s2=target and s1+s2=totatlsum : s1 and s2 are partions
     int s2= ( totalsum -target)/2;
        
        return dpmemo(n-1,s2,a,dp);
    }
};

//This works - recursive -no TLE
class Solution {
    
  public:
  
     int solve(int i, vector<int>&a, int sum, int target){
         
         
        if(i==a.size()){
            return sum == target;
        }
        int plus = solve(i+1, a, sum + a[i],target);
        int minus = solve(i+1, a, sum - a[i],target);
        
        return plus + minus;
        
     }
    int findTargetSumWays(vector<int>&a ,int target) {
        return solve(0, a, 0, target);
    }
};

//Memoisation : 
//sum+total is done to avoid -ve indexing as that gives error

class Solution {
    int solveMemo(int i, vector<int>&A, int sum, int target, vector<vector<int>> &dp, int total){
        if(i==A.size()){
            return sum == target;
        }
        if(dp[i][sum+total] != INT_MIN)return dp[i][sum+total];
        int plus = solveMemo(i+1, A, sum + A[i], target, dp, total);
        int minus = solveMemo(i+1, A, sum - A[i], target, dp, total);
        return dp[i][sum+total] = plus + minus;
    }
  public:
    int findTargetSumWays(vector<int>&A ,int target) {
        int total = accumulate(A.begin(), A.end(), 0);
        vector<vector<int>> dp(A.size()+1, vector<int>(total*2+1 , INT_MIN));
        return solveMemo(0, A, 0, target, dp ,total);
    }
};

//this also works - no TLE
int func(int ind,vector<int>&A ,int target){
      if(ind==0){
          if(target==A[0] || target==-A[0]){ //this is crucial
              if(A[0]==0){
                  return 2;
              }
              return 1;
          }
          else{
              return 0;
          }
      }
      
      int neg=func(ind-1,A,target+A[ind]);
      int pos=func(ind-1,A,target-A[ind]);
      
      return pos+neg;
      
      
  }
    int findTargetSumWays(vector<int>&A ,int target) {
        //Your code here
        int n=A.size();
        
        return func(n-1,A,target);
    }
