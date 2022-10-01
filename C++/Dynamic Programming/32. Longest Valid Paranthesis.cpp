// Name : Nikita
// Github id: geekygirl8

class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.length(), openL=0, closeL=0, openR=0, closeR=0, max=0;
        for(int i=0; i<n; i++) {
            if(s[i]=='(')
                openL++;
            else
                closeL++;
            
            if(openL==closeL)
                max = (max>openL+closeL) ? max : openL+closeL;
            else if (openL<closeL)
                openL=closeL=0;
            
            // From Reverse
            if(s[n-i-1]==')')
                closeR++;
            else 
                openR++;
            
            if(openR==closeR)
                max = (max>openR+closeR) ? max : openR+closeR;
            else if(closeR<openR)
                openR=closeR=0;
        }
        return max;  
    }
};
