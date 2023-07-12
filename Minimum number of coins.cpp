//Without DP soln
class Solution{
public:
    vector<int> minPartition(int N)
    {
        vector<int> ans;
        
        while(N/2000!=0){
            N=N-2000;
            ans.push_back(2000);
        }
        
         while(N/500!=0){
            N=N-500;
            ans.push_back(500);
        }
        
         while(N/200!=0){
            N=N-200;
            ans.push_back(200);
        }
        
        while(N/100!=0){
            N=N-100;
            ans.push_back(100);
        }
        
        while(N/50!=0){
            N=N-50;
            ans.push_back(50);
        }
        
        while(N/20!=0){
            N=N-20;
            ans.push_back(20);
        }
        
        while(N/10!=0){
            N=N-10;
            ans.push_back(10);
        }
        
        while(N/5!=0){
            N=N-5;
            ans.push_back(5);
        }
        
        
        while(N/2!=0){
            N=N-2;
            ans.push_back(2);
        }
        
        while(N/1!=0){
            N=N-1;
            ans.push_back(1);
        }
        
        return ans;
    }
};

//another-without dp soln - Greedy approach
vector<int> minPartition(int N)
    {
        // code here
        int arr[10]={ 2000,500,200,100,50,20,10,5,2,1 };
        vector<int>v;
        int i=0;
        int rem=N;int ans=0;
        while(i<10 && rem){
            if(arr[i]<=rem){
                ans+=rem/arr[i];
                while(ans){
                    v.push_back(arr[i]);
                    ans--;
                }
                rem=rem%arr[i];
                if(rem==0){
                    return v;
                }
                
            }
            else{
                    i++;
                }
        }
        
    }

//Memoisation
class Solution {
public:
    
    int dpmemo(int i,int target,vector<int>& coins,vector<vector<int>> &dp){
        if(i==0){
            if(target%coins[0]==0) 
            return target/coins[0];

            else
            return 1e9;
        }

        if(dp[i][target]!=-1)
          return dp[i][target];

        int notTake=dpmemo(i-1,target,coins,dp);

        int Take=INT_MAX;
        if(target>=coins[i])
        Take=1 + dpmemo(i,target-coins[i],coins,dp);

        return dp[i][target]=min(Take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
         int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        
        // if(n==1){
        //     if(amount%coins[0]==0) 
        //     return amount/coins[0];

        //     else
        //     return -1;
        // } // not needed
        int ans= dpmemo(n-1,amount,coins,dp);

        if(ans>=1e9)
        return -1;

        else
        return ans;
    }
};

//Tabulation and it can easily be space-optimised using prev and cur
int coinChange(vector<int>& coins, int amount) {
         int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
    

        //base-case
        for(int target=0;target<=amount;target++){
              if(target%coins[0]==0)  
              dp[0][target]=target/coins[0];

              else
              dp[0][target]=1e9;

        }


        //explore all cases
        for(int i=1;i<n;i++){
            for(int target=0;target<=amount;target++){
                //copy-recursion
                 int notTake=dp[i-1][target];

        int Take=INT_MAX;
        if(target>=coins[i])
        Take=1 + dp[i][target-coins[i]];

         dp[i][target]=min(Take,notTake);
            }
        }

         int ans= dp[n-1][amount];

        if(ans>=1e9)
        return -1;

        else
        return ans;
    }
