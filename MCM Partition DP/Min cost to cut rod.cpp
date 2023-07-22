//memo + tabulation
   int dpmemo(int i,int j,vector<int>& cuts,vector<vector<int>> &dp){
        if(i>j)
        return 0;


        if(dp[i][j]!=-1)
        return dp[i][j];

        int mini=1e9;
        for(int index=i;index<=j;index++){ //'index' indicates where  partition to be made
               
               int cost=cuts[j+1]-cuts[i-1]+dpmemo(i,index-1,cuts,dp) + dpmemo(index+1,j,cuts,dp);

               mini=min(mini,cost);
        }

        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        
        int c=cuts.size();
        cuts.push_back(n);

        cuts.insert(cuts.begin(),0);

        sort(cuts.begin(),cuts.end()); // this way we can separtely perform cuts after a separation as they are in increasing order and cuts on left and right of index dont affect each other

        // vector<vector<int>> dp(c+1,vector<int>(c+1,-1)); // as after adding two elements to cuts,the c th element is the last elelemnt of original 'cuts' of size c
         

        //  return dpmemo(1,c,cuts,dp);

         //tabulatiom
         
         vector<vector<int>> dp(c+2,vector<int>(c+2,0));
          //covers the case if(i>j) return 0;


          //explore
          for(int i=c;i>=1;i--){
              for(int j=i;j<=c;j++){
                  int mini=1e9;
        
        for(int index=i;index<=j;index++){ //'index' indicates where  partition to be made
               
               int cost=cuts[j+1]-cuts[i-1]+dp[i][index-1] + dp[index+1][j];

               mini=min(mini,cost);
        }

         dp[i][j]=mini;
              }
          }

          return dp[1][c];

    }
