//leetcode and gfg working soln
class Solution {
public:
     
     int mod=1e9+7;

     long long  dpmemo(int i,int target,vector<int> coins, vector<vector<int>> &dp){
             
            //  if(target==0)
            //  return 1;
             
             if(i==0){
                 if(target%coins[0]==0)
                 return 1;
                 
                 else
                 return 0;
             }
             
             if(dp[i][target]!=-1)
             return dp[i][target];
             
             int notTake=dpmemo(i-1,target,coins,dp);
             int Take=0;
             if(coins[i]<=target)
             Take=dpmemo(i,target-coins[i],coins,dp);
             
             return dp[i][target]=(Take+notTake);
         }



    int change(int amount, vector<int>& coins) {
        int N=coins.size();
        //vector<vector<int>> dp(N,vector<int>(amount+1,-1)); //memoisation
        vector<vector<int>> dp(N,vector<int>(amount+1,0));
        //return dpmemo(N-1,amount,coins,dp);
        
        //base-case
        for(int target=0;target<=amount;target++){
            if(target%coins[0]==0)
            dp[0][target]=1;
            
        }
        
        //explore every possibility
        for(int i=1;i<N;i++){
            for(int target=0;target<=amount;target++){
                //copy-recusion
                 int notTake=dp[i-1][target];
             int Take=0;
             if(coins[i]<=target)
             Take=dp[i][target-coins[i]];
             
             dp[i][target]=(Take+notTake);
            }
        }
        
        return dp[N-1][amount];
    }
};
