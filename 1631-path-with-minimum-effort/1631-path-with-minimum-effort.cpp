class Solution {
public:
    int dir[5]={0,1,0,-1,0};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        dist[0][0]=0;
        while(!pq.empty()){
            int diff=pq.top().first;
            int row=pq.top().second.first;
            int clm=pq.top().second.second;
            if(row==n-1 && clm==m-1) return diff;
            pq.pop();
            for(int i=0;i<4;i++){
                int nrow=row+dir[i];
                int nclm=clm+dir[i+1];
                if(nclm>=0 && nclm<m && nrow>=0 && nrow<n){
                    int neweffort=max(abs(heights[row][clm]-heights[nrow][nclm]),diff);
                    if(dist[nrow][nclm]>neweffort){
                        dist[nrow][nclm]=neweffort;
                        pq.push({neweffort,{nrow,nclm}});
                    }
                }
            }

        } return 0;
        
    }
};