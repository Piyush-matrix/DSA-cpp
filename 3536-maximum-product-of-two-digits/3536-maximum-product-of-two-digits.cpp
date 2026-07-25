class Solution {
public:
    int maxProduct(int n) {
        string num=to_string(n);
        int s=num.size();
        sort(num.begin(),num.end());
        return (num[s-2]-'0')*(num[s-1]-'0');
     }
};