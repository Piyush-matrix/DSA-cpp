class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i+=2){
            string num1=to_string(nums[i]);
            num1+=to_string(nums[i+1]);
            int ans=stoi(num1);
            mini=min(mini,ans);
        } return mini;
        
    }
};