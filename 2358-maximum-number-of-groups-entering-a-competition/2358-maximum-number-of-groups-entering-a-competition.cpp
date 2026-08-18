class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        sort(grades.begin(), grades.end());
        int maxGrps = 1;
        long long currSum = grades[0];
        int n = grades.size();
        int currSize = 1;
        int i = 1;
        while (true) {
            long long sum = 0;
            int size = 0;
            while (i < n && size <= currSize) {
                sum += grades[i];
                i++;
                size++;
            }
            if (i == n - 1) {
                sum += grades[i];
                size++;
                i++;
            }
            if (size > currSize && sum > currSum) {
                currSum = sum;
                maxGrps++;
                currSize = size;
            }
            if (i >= n)
                break;
        }
        return maxGrps;
    }
};