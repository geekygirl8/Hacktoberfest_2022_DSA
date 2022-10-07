// Name: Satender Sharma
// Github id: thesatender

class Solution {
public:
    int trap(vector<int>& ht) {
        int i = 0, j = ht.size() - 1, leftMax = 0, rightMax = 0, ans = 0;
        while ( i <= j) {
            if (ht[i] <= ht[j]) {
                if (ht[i] < leftMax) ans += leftMax - ht[i];
                else leftMax = ht[i];
                i++;
            }
            else {
                if (ht[j] < rightMax) ans += rightMax - ht[j];
                else rightMax = ht[j];
                j--;
            }
        } 
        return ans;
    }
};
