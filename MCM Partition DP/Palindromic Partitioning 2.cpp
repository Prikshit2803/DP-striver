//front partition technique

     bool isPalindrome(int i,int j,string str){
         while(i<j){
             if(str[i]!=str[j])
             return false;
             
             i++;
             j--;
         }
         
         return true;
     }
     
     
   int dpmemo(int i,string str, vector<int> &dp){
       
       
       if(i==str.length())
       return 0;
       
    //     if(i==str.length()-1)
    //   return 1;  not needed but can be placed
    
       if(dp[i]!=-1)
       return dp[i];
       
       int mincost=INT_MAX;
       
       for(int j=i;j<str.length();j++){
           if(isPalindrome(i,j,str)){
               int cost=1+dpmemo(j+1,str,dp);
               mincost=min(mincost,cost);
           }
       }
       
       return dp[i]=mincost;
   }
    int palindromicPartition(string str)
    {
        int n=str.length();
       vector<int> dp(n,-1);
       
       return dpmemo(0,str,dp)-1; //as partition might be placed after last element
    }
