//Combines find partition with given sum and mainly find number of subsets with sum k
class Solution {
  public:
  int mod=1e9+7;
    int countPartitions(int n, int d, vector<int>& arr) {
        
        int totsum=0;
        for(int i=0;i<n;i++)
        totsum+=arr[i];
        
        vector<vector<int>> dp(n,vector<int>(totsum+1,0));
        
        
      
      if(totsum-d<0)
      return 0;
      
      if((totsum-d)%2!=0) //has to be even , not sure why tho
      return 0;
       
       int s2=(totsum-d)/2;
       int s1=totsum-s2; //s1>=s2 , hence now we just find subsets with sum s2
       
      for(int i=0;i<n;i++){
           dp[i][0]=1;
       }
       
       if(arr[0]==0)
        dp[0][arr[0]]=2;
        
      else
      dp[0][arr[0]]=1; //it means when i=0  the element is equal to target
       
       
       //explore every path
       for(int i=1;i<n;i++){
           for(int target=0;target<=s2;target++){
               //copy-recursion
                 int notTake=dp[i-1][target];
	    int Take=0;
	    if(target>=arr[i])
	    Take=dp[i-1][target-arr[i]];
	    
	     dp[i][target]=(Take + notTake)%mod;
           }
       }
       
      
       
      
       
        return dp[n-1][s2];
        
	
    }
};

//Space-Optimised
class Solution {
  public:
  int mod=1e9+7;
    int countPartitions(int n, int d, vector<int>& arr) {
        
        int totsum=0;
        for(int i=0;i<n;i++)
        totsum+=arr[i];
        
        vector<vector<int>> dp(n,vector<int>(totsum+1,0));
        
        
        
      
      if(totsum-d<0)
      return 0;
      
      if((totsum-d)%2!=0) //has to be even , not sure why tho
      return 0;
       
       int s2=(totsum-d)/2;
       int s1=totsum-s2; //s1>=s2 , hence now we just find subsets with sum s2
       
    //   for(int i=0;i<n;i++){
    //       dp[i][0]=1;
    //   }
       
       vector<int> prev(s2+1,0),cur(s2+1,0);
       
       if(arr[0]==0)
        prev[arr[0]]=2;
        
      else
      prev[0]=1; 
      
      if(arr[0]!=0 && arr[0]<=s2) prev[arr[0]]=1;
       
       
       //explore every path
       for(int i=1;i<n;i++){
           for(int target=0;target<=s2;target++){
               //copy-recursion
                 int notTake=prev[target];
	    int Take=0;
	    if(target>=arr[i])
	    Take=prev[target-arr[i]];
	    
	     cur[target]=(Take + notTake)%mod;
           }
           prev=cur;
       }
       
      
       
      
       
        return prev[s2];
        
	
    }
};
