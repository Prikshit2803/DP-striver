// Memoisation : TLE

class Solution{
public:	
	// calculate the maximum sum with out adjacent
	
	int dpmemo(int n,int *arr,vector<int> &dp){
	   // if(n==0)
	   // return arr[0];
	    
	   // if(n==1)
	   // return max(arr[0], arr[1]);  this is my way and it works
	   
	   //striver way
	   
	   if(n==0)
	   return arr[0];
	   
	   if(n<0)
	   return 0;
	    
	    if(dp[n]!=INT_MIN)
	    return dp[n];
	    
	    
	    
	   //     for(int i=n-2;i>=0;i--){
	   //       dp[n]=max((dpmemo(i,arr,dp) + arr[n]),dp[n]);  
	        
	   // } doesn't work
	   
	   
	   int pick=arr[n] + dpmemo(n-2,arr,dp);
	   int notpick = 0 + dpmemo(n-1,arr,dp);
	    
	    return max(pick,notpick);
	}
	int findMaxSum(int *arr, int n) {
	   vector<int> dp(n,INT_MIN);
	   
	   //if(n==1)//number of elements
	   // return arr[0];
	    
	   // if(n==2)
	   // return max(arr[0], arr[1]);
	   
	  return dpmemo(n-1,arr,dp);
	   
	  
	}
};


// Tabulation : works

	int findMaxSum(int *arr, int n) {
	   vector<int> dp(n,INT_MIN);
	   


       dp[0]=arr[0];
       dp[1]=max(arr[0],arr[1]); // we do this coz if n=1 we either take 1 and do n-2 which is negative hence e consider that as nothing(0) or else we not take 1 and take element at index 0 amd the max of these is the answer
       
       for(int i=2;i<n;i++){
           int pick = arr[i] + dp[i-2];
           int notpick = 0 + dp[i-1];
           
           dp[i]=max(pick,notpick);       
           
       }

//space optimisation
    	int findMaxSum(int *arr, int n) {
	   vector<int> dp(n,INT_MIN);
	   
    if(n==1)
    return arr[0];
    
    if(n==2)
    return max(arr[0],arr[1]);
 
       int prev2=arr[0];
      int  prev1=max(arr[0],arr[1]);
       int cur;
       
       for(int i=2;i<n;i++){
           int pick = arr[i] + prev2;
           int notpick = 0 + prev1;
           
           cur=max(pick,notpick); 
           
           prev2=prev1;
           prev1=cur;
           
           
           
       }
	   
	  return prev1;
	}
	   
	  return dp[n-1];
	}
