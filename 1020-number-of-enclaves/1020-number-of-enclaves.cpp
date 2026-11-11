class Solution {
public:
    int dir[5]={0,1,0,-1,0};
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(grid[i][j]==1){
                        q.push({i,j});
                        vis[i][j]=1;
                    }

                }
            }
        }
        while(!q.empty()){
            int row=q.front().first;
            int clm=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+dir[i];
                int nclm=clm+dir[i+1];
                if(nrow>=0 && nrow<n && nclm>=0 && nclm<m && grid[nrow][nclm]==1 && !vis[nrow][nclm]){
                    q.push({nrow,nclm});
                    vis[nrow][nclm]=1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(!vis[i][j] && grid[i][j]==1)cnt++;
            }
        } return cnt;
        
    }
};