// Name: SARAVANAN S
// Github id: sarav18302


class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size(),l=0,r=n-1;
        while(l<r)
        {
            swap(s[l],s[r]);
            l++;
            r--;
        }
            
    }
};
