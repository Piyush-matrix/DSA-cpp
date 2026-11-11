class Solution {
public:
    int dir[5]={0,1,0,-1,0};
    void dfs(vector<vector<char>>& grid,vector<vector<char>>& vis,int i,int j){
        vis[i][j]=true;
        int row=grid.size();
        int clm=grid[0].size();
        for(int k=0;k<4;k++){
            int nrow=i+dir[k];
            int nclm=j+dir[k+1];
            if(nrow>=0 && nrow<row && nclm>=0 && nclm<clm &&grid[nrow][nclm]=='1' && !vis[nrow][nclm]){
                dfs(grid,vis,nrow,nclm);
            }

        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<char>>vis(n,vector<char>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    cnt++;
                    dfs(grid,vis,i,j);
                }
            }
        } return cnt;
    }
};