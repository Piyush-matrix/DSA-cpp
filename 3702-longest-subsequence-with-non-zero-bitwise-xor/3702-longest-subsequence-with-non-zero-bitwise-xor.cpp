class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int ans=nums.size();
        int cnt=0;
        int x=0;
        for(int i=0;i<ans;i++){
             x^=nums[i];
             if(nums[i]!=0) cnt++;
        }
        if(x!=0) return ans;
        if(cnt==0) return 0;
        return ans-1;

    }
};