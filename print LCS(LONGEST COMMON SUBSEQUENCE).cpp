//Uses LCS
int dpmemo(int i, int j,string &s1, string &s2,vector<vector<int>> &dp){
	//with-right shift of index
	if(i==0||j==0)
	return 0;

     if(dp[i][j]!=-1)
	 return dp[i][j];

      if(s1[i-1]==s2[j-1])
	  return dp[i][j]=(1 + dpmemo(i-1,j-1,s1,s2,dp));

	  else
	  return dp[i][j]=max(dpmemo(i-1,j,s1,s2,dp),dpmemo(i,j-1,s1,s2,dp));
}



string findLCS(int n, int m,string &s1, string &s2){
       //vector<vector<int>> dp(n+1,vector<int>(m+1,-1)); //for memo
	   vector<vector<int>> dp(n+1,vector<int>(m+1,0)); // for tabulation
       //shift-index to right

	
       tabulation
   
       for(int i=1;i<=n;i++){
           for(int j=1;j<=m;j++){
              
              if(s1[i-1]==s2[j-1])
               dp[i][j]=1 + dp[i-1][j-1];
        
             else
               dp[i][j]=max(dp[i-1][j],dp[i][j-1]); 
           }
       }

	  // int len= dpmemo(n,m,s1,s2,dp);

	//   int index=len-1;

	  int i=n;
	  int j=m;

	   string ans="";
	//   for(int i=0;i<len;i++){
	// 	  ans+='$';
	//   }

	   while(i>0 && j>0){
		  
		  if(s1[i-1]==s2[j-1]){
			  ans=s1[i-1] + ans;
			 // index--;
			  i--;
			  j--;

		  }

		  else if(dp[i-1][j]>dp[i][j-1]) //if both equal we pick any and it wont happen as it would mean there are multiple subsequnces and we cant use dp table there
		  {
			  i--;
		  }

		  else
		  j--;
	  }



	return ans;
	
		
}
