class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int i = n - 1;
        int j = n - 1;
        int ones = 0;
        string result = "";
        while (i >= 0) {
            if (s[i] == '1') {
                ones++;
            }
            while (ones == k) {
                string current = s.substr(i, j - i + 1);
                if (result == "" || current.length() < result.length() || 
                   (current.length() == result.length() && current < result)) {
                    result = current;
                }
                if (s[j] == '1') {
                    ones--;
                }
                j--;
            }
            i--;
        }
        return result;
    }
};