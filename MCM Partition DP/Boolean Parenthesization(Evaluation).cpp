 #define ll long long
 #define mod 1003


int dpmemo(int i,int j,int isTrue,string S, vector<vector<vector<ll>>> &dp){
    
    if(i>j)
    return 0;
    
    if(i==j){
        if(isTrue)
            return S[i]=='T';
       
        else
            return S[i]=='F';
              }
    
    
    if(dp[i][j][isTrue]!=-1)
    return dp[i][j][isTrue];
    
    ll ways=0;
    
    for(int index=i+1;index<=j-1;index+=2) { //as operators are after right 'i' at 2 increment
        
        ll lT=dpmemo(i,index-1,1,S,dp); //left partiotion number of 'T'
        ll lF=dpmemo(i,index-1,0,S,dp);//left partiotion number of 'F'
        ll rT=dpmemo(index+1,j,1,S,dp);
        ll rF=dpmemo(index+1,j,0,S,dp);
        
        
        if(S[index]=='&'){
            if(isTrue){
            ways=(ways + (lT*rT)%mod )%mod;
            }
            
            else
            ways=(ways + (lT*rF)%mod + (lF*rF)%mod + (lF*rT)%mod )%mod;
        }
        
        else if(S[index]=='|'){
            if(isTrue)
            ways=(ways + (lT*rT)%mod + (lT*rF)%mod + (lF*rT)%mod )%mod;
            
            else
            ways=(ways +  (lF*rF)%mod  )%mod;
        }
        
      else if(S[index]=='^'){
            if(isTrue)
            ways=(ways +  (lT*rF)%mod + (lF*rT)%mod )%mod;
            
            else
            ways=(ways + (lT*rT)%mod + (lF*rF)%mod  )%mod;
        }
    
    
    }
    
    return dp[i][j][isTrue]=ways;
}  
    int countWays(int N, string S){
        vector<vector<vector<ll>>>dp(N,vector<vector<ll>>(N,vector<ll>(2,-1)));
        return dpmemo(0,N-1,1,S,dp);
    }
