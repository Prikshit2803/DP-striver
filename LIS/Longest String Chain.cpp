  bool cmp(string &s1,string &s2){
      if(s1.length()!=1+s2.length())
      return false;
      
      int i=0,j=0;
      while(i<s1.length()){
          if(s1[i]==s2[j]){
              i++;
              j++;
          }
          
          else{
              i++;
          }
      }
      
      if(j==s2.length() && i==s1.length())
      return true;
      
      else
      return false;
  }
  
  static bool comp(string &s1,string &s2){ //static is necessary
      return s1.length()<s2.length(); //arrange in increasing order of length
  }
    int longestChain(int n, vector<string>& words) {
       
       vector<int> dp(n,1);
       
       sort(words.begin(),words.end(),comp);
       
      int maxi=1;
      
      
       for(int i=1;i<n;i++){
           for(int prev=0;prev<i;prev++){
               if(cmp(words[i],words[prev]) && 1 + dp[prev]>dp[i] ){
                   dp[i]=1+dp[prev];
               }
           }
           maxi=max(maxi,dp[i]);
       }
       
       return maxi;
    }
