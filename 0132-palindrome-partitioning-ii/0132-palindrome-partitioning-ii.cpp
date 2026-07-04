class Solution {
public:
    bool ispalindrome(string &s,int i,int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        } 
        return true;
    }
    int solve(string &s,int i,int n,vector<int> &dp){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int ans=INT_MAX;
        for(int k=i;k<n;k++){
             if(ispalindrome(s,i,k)){
            int temp=1+solve(s,k+1,n,dp);
            ans=min(ans,temp);
             }
        } return dp[i]=ans;
    
    }
    int minCut(string s) {
        int n=s.size();
        vector<int>dp(n,-1);
        return solve(s,0,n,dp)-1;
    }
};