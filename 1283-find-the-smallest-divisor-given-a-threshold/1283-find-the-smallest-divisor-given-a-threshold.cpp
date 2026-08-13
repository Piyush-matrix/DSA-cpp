class Solution {
public:
    long long totalh(vector<int>& nums, int hrs){
        int n=nums.size();
        long long tot=0;
        for(int i=0;i<n;i++){
            tot+=ceil((double)nums[i]/(double)hrs);
        } 
        return tot;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
    int maxel=*max_element(nums.begin(),nums.end());
        int low=1,high=maxel;
        while(low<=high){
            int mid=(low+high)/2;
            long long totalhr=totalh(nums,mid);
            if(totalhr<=threshold){
                high=mid-1;
            }
            else low=mid+1;

        } return low;
        
    }
};