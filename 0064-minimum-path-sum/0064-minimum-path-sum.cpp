class Solution {
public:
    int solve(int n,int m,vector<vector<int>>& grid,vector<vector<int>>&dp){
     if(m==0 && n==0) return grid[0][0];
     if(m<0 || n<0) return 1e9;
     if(dp[n][m]!=-1) return dp[n][m];
     int x=grid[n][m]+solve(n-1,m,grid,dp);
     int y=grid[n][m]+solve(n,m-1,grid,dp);
     return dp[n][m]=min(x,y);
    }
    int minPathSum(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,grid,dp);
        
    }
};