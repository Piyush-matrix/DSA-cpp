class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
         long long res = 0;
        vector<int> s;
        unordered_map<int, int> count;
        for (int a : nums) {
            while (!s.empty() && s.back() > a) {
                count[s.back()]--;
                s.pop_back();
            }
            res += s.size() - count[a];
            s.push_back(a);
            count[a]++;
        }
        return res;
    }
};