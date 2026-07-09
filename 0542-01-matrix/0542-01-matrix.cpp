class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dist(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        int delrow[]={-1,0,+1,0};
        int delclm[]={0,+1,0,-1};
        while(!q.empty()){
            int row=q.front().first.first;
            int clm=q.front().first.second;
            int level=q.front().second;
            q.pop();
            dist[row][clm]=level;
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int nclm=clm+delclm[i];
                if(nrow>=0 && nrow<n && nclm>=0 && nclm<m && vis[nrow][nclm]==0){
                    vis[nrow][nclm]=1;
                    q.push({{nrow,nclm},level+1});
                }
            }
        } return dist;
    }
};