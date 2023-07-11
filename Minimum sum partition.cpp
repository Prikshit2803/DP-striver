// Similar(very) to subset-sum equal to target and partition into equal sum problems
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    int sum=0;
        for(int i=0;i<n;i++)
        sum+=arr[i];
        
      
        
       
      
      vector<int> prev((sum)+1,0), cur((sum)+1,0);
      
      prev[0]=1; //base case
      cur[0]=1;
      
      prev[arr[0]]=1; //it means when i=0 ,  target=arr[0]
      
      //explore all path
      for(int i=1;i<n;i++){
          for(int target=0;target<=sum;target++){
              //copy recursion
                  int notTake=prev[target];
                  int Take=0;
                  if(target>=arr[i])
                    Take=prev[target-arr[i]];
    
                  cur[target]=(notTake||Take);
          }
          
          prev=cur;
          prev[0]=1;
      }
      
      
      //only this part is different from subset-sum equal to target as last row tells if a crtain sum is possible or not 
      //total sum is given by 'sum' sum-s1 gives s2 
      
      int mini=INT_MAX;
      
      
      for(int i=0;i<sum;i++){
          if(prev[i]==1){
              int s1=i;
              int s2=sum-i;
              
              mini=min(mini,abs(s1-s2));
              
              
          }
          
      }
      
    return mini;
        
       
	} 
};
