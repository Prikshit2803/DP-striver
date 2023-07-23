//My approach works but TLE

int dpmemo(int i,int j,vector<int> arr,vector<vector<int>> &dp ){
    if(arr.size()==2)
    return 0;
    
    // if(dp[i][j]!=-1)
    // return dp[i][j];
    
    int maxi=INT_MIN;
    
    for(int k=i;k<=j;k++){
        int coins=arr[k-1]*arr[k]*arr[k+1];
        vector<int> ap=arr;
        ap.erase(ap.begin()+k);
        // if(k==j)
        // coins+=dpmemo(i,j-1,ap,dp);
        
        // else
        coins+=dpmemo(i,j-1,ap,dp);
        
        maxi=max(maxi,coins);
    }
    
    return maxi;
}
    int maxCoins(int N, vector<int> &arr) {
       
    //   vector<int> ap= arr.erase(arr.begin() + 1 );
    //   cout<<ap[1]<<".";
    
    vector<vector<int>> dp(N+1,vector<int>(N+1,-1));
    
    arr.push_back(1);

        arr.insert(arr.begin(),0);
       
       return dpmemo(1,N,arr,dp);
    }

//DP memo

int dpmemo(int i,int j,vector<int> arr,vector<vector<int>> &dp ){
    if(i>j)
    return 0;
    
    if(dp[i][j]!=-1)
    return dp[i][j];
    
    int maxi=INT_MIN;
    
    //we start bottom up so that f(i,k-1) & f(k+1,j) can be solved independently
    for(int k=i;k<=j;k++){
        int coins=arr[i-1]*arr[k]*arr[j+1] + dpmemo(i,k-1,arr,dp) + dpmemo(k+1,j,arr,dp);
       
        
        maxi=max(maxi,coins);
    }
    
    return dp[i][j]=maxi;
}



    int maxCoins(int N, vector<int> &arr) {
       
    
    
    vector<vector<int>> dp(N+1,vector<int>(N+1,-1));
    
    arr.push_back(1);

        arr.insert(arr.begin(),1);
       
       return dpmemo(1,N,arr,dp);
    }

//TAbulation
int maxCoins(int N, vector<int> &arr) {
    
    arr.push_back(1);

        arr.insert(arr.begin(),1);
       
       //Tabulatiom
       
       vector<vector<int>> dp(N+2,vector<int>(N+2,0));
       //Base-case is taken care as all elements 0
       
       for(int i=N;i>=1;i--){
           for(int j=i;j<=N;j++){
               
            //   if(i>j)
            //   continue;
               
                int maxi=INT_MIN;
    
    //we start bottom up so that f(i,k-1) & f(k+1,j) can be solved independently
    for(int k=i;k<=j;k++){
        int coins=arr[i-1]*arr[k]*arr[j+1] + dp[i][k-1] + dp[k+1][j];
       
        
        maxi=max(maxi,coins);
    }
    
    dp[i][j]=maxi;
           }
       }
       
       return dp[1][N];
    }
