// using LIS + tracking using hash array - striver approach
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {


        vector<int> dp(n,1),hash(n,0);
        
        int maxi=1;
        int lastIndex=0;
        
        for(int i=1;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                
                if(arr[i]>arr[prev] && 1+dp[prev]>dp[i]){
                    dp[i]=1 + dp[prev];
                    hash[i]=prev;
                }
            }
            
            if(dp[i]>maxi){
                maxi=dp[i];
                lastIndex=i;
            }
        }
      
      
      vector<int> ans;
      
      ans.push_back(arr[lastIndex]);
          
      while(hash[lastIndex]!=lastIndex){ //if hash[lastIndex]==lastIndex it means it is first element in LIS 
      
             lastIndex=hash[lastIndex];
             ans.push_back(arr[lastIndex]);
          
      }
      
      reverse(ans.begin(),ans.end());
      
      return ans;
    }
