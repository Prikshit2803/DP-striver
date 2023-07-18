//sorting ans applying print LIS so it becomes Longest divisible subsequence
    vector<int> LargestSubset(int n, vector<int>& arr) {
     sort(arr.begin(),arr.end());
     
     vector<int> dp(n,1),hash(n,0);
     
     int maxi=0,lastindex=0;
     
     
     for(int i=1;i<n;i++){
         hash[i]=i;
         for(int prev=0;prev<i;prev++){
             if(arr[i]%arr[prev]==0 && 1+dp[prev]>dp[i])       //a[i]%a[j]==0 this coz array is sorted
             {
                 dp[i]=1+dp[prev];
                 hash[i]=prev;
             }
         }
         
         if(dp[i]>maxi){
             maxi=dp[i];
             lastindex=i;
         }
     }
     
     
     vector<int> ans;
     
     ans.push_back(arr[lastindex]);
     
     while(hash[lastindex]!=lastindex){
         lastindex=hash[lastindex];
         ans.push_back(arr[lastindex]);
     }
    
     reverse(ans.begin(),ans.end()); 
    
     
     return ans;
    }
