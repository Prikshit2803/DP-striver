// original copied soln
 // vector<int> dp(n,0);
       // dp[0]=arr[0];
      int prev1=0;
       int prev2=arr[0];
       
        int incl,excl,ans;
        for(int i=1;i<n;i++){
          ///incl=dp[i-2]+arr[i];
         // excl=dp[i-1];
         // dp[i]=max(incl,excl);
         incl=prev1+arr[i];
         excl=prev2;
         ans=max(incl,excl);
         prev1=prev2;
         prev2=ans;
        }
        
        return prev2;


// the problem is same as max sum of non-adjacent elements
//problem link : https://bit.ly/3QOMRs1
// space optimised approach
class Solution
{
    
    
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
      // same as max sum of non-adjacent elements
      // directly riting space optimised approach
      vector<int> dp(n,-1);
      
      int prev1=arr[0];
      
      int prev=0;
      
      int cur;
       
      for(int i=1;i<n;i++){
          
          int pick = arr[i];
          
          if(i>1)// from striver : this is for case when i=1 and we pick it hence i-2=-1 we get negative number
          pick+=prev;
          
          
          int notpick=0 + prev1;
          
          cur=max(pick,notpick);
          
          prev=prev1;
          prev1=cur;
      }
      
      return prev1;
    }
};
