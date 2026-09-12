class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        map<int,vector<int>>mpp;
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]].push_back(i);
        }
        for(auto &p:mpp){
            if(p.second.size()==3){
               
                    if(p.second[1]-p.second[0]==p.second[2]-p.second[1]){
                        cnt++;
        
                }
            }
        } return cnt;
        
    }
};