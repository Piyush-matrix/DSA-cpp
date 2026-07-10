class Solution {
public:
    int dir[5]={0,1,0,-1,0};
    void dfs(int row,int clm,vector<vector<int>> &vis,vector<vector<char>>& board,int dir[]){
        int n=board.size();
        int m=board[0].size();
        vis[row][clm]=1;
        for(int i=0;i<4;i++){
            int nrow=row+dir[i];
            int nclm=clm+dir[i+1];
            if(nrow>=0 && nrow<n && nclm>=0 && nclm<m && !vis[nrow][nclm] && board[nrow][nclm]=='O'){
                dfs(nrow,nclm,vis,board,dir);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        // now traverse all boundries
        // first row
        for(int j=0;j<m;j++){
            if(!vis[0][j] && board[0][j]=='O'){
                dfs(0,j,vis,board,dir);
            }
            // last row
            if(!vis[n-1][j] && board[n-1][j]=='O'){
                dfs(n-1,j,vis,board,dir);
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i][0] && board[i][0]=='O'){
                 dfs(i,0,vis,board,dir);
            }
            if(!vis[i][m-1] && board[i][m-1]=='O'){
                dfs(i,m-1,vis,board,dir);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        } 
        
    }
};