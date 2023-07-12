//Using subset-sum equal to target and concept that recursion returns sum
//people trying out Striver's solution, listen -> his soln wont work here since there are zeroes in the input and in his soln,
//whenever target reaches zero, it is assumed as base case, so zeroes wont get considered in the soln.

Just cleverly modify the base case
class Solution{

	public:
	
	int mod = 1e9 + 7;
	
	int dprec(int i,int arr[],int target){
	   // if(target==0)
	   // return 1; //we dont do this as we let it go to base case then return 
	    
	    if(i==0){
	         if(target==0 && arr[0]==0) 
                return 2;
	      
	      if(target==0 || target==arr[0]) 
                return 1; 
                
                return 0;
	    }
	    
	    
	    int notTake=dprec(i-1,arr,target);
	    int Take=0;
	    if(target>=arr[i])
	    Take=dprec(i-1,arr,target-arr[i]);
	    
	    return (Take + notTake);
	    
	}
	
		int dpmemo(int i,int arr[],int target ,vector<vector<int>> &dp){
	   // if(target==0)
	   // return 1; //we dont do this as we let it go to base case then return 
	    
	    if(i==0){
	         if(target==0 && arr[0]==0) 
                return 2;
	      
	      if(target==0 || target==arr[0]) 
                return 1; 
                
                return 0;
	    }
	    
	    
	    if(dp[i][target]!=-1){
	        return dp[i][target];
	    }
	    
	    
	    int notTake=dpmemo(i-1,arr,target,dp);
	    int Take=0;
	    if(target>=arr[i])
	    Take=dpmemo(i-1,arr,target-arr[i],dp);
	    
	    return  dp[i][target]=(Take + notTake)%mod; //mod is important to do
	    
	}
	
	
	
	int perfectSum(int arr[], int n, int sum)
	{
	    //vector<vector<int>> dp(n,vector<int>(sum+1,-1)); //for memoisation
	    vector<vector<int>> dp(n,vector<int>(sum+1,0));
       // return dpmemo(n-1,arr,sum,dp);
       
       //Tabulation
       
       //base-case
       for(int i=0;i<n;i++){
           dp[i][0]=1;
       }
       
       if(arr[0]==0)
        dp[0][arr[0]]=2;
        
      else
      dp[0][arr[0]]=1; //it means when i=0  the element is equal to target
       
       
       //explore every path
       for(int i=1;i<n;i++){
           for(int target=0;target<=sum;target++){
               //copy-recursion
                 int notTake=dp[i-1][target];
	    int Take=0;
	    if(target>=arr[i])
	    Take=dp[i-1][target-arr[i]];
	    
	     dp[i][target]=(Take + notTake)%mod;
           }
       }
       
        return dp[n-1][sum];
        
	}
	  
};

//space-optimisation
		int perfectSum(int arr[], int n, int sum)
	{
	     vector<int> prev(sum+1,0),cur(sum+1,0);
       
      //base-case
       
       if(arr[0]==0)
        prev[0]=2;
        
      else
      prev[0]=1; //it means when i=0  the element is equal to target
      
      if(arr[0]!=0 && arr[0]<=sum) prev[arr[0]]=1;
       
       
       //explore every path
       for(int i=1;i<n;i++){
           for(int target=0;target<=sum;target++){
               //copy-recursion
                 int notTake=prev[target];
	    int Take=0;
	    if(target>=arr[i])
	    Take=prev[target-arr[i]];
	    
	       cur[target]=(Take + notTake)%mod;
           }
           
           prev=cur;
    
         }
         
          
        
       
       
        return prev[sum];
        
	}
	  
};

//working-space optimisation
class Solution{

	public:
	
	int perfectSum(int arr[], int n, int sum)
	{
	    //to handle 0's
	    sort(arr, arr+n);
	    
	    //space optimisation
	    vector<int> curr(sum + 1, 0);
	    vector<int> next(sum + 1, 0);
	    
	    //base case anbalysis
	    next[0] = 1;
	    curr[0] = 1;
	    
	    int MOD = 1e9 + 7;
	    
	    //tabulation part
	    for(int index = n-1; index >= 0; index--){
	        
	        for(int target = 1; target <= sum; target++){
	            
	            int include = 0;
	            if(target - arr[index] >= 0)
	                include = next[target - arr[index]] % MOD;
	                
	            int exclude = next[target] % MOD;
	    
	            curr[target] = (include + exclude) % MOD;
	        }
	        next = curr;
	    }
	    return next[sum];
	}
	  
};
