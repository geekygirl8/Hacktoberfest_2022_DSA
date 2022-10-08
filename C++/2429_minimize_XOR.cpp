//https://leetcode.com/contest/weekly-contest-313/problems/minimize-xor/

class Solution {
public:
    
    int count_bits(int n)
    {
        int ans=0;
        while(n>0)
        {
            //refer to notes
            n=n&(n-1);
            ans++;
        }
        return ans;
    }
    
    int minimizeXor(int num1, int num2) {
        int y = count_bits(num2);
        int x=0;
        
        for(int i=31;i>=0 && y>0;i--)
        {
            if((num1&(1<<i)) > 0)
            {
                x=x | (1<<i);
                y--;
            }
        }
        
        for(int i=0;i<=31 && y>0;i++)
        {
            if((num1 & (1<<i))==0)
            {
                x = x | (1<<i);
                y--;
            }
        }
        return x;
    }
};
