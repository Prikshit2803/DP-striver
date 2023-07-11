class Solution{   
public:

bool dpm(int i,vector<int>&arr, int sum,int k,vector<int> &dp,int n){
    if(i>=n)
    return false;
    
    if(k==sum)
    return true;
    
    if(k>sum)
  return false;
   

   
   
   
  bool a=dpmemo(i+1,arr,sum,k+arr[i],dp,n);
  bool b=dpmemo(i+1,arr,sum,k,dp,n);
   
  if(a||b){
      
     return true;
  }
  
   
  else{
         
     return false;
  }
   
   
} //my recursion soln and it works but gives TLE
    
    
    bool dpmemo(int i,vector<int>&arr, int target,vector<vector<int>>  &dp){
    if(target==0)
    return true;
    
    if(i==0){
    if(arr[0]==target)
    return true;
    
    else
    return false;
    }
    
  
   
  if(dp[i][target]!=-1){  //all this can be cut short to : return dp[i][target]
      if(dp[i][target]==1)
      return true;
       
      else if(dp[i][target]==0)    
      return false;
  }
   
   
   
   bool notTake=dpmemo(i-1,arr,target,dp);
   bool Take=false;
   
   if(target>=arr[i])
   Take=dpmemo(i-1,arr,target-arr[i],dp);
   
   if(Take||notTake){   // both if else can be shortened to : dp[i][target]=take||notTake;
       dp[i][target]=1;
     return true;
   }
  
   
   else{
          dp[i][target]=0;
     return false;
   }
   
   
}

    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
         // vector<vector<int>> dp(n,vector<int>(sum+1,0)); //this is for memo //sum+1 is essential to do or else dp goes out of bounds for dp[i][target]
          vector<vector<bool>> dp(n,vector<bool>(sum+1,0));
         // return dpmemo(n-1,arr,sum,dp);
         
         //tabulation
         for(int i=0;i<n;i++) //base case
         dp[i][0]=true;
         
         dp[0][arr[0]]=true; //if 0th element is target
         
         //explore every path
         for(int i=1;i<n;i++){
             for(int target=0;target<=sum;target++){
                 
                 //copy recursion
                 
                  bool notTake=dp[i-1][target];
                   bool Take=false;
   
                   if(target>=arr[i])
                 Take=dp[i-1][target-arr[i]];
   
                  dp[i][target]=(Take||notTake);
                     
  
   
                         
             }
         }
          
          return dp[n-1][sum];
    }
};


//Space-Optimisation
bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
         // vector<vector<int>> dp(n,vector<int>(sum+1,0)); //this is for memo //sum+1 is essential to do or else dp goes out of bounds for dp[i][target]
          vector<vector<bool>> dp(n,vector<bool>(sum+1,0));
         // return dpmemo(n-1,arr,sum,dp);
         
         if(n==1)
         return (arr[0]==sum);
         
         
         vector<bool> prev(sum+1,0),cur(sum+1,0);
         //tabulation and space optimise
        
         prev[0]=true;
         
         prev[arr[0]]=true; //if 0th element is target
         
         //explore every path
         for(int i=1;i<n;i++){
             for(int target=0;target<=sum;target++){
                 
                 //copy recursion
                 
                  bool notTake=prev[target];
                   bool Take=false;
   
                   if(target>=arr[i])
                 Take=prev[target-arr[i]];
   
                  cur[target]=(Take||notTake);
                     
  
   
                         
             }
             
             prev=cur;
             prev[0]=true;
         }
          
          return prev[sum];
    }
};
