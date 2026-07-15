class Solution {
public:
    int delta[9]={-1,0,1,0,-1,1,1,-1,-1};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
        vector<vector<int>>dist(n+1,vector<int>(n+1,1e9));
        queue<pair<int,pair<int,int>>> q;
        dist[0][0]=1;
        q.push({1,{0,0}});
        while(!q.empty()){
            int dis=q.front().first;
            int row=q.front().second.first;
            int clm=q.front().second.second;
            q.pop();
            for(int i=0;i<8;i++){
                int nrow=row+delta[i];
                int nclm=clm+delta[i+1];
                if(nrow>=0 && nrow<n && nclm>=0 && nclm<n && grid[nrow][nclm]==0 && dis+1<dist[nrow][nclm]){
                    dist[nrow][nclm]=1+dis;
                    q.push({1+dis,{nrow,nclm}});
                }
            }
        } return dist[n-1][n-1]==1e9 ? -1 : dist[n-1][n-1];
        
    }
};