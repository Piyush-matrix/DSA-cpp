class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        int n2=n/2;
        string ans;
        sort(s.begin(),s.begin()+n2);
        for(int i=0;i<n2;i++){
            ans+=s[i];
        }
        if(n%2!=0){
            ans+=s[n2];
        }
        reverse(s.begin(),s.begin()+n2);
        
        for(int i=0;i<n2;i++){
            ans+=s[i];
        }
        return ans;
        
    }
};