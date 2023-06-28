// dp[n] = dp[n-1] + dp[n-2]  we can directly just add these without adding 1 or anything because ways will remain same take eg of n=3 , dp[1]=1 and dp[2] =2 no dp[3[ will be 3 only as from 1 path of sp only one way possible i.e. to take 2 steps if we take 1 step it comes under dp[2] and then from dp[2] only one way possible
//striver uses fibonnacci similar code
// but this is my approach
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int temp=1000000007;
     
     //top-down : memoisation
    int dpmemo(int n,vector<int> &dp){
        if(n==1)
        return 1;
        
        if(n==2)
        return 2;
        
        if(dp[n]!=-1)
        return dp[n];
        
        return dp[n]=(dpmemo(n-1,dp)%temp + dpmemo(n-2,dp)%temp)%temp;
    }
    int countWays(int n)
    {
        vector<int> dp(n+1,-1);
        
        return dpmemo(n,dp);
        
        //space-optimisation can also be done here
        //bottom-up : Tabulation
        // int temp=1000000007;
        //dp[0]=0;
        // dp[1]=1;
        // dp[2]=2;
        
        // for(int i=3;i<=n;i++){
        //     dp[i]=((dp[i-1])%temp + (dp[i-2])%temp)%temp;
        // }
        
        // return dp[n];
    }
};
