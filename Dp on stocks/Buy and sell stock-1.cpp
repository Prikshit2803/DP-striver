//Brute force 
#include <bits/stdc++.h> 
int maximumProfit(vector<int> &arr){

int maxi=INT_MIN;
    for(int k=0;k<arr.size();k++){
         int ans=0;
    int buy=arr[k];
    for(int i=k+1;i<arr.size();i++){
      if (buy < arr[i]) {
        ans += arr[i] - buy;
        buy = arr[i];
      }
    }
    maxi=max(maxi,ans);
    }
    return maxi;
}

//working soln
#include <bits/stdc++.h> 
int maximumProfit(vector<int> &arr){

//for every ith element we keep track of minimum eement before it 
//so that we can sell
//we can buy and sell only once
int maxprofit=0;
int mini=arr[0];

for(int i=1;i<arr.size();i++){
  int profit=arr[i] - mini;

  maxprofit=max(maxprofit,profit);

     mini=min(mini,arr[i]);
}

return maxprofit;

}
