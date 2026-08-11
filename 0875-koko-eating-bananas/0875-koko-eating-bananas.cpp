class Solution {
public:
    long long totalh(vector<int>& piles, int hrs){
        int n=piles.size();
        long long tot=0;
        for(int i=0;i<n;i++){
            tot+=ceil((double)piles[i]/(double)hrs);
        } 
        return tot;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxel=*max_element(piles.begin(),piles.end());
        int low=1,high=maxel;
        while(low<=high){
            int mid=(low+high)/2;
            long long totalhr=totalh(piles,mid);
            if(totalhr<=h){
                high=mid-1;
            }
            else low=mid+1;

        } return low;
        
    }
};