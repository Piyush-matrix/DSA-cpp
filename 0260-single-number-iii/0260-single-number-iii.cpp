class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorr=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            xorr=xorr^nums[i];
        }
        unsigned int rytmost = xorr & -(unsigned int)xorr;
        int b1=0,b2=0;
        for(int i=0;i<n;i++){
            if(rytmost&nums[i]) b1=b1^nums[i];
            else b2=b2^nums[i];
        }
        return {b1,b2};
       
    }
};