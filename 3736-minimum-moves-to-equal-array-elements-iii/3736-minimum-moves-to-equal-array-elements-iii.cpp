class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int lst=nums[n-1];
        int moves=0;
        for(int i=0;i<n;i++){
            moves+=lst-nums[i];
        } 
        return moves;
        
    }
};