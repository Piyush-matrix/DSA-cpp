class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        map<int,vector<int>>mpp;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]].push_back(i);
        }
        for(auto &p:mpp){
            if(p.second.size()>=3){
                int ans=p.second[1]-p.second[0];
                bool issp=true;
             for(int ind=2;ind<p.second.size();ind++){
                  if((p.second[ind]-p.second[ind-1])!=ans){
                      issp=false;
                      break;
                    }
                } 
             if(issp)cnt++;
            }
        } 
        return cnt;
        
    }
};