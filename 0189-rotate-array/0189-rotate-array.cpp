class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        int it=nums.size()-k;
        reverse(nums.begin()+it,nums.end());
        reverse(nums.begin(),nums.begin()+it);
        reverse(nums.begin(),nums.end());
        
    }
};