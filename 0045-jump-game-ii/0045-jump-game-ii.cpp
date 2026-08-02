class Solution {
public:
    int jump(vector<int>& nums) {
       int jumps=0,r=0,l=0;
       while(r<nums.size()-1){
           int farthest=0;
           for(int i=l;l<=r;l++){
            farthest=max(farthest,l+nums[l]);
           }
           l=r+1;
           jumps=jumps+1;
           r=farthest;
       }
       return jumps;
    }
};