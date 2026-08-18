class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        int n = price.size();
        long long ans = 0;
        sort(price.begin(), price.end());
        long long start = 1, end = price[n - 1] - price[0];
        while (start <= end) {
            long long mid = start + (end - start) / 2;
            int noOfCandies = 1, currPrice = price[0];
            for (int i = 1; i < n; i++) {
                if (currPrice + mid <= price[i]) {
                    noOfCandies++;
                    currPrice = price[i];
                }
            }
            if (noOfCandies >= k) {
                ans = mid;
                start = mid + 1;
            } else
                end = mid - 1;
        }
        return (int)ans;
    }
};