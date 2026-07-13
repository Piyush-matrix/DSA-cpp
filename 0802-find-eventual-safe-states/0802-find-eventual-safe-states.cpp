class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>> revGraph(n);
        vector<int> outdegree(n),ans;
        queue<int> q;
        for(int i=0;i<n;i++){
            for( auto it : graph[i]){
                revGraph[it].push_back(i);
                outdegree[i]++;
            }
            if(outdegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : revGraph[node]){
                if(--outdegree[it]==0) q.push(it);

            }
        } 
        sort(ans.begin(),ans.end());
        return ans;
        
        

        
    }
};