// Hi guys . Reading all comments I want to add some few points:-

// 1) the problem cannot be solve using dp 

//     a)because there are 4 direction to move . so you will catch in infinite loop . Example (i, j )->(i-1 ,j) now in next call from (i-1 , j ) you will  again go back to i, j  ; 

//    b) the point might srruck that all number are positive why not only move down and right but that will also give wa . 

//    c) we have to maintain visited vector but its also a changing factor so 

//        we have to include it in dp but then memory limit will exceed . 

 

// thererfore go for djkstra algorithm to solve the question greedily  . 

//failed dp approach
class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
	
	int dpmemo(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
	    
	     
	    if(i==0 && j==0)
	    return grid[0][0];
	    
	    
	    if(i<0||j<0 ) 
	    return 1e9;
	    
	 
	    
	   
	    if(dp[i][j]!=-1)
	    return dp[i][j];
	    
	 
	    
	    int up=grid[i][j] + dpmemo(i-1,j,grid,dp);
	    
	   
	    
	    int left=grid[i][j] + dpmemo(i,j-1,grid,dp);
	    
	   
	    
	    return dp[i][j]= min(up,left);
	}
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        
        int rows=grid.size();
        int cols=grid[0].size();
        
       
        
        vector<vector<int>> dp(rows,vector<int>(cols,-1));
        // vector<vector<int>> vis(rows,vector<int>(cols,0));
        
        //return dpmemo(rows-1,cols-1,grid,dp);
        
        //tabulation
        
        for(int i =0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(i==0 && j==0) dp[i][j]=grid[i][j];
                
                else{
                    int up=grid[i][j],left=grid[i][j];
                    
                    if(i>0) up+= dp[i-1][j];
                    else
                    up=1e9;
                    if(j>0) left+=dp[i][j-1];
                    else
                    left=1e9;
                    
                    dp[i][j]=min(up,left);
                }
            }
        }
        
        return dp[rows-1][cols-1];
    }
};

//dijstra's based greedy soln
class Solution
{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
	
	// we use dijkstra's algo ... 
	//priority queue pq with min cost at top to store the vertices with their corresponding costs. Initialize it with the starting cell (0,0) and its cost
	//starting from initial vertex we consider all four paths and then take min cost and similarly we keep on popping whatever min cost path exists so far.
    int minimumCostPath(vector<vector<int>>& grid) 
    {     
       int n=grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        
        
        pq.push({grid[0][0],{0,0}});
        
        while(!pq.empty()){
            int cost=pq.top().first;
            int rows=pq.top().second.first;
            int cols=pq.top().second.second;
            
            pq.pop();
            
            int dx[]={-1,0,1,0};
            int dy[]={0,1,0,-1};
            
            for(int i=0;i<4;i++){
                int nx=rows+dx[i];
                int ny=cols + dy[i];
                
                if(nx==n-1 && ny==n-1)
                return grid[n-1][n-1] + cost;
                
                else if(nx>=0 && ny>=0 && nx<n && ny<n && vis[nx][ny]!=1){
                    
                    int newcost=grid[nx][ny] + cost;
                    pq.push({newcost,{nx,ny}});
                    
                    vis[nx][ny]=1;
                }
            }
        }
        

    }
};
