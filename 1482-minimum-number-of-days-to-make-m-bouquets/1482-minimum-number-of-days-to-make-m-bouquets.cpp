class Solution {
public:
    bool possible(vector<int>& bloomDay,int day, int m, int k){
        int cnt=0,nofB=0;
        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=day){
                cnt++;
            }
            else{
                nofB+=cnt/k;
                cnt=0;
            }
           
        }  nofB+=cnt/k;
        return nofB>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long val=m*1LL*k*1LL;
        if(val>bloomDay.size()) return -1;
        int low=*min_element(bloomDay.begin(),bloomDay.end());
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        while(low<=high){
            int mid=(low+high)/2;
            if(possible(bloomDay,mid,m,k)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        } return low;

    }
};