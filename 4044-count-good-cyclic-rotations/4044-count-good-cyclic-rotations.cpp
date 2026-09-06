class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int n=nums.size();
        long long sum1=0,sum2=0,cnt=0;
        for(int i=0;i<n/2;i++){
           sum1+=nums[i];
           sum2+=nums[n/2+i];
        }
        for(int i=0;i<n;i++){
            if(sum1>sum2)cnt++;
            int next_element = nums[(i + n / 2) % n];
            sum1=sum1-nums[i]+next_element;
            sum2=sum2-next_element+nums[i];
        }
        return cnt;
        
    }
};