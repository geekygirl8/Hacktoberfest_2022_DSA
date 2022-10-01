// Name: Nikita
// Github id: geekygirl8

class Solution {
public:
    int dp[105];
    
    int solve(int pos,string &s){
        if(pos==s.size()){
            return 1;
        }
        int num = s[pos]-'0';
        int &ret=dp[pos];
        if(ret!=-1){
            return ret;
        }
        ret=0;
        if(num!=0 && num<=26){
            ret=ret+solve(pos+1,s);
        }
        if(num!=0 && pos+1<s.size()){
            num = num*10 + (s[pos+1]-'0');
            if(num!=0 && num<=26){
                ret=ret+solve(pos+2,s);
            }
        }
        return ret;
    }
    
    int numDecodings(string s) {
        memset(dp,-1,sizeof dp);
        return solve(0,s);
    }
};
