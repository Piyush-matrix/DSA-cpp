class disjointset{
public:
    vector<int> size,parent;
    disjointset(int n){
        size.resize(n+1,1);
        parent.resize(n+1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

    int findUpr(int node){
        if(node==parent[node]) return node;
        return parent[node]=findUpr(parent[node]);

    }
    void unionbysize(int u,int v){
        int upr_u=findUpr(u);
        int upr_v=findUpr(v);
        if(upr_u==upr_v) return;
        if(upr_u < upr_v){
            parent[upr_u]=upr_v;
            size[upr_v]+=size[upr_u];
        }
        else{
            parent[upr_v]=upr_u;
            size[upr_u]+=size[upr_v];
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        disjointset ds(n);
        int extracnt=0;
        for(auto it :connections ){
            int u=it[0];
            int v=it[1];
            if(ds.findUpr(u)==ds.findUpr(v)) extracnt++;
            else{
                 ds.unionbysize(u,v);
            }
        }
        int cnt=0,ans;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i) cnt++;
        }
        ans=cnt-1;
        if(extracnt>=ans) return ans;
        return -1;

        
    }
};