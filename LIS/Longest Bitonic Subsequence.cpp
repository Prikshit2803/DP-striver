int LongestBitonicSequence(vector<int>nums)
	{
	   vector<int> dp1(nums.size(),1),dp2(nums.size(),1);
	   
	   //LIS from start
	   for(int i=1;i<nums.size();i++){
	       for(int prev=0;prev<i;prev++){
	           if(nums[i]>nums[prev] && dp1[prev] +1 > dp1[i]){
	               dp1[i]=dp1[prev]+1;
	           }
	       }
	   }
	   
	   //LIS from behind
	   for(int i=nums.size()-2;i>=0;i--){
	       for(int prev=nums.size()-1;prev>i;prev--){
	           if(nums[i]>nums[prev] && dp2[prev] +1 > dp2[i]){
	               dp2[i]=dp2[prev]+1;
	           }
	       }
	   }
	   
	   //take sum of dp1 and dp2 minus the element as it repeats
	   int maxi=0;
	    for(int i=0;i<nums.size();i++){
	        maxi=max(dp1[i]+dp2[i]-1,maxi);
	    }
	    
	    return maxi;
	}
