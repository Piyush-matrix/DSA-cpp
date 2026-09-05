class Solution {
public:
    void generate(string res,int open,int close,int n,vector<string>&result){
        if(open==close && open+close==2*n){
            result.push_back(res);
            return;
            }
        if(open<n) {
            generate(res+ "(",open+1,close,n,result);
        }
        if(close<open) {
            generate(res+")",open,close+1,n,result);
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate("",0,0,n,result);
        return result;
        
    }
};