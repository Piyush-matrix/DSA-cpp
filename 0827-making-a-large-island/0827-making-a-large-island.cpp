class disjointset {
public:
    vector<int> size,parent;
    disjointset(int n){
       size.resize(n,1);
       parent.resize(n);
       for(int i=0;i<n;i++){
           parent[i]=i;
        }
    }
    int findupr(int node){
        if(node==parent[node]) return node;
        return parent[node]=findupr(parent[node]);
    }
    void unionbysize(int u,int v){
        int upr_u=findupr(u);
        int upr_v=findupr(v);
        if(upr_u==upr_v) return;
        if(size[upr_u]<size[upr_v]){
            parent[upr_u]=upr_v;
            size[upr_v]+=size[upr_u];
        }
        else{
            parent[upr_v]=upr_u;
            size[upr_u]+=size[upr_v];
        }
    }

};
bool isvalid(int nrow,int nclm,int n){
    return nrow>=0 && nrow<n && nclm>=0 && nclm<n;
}
class Solution {
public:
    int dir[5]={0,1,0,-1,0};
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        disjointset ds(n*n);
        for(int row=0;row<n;row++){
            for(int clm=0;clm<n;clm++){
                if(grid[row][clm]==0) continue;
                for(int i=0;i<4;i++){
                    int nrow=row+dir[i];
                    int nclm=clm+dir[i+1];
                    if(isvalid(nrow,nclm,n) && grid[nrow][nclm]==1){
                        int nodeno=row*n+clm;
                        int adjnode=nrow*n+nclm;
                        ds.unionbysize(nodeno,adjnode);
                    }
                }
            }
        } int mx=0;
        for(int row=0;row<n;row++){
            for(int clm=0;clm<n;clm++){
                if(grid[row][clm]==1) continue;
                set<int> components;
                for(int i=0;i<4;i++){
                    int nrow=row+dir[i];
                    int nclm=clm+dir[i+1];
                    if(isvalid(nrow,nclm,n) && grid[nrow][nclm]==1){
                       components.insert(ds.findupr(nrow*n+nclm));
                    }
                }
                int size=1;
                for(auto it : components){
                    size+=ds.size[it];
                }
                mx=max(mx,size);
            }
        } 
        for(int cell=0;cell<n*n;cell++){
            mx=max(mx,ds.size[ds.findupr(cell)]);
        }
        return mx;
    }
};