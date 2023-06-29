class Solution {
  public:
  
  int dpmemo(int day,int task,vector<vector<int>>& points,vector<vector<int>>& dp){
      
      if(day==0){
          int maxi=0;
          for(int i=0;i<3;i++){
              if(i!=task){
                  maxi=max(points[0][i],maxi);
              }
          }
          return maxi;
      }
   
       
       
                  if(dp[day][task]!=-1)
                  return dp[day][task];
              
          
           int maxi=0;
          for(int i=0;i<3;i++){
             
              if(i!=task){
                 maxi=max(points[day][i] + dpmemo(day-1,i,points,dp),maxi);
              }
          }
          
          return dp[day][task]=maxi;
          
         
  }
    int maximumPoints(vector<vector<int>>& points, int n) {
       vector<vector<int>> dp(n,vector<int>(4,-1));
       
       //return dpmemo(n-1,3,points,dp);
       
       // tabulation
       
       // i: represents day and j: represents task performed before
       
    //   dp[0][0]=max(points[0][1],points[0][2]);
    //     dp[0][1]=max(points[0][0],points[0][2]);
    //      dp[0][2]=max(points[0][0],points[0][1]);
    //      dp[0][3]=max(points[0][0],max(points[0][1],points[0][2]));
       
    //   for(int day=1;day<n;day++){
           
    //       for(int last=0;last<4;last++){// if last=3 i.e. when no task is chosen for case when i=n-1 wnd we get final ans
               
    //           dp[day][last]=0;
              
    //           for(int task=0;task<3;task++){
    //               if(last!=task){
    //                   dp[day][last]=max(points[day][task] + dp[day-1][task],dp[day][last]);
    //               }
    //           }
              
              
    //       }
    //   }
      
    //   return dp[n-1][3];
    
    
    //**space optimisation*****
    vector<int> prev(4,0);
     prev[0]=max(points[0][1],points[0][2]);
        prev[1]=max(points[0][0],points[0][2]);
         prev[2]=max(points[0][0],points[0][1]);
         prev[3]=max(points[0][0],max(points[0][1],points[0][2]));
       
       for(int day=1;day<n;day++){
           vector<int> temp(4,0);
           for(int last=0;last<4;last++){// if last=3 i.e. when no task is chosen for case when i=n-1 wnd we get final ans
               
              temp[last]=0;
              
              for(int task=0;task<3;task++){
                  if(last!=task){
                    temp[last]=max(points[day][task] + prev[task],temp[last]);
                  }
              }
              
             
           }
            prev=temp;
       }
      
      return prev[3];
    }
};
