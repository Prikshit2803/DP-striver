    //Front partitioning problem
    int maxele(int i,int j,vector<int>& arr){
        int ele=INT_MIN;
        for(int k=i;k<=j;k++){
            ele=max(ele,arr[k]);
        }
        
        return ele;
    }
    
    int dpmemo(int i,int k,vector<int>& arr,vector<int> & dp){
        int n=arr.size();
        
        if(i==arr.size())
        return 0;
        
        if(dp[i]!=-1)
        return dp[i];
        
        int maxsum=INT_MIN,maxi=INT_MIN;
        for(int j=i;j<min(n,i+k);j++){
            maxi=max(maxi,arr[j]);
            int sum=maxele(i,j,arr)*(j-i+1) + dpmemo(j+1,k,arr,dp); //maxi and maxele both work
            
            maxsum=max(sum,maxsum);
        }
        
        return dp[i]=maxsum;
    }
    int solve(int n, int k, vector<int>& arr){
       vector<int> dp(n,-1);
       
       return dpmemo(0,k,arr,dp);
    }
