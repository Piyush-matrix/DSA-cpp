class Solution {
public:
    int possible(vector<int>& nums, int tillsum){
        int cnt=1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<=tillsum){
                sum+=nums[i];
            }
            else{
                cnt++;
                sum=nums[i];
            }
        } return cnt;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid=(low+high)/2;
            if(possible(nums,mid)>k){
                low=mid+1;
                            }
            else{
                high=mid-1;
            }
        } return low;
        
    }
};