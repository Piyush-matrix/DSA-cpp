class Solution {
public:
    int largestInteger(int n, int s) {
        if(n==1 && s>9 || n==2 && s>18 || n==3 && s>27 || n==4 && s>36 || 
        n==5 && s>45) return -1;
        int num=0;
        for(int i=0;i<n;i++){
            int dig=min(9,s);
            num=num*10+dig;
            s-=dig;
        }
        return num;

    }
};