     vector<int> dp1(n,1),cnt(n,1);
	   
	   int maxi=1;
	   //LIS 
	   for(int i=1;i<n;i++){
	       for(int prev=0;prev<i;prev++){
	           if(nums[i]>nums[prev] && dp1[prev] +1 > dp1[i]){
	               dp1[i]=dp1[prev]+1;
	               cnt[i]=cnt[prev]; //it means we can create this new LIS same number of ways as cnt[prev]
	           }
	           
	           else  if(nums[i]>nums[prev] && dp1[prev] +1 == dp1[i]){
	               
	               cnt[i]+=cnt[prev]; //it is same length as currently largest length hence we add as it gives number of LIS so far
	           }
	       }
	       
	       maxi=max(dp1[i],maxi);
	   }
	   
	   int ans=0;
	   for(int i=0;i<n;i++){
	      
	       if(dp1[i]==maxi){
	           ans+=cnt[i];
	       }
	       
	   }
	   
	   return ans;
    }
