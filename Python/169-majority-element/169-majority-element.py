class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        c = 0
        num = 0
        
        for i in nums:
            if c == 0:
                num = i
            if i == num:
                c += 1
            else:
                c -= 1
        return num