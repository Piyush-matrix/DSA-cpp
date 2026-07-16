class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
        vector<long long> prefixgcd(n);
        int maxi=0;
        long long sum=0;
        for(int i=0;i<n;i++){
            maxi=max(nums[i],maxi);
            prefixgcd[i]=gcd(nums[i],maxi);
        }
        sort(prefixgcd.begin(),prefixgcd.end());
        int i=0,j=n-1;
        while(i<j){
            sum+=gcd(prefixgcd[i],prefixgcd[j]);
            i++;
            j--;
        }
        return sum;
    }
};