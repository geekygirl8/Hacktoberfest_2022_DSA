
// Name: SARAVANAN S
// Github id: sarav18302

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
  int n=nums.size(),l=0,r=0,i=0;
        while(i<n)
        {
            if(nums[r]==0)
            {
                r++;
                
            }
            else
            {
                swap(nums[l],nums[r]);
                l++;
               r++;
            }
            i++;
        }
        
    }
};
