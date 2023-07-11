////Use subset-sum equal to target

class Solution{
public:


//t1 and t2 are partitions and this is my approach and it doesnt work,figure out ehy
// int dpmemo(int i,int t1,int t2,int arr[]){
//     if(t1==t2 && (t1!=0 && t2!=0))
//     return 1;
    
//     if(i==0){
//      if(t1+arr[0]==t2) 
//      return 1;
     
//      else if(t2+arr[0]==t1)
//      return 1;
     
//      else
//      return 0;
//     }
//     //return (t1+arr[0]==t2||t2+arr[0]==t1);
    
//     int a=dpmemo(i-1,t1+arr[i],t2,arr);
//     int b=dpmemo(i-1,t1,t2+arr[i],arr);
    
//      if(a==1||b==1)
//      return 1;
     
//      else
//      return 0;
// }

int dpmemo(int i,int target,int arr[],vector<vector<int>> &dp){
    //use subset-sum equal to target
    if(target==0)
    return 1;
    
    if(i==0)
    return (arr[0]==target);
    
    if(dp[i][target]!=-1)
    return dp[i][target];
    
    int notTake=dpmemo(i-1,target,arr,dp);
    int Take=0;
    if(target>=arr[i])
    Take=dpmemo(i-1,target-arr[i],arr,dp);
    
     return dp[i][target]=(notTake||Take);
     
}

    int equalPartition(int N, int arr[])
    {
       
        int sum=0;
        for(int i=0;i<N;i++)
        sum+=arr[i];
        
        if(sum%2!=0)
        return 0;
        
        vector<vector<int>> dp(N,vector<int>((sum/2)+1,-1)); //for memoisation
       
        
        
        
      //return dpmemo(N-1,sum/2,arr,dp); 
      //we do sum/2 as if equal partition then both partion have qual sum which is sum/2
      
      
      vector<int> prev((sum/2)+1,0), cur((sum/2)+1,0);
      
      prev[0]=1; //base case
      cur[0]=1;
      
      prev[arr[0]]=1; //it means when i=0 ,  target=arr[0]
      
      //explore all path
      for(int i=1;i<N;i++){
          for(int target=0;target<=sum/2;target++){
              //copy recursion
                  int notTake=prev[target];
                  int Take=0;
                  if(target>=arr[i])
                    Take=prev[target-arr[i]];
    
                  cur[target]=dp[i][target]=(notTake||Take);
          }
          
          prev=cur;
          prev[0]=1;
      }
      
      
    return prev[sum/2];
        
       }
      
    
};
