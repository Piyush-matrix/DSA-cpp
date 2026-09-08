class Solution {
public:
    int climbStairs(int n) {
        int prev=1,prev2=0;
        int curri;
        for(int i=1;i<=n;i++){
           curri=prev+prev2;
           prev2=prev;
           prev=curri;
        } return prev;
    }
};